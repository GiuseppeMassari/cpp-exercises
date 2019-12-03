#include <iostream>
#include "parking.h"

using namespace std;

namespace excpp {

Parking::Parking(unsigned int nr_slots)
{
	free_slots_count = nr_slots;
	slots.resize(nr_slots); // vector must include 'nr_slots' parking spaces
	cout << "New parking area with " << nr_slots << " slots" << endl;
}

int Parking::park(string car_model)
{
	unsigned int i;
	for (i = 0; i < this->slots.size()-1; ++i) {
		if (slots[i].is_free) {
			slots[i].is_free = false;
			slots[i].car_model = car_model;
			cout << "Car " << car_model << " parked at slot " << i << endl;
			this->free_slots_count--; // less free slots now...
			return i; // return the slot number to find the car again
		}
	}

	return -1; // no slot available
}

void Parking::leave(unsigned int slot_num)
{
	if (slot_num > this->slots.size()-1) {
		cout << "You're looking for a not existing parking slot!" << endl;
	}
	else {
		if (slots[slot_num].is_free) {
			cout << "Drive or drink! No car at slot " << slot_num << endl;
			return; // exit the function... no reason to go on...
		}
		
		cout << "Car " << slots[slot_num].car_model << " is leaving slot "
		     << slot_num << endl;
		slots[slot_num].is_free = true;
		slots[slot_num].car_model.clear();
		free_slots_count++; // one slot is back available
	}
}

unsigned int Parking::get_nr_free_slots() const
{
	return free_slots_count;
}

} // namespace

