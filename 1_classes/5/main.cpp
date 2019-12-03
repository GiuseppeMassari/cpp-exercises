#include <iostream>
#include <thread>

#include "pay_parking.h"

using namespace std;
using namespace excpp; // for class Parking


int main(int argc, char **argv)
{
	PaymentParking p1(15, 0.50);	

	auto sn_giulia = p1.park("Alfa Giulia");
	auto sn_yaris = p1.park("Toyota Yaris");
	auto sn_golf = p1.park("Volkswagen Golf");
	cout << "Nr. available slots: " << p1.get_nr_free_slots() << endl;

	// sleep 3 seconds to simulate the car leaves after 3 hours
	this_thread::sleep_for(chrono::seconds(3));
	p1.leave(sn_golf);
	cout << "Nr. available slots: " << p1.get_nr_free_slots() << endl;

	p1.leave(50);

	return 0;
}
