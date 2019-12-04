#include <iostream>
#include "pay_parking.h"

using namespace std;

namespace excpp {

PaymentParking::PaymentParking(
	unsigned int nr_slots, float fee_per_hour):
	Parking(nr_slots), fph(fee_per_hour)
{
	cout << "Parking includes " << nr_slots << " slots" << endl;
	for (unsigned int j = 0; j < nr_slots; ++j) {
		slots.emplace_back(make_shared<PaymentSlotInfo>());
	}
	cout << "Parking fee is " << fph << " per hour" << endl << endl;
}

int PaymentParking::park(string car_model)
{
	// Lock the mutex protecting the count of free slots
	unique_lock<mutex> lck(mx_slots);
	while (free_slots_count == 0) {
		cout << car_model << ": parking is full. Waiting..." << endl;
		cv_slots.wait(lck);
	}

	this->free_slots_count--; // less free slots now...

	// We can already release the lock, since we are protecting only the
	// count of free slots. This way we maximize the parallelism.
	lck.unlock();

	unsigned int i;
	for (i = 0; i < this->slots.size(); ++i) {

		// Avoid the cars will collide trying to park in the same slot! :P
		unique_lock<mutex> slot_lck(slots[i]->mx);

		// Beware... in 'slots' we stored pointers to object now, so we
		// need to access data members with '->'
		if (slots[i]->is_free) {
			slots[i]->is_free = false;
			slots[i]->car_model = car_model;
			slots[i]->arrival_time = chrono::system_clock::now();
			cout << car_model << ": parked at slot " << i << endl;
			return i; // return the slot number to find the car again
		}
	}

	return -1; // no slot available
}

void PaymentParking::leave(unsigned int slot_num)
{
	if (slot_num > this->slots.size()-1) {
		cout << "You're looking for a not existing parking slot! :" << slot_num << endl;
	}
	else {

		// If a car want to park here, first it has to wait for me to
		// leave! ;)
		unique_lock<mutex> slot_lck(slots[slot_num]->mx);

		if (slots[slot_num]->is_free) {
			cout << "Drive or drink! No car at slot " << slot_num << endl;
			return; // exit the function... no reason to go on...
		}

		// fast-forward mode: let's assume 1 second in the program = 1
		// hour in real life
		auto elapsed_time = chrono::duration_cast<chrono::seconds>(
			chrono::system_clock::now() - slots[slot_num]->arrival_time
		);

		float to_pay = elapsed_time.count() * fph;
		cout << "Car " << slots[slot_num]->car_model << " is leaving slot "
		     << slot_num << " to pay: " << to_pay << " €" << endl;

		slots[slot_num]->is_free = true;
		slots[slot_num]->car_model.clear();

		// manage the "parking is full" case
		unique_lock<mutex> lck(mx_slots);
		free_slots_count++;    // one slot is back available
		cv_slots.notify_one(); // if the parking was full, now notify one car
	}
}


} // namespace

