#include <iostream>
#include <list>
#include <thread>

#include "pay_parking.h"

using namespace std;
using namespace excpp; // for class Parking


void park_the_car(PaymentParking & parking, string car_name, unsigned int nr_hours)
{
	// Let's park the car
	int slot_number = parking.park(car_name);

	// Let's park the car for a while. Again, we speed-up the simulation
	// (1s = 1h)
	this_thread::sleep_for(chrono::seconds(nr_hours));
	
	// This should never happen
	if (slot_number < 0) {
		cerr << " No valid slot for " << car_name << ". Bad things happened here!" << endl;
		return;
	}

	// Ready to go away...
	parking.leave(slot_number);
}


int main(int argc, char **argv)
{
	// very few slots just for testing the full parking condition
	PaymentParking p1(3, 0.50);

	// let's keep the cars threads into a list
	list<thread> cars;

	// we ned to specify that we are passing a reference to the
	// PaymentParking object, by using the function ref()
	cars.emplace_back(park_the_car, ref(p1), "Fiat 500", 3);
	cars.emplace_back(park_the_car, ref(p1), "Alfa Giulia", 6);
	cars.emplace_back(park_the_car, ref(p1), "Toyota Aygo", 2);
	cars.emplace_back(park_the_car, ref(p1), "Citroen C3", 4);
	cars.emplace_back(park_the_car, ref(p1), "Peugeout 206", 3);

	// join all the threads for a clean termination of the program
	for (auto & car_thread: cars) {
		car_thread.join();
	}

	return 0;
}
