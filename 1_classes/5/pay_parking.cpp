#include <iostream>
#include "pay_parking.h"

using namespace std;

namespace excpp {

PaymentParking::PaymentParking(
	unsigned int nr_slots, float fee_per_hour):
	Parking(nr_slots), fph(fee_per_hour)
{
	slots.resize(nr_slots);	
	cout << "Parking fee is " << fph << " per hour" << endl;
}

int PaymentParking::park(string car_model)
{
	unsigned int i;
	for (i = 0; i < this->slots.size()-1; ++i) {
		if (slots[i].is_free) {
			slots[i].is_free = false;
			slots[i].car_model = car_model;
			slots[i].arrival_time = chrono::system_clock::now();
			cout << "Car " << car_model << " parked at slot " << i << endl;
			this->free_slots_count--; // less free slots now...
			return i; // return the slot number to find the car again
		}
	}

	return -1; // no slot available
}

void PaymentParking::leave(unsigned int slot_num)
{
	if (slot_num > this->slots.size()-1) {
		cout << "You're looking for a not existing parking slot!" << endl;
	}
	else {
		if (slots[slot_num].is_free) {
			cout << "Drive or drink! No car at slot " << slot_num << endl;
			return; // exit the function... no reason to go on...
		}
		
		// fast-forward mode: let's assume 1 second in the program = 1
		// hour in real life
		auto elapsed_time = chrono::duration_cast<chrono::seconds>(
			chrono::system_clock::now() - slots[slot_num].arrival_time
		);

		float to_pay = elapsed_time.count() * fph;
		cout << "Car " << slots[slot_num].car_model << " is leaving slot "
		     << slot_num << " to pay: " << to_pay << " €" << endl;

		slots[slot_num].is_free = true;
		slots[slot_num].car_model.clear();
		free_slots_count++; // one slot is back available
	}
}


} // namespace

