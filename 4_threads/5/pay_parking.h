
#ifndef EXCPP_PAY_PARKING_H
#define EXCPP_PAY_PARKING_H

#include <chrono>
#include <condition_variable>
#include <mutex>
#include <vector>

#include "parking.h"

using namespace std;

namespace excpp {


class PaymentSlotInfo: public SlotInfo
{
public:
	chrono::system_clock::time_point arrival_time;

	// avoid contention while more than one car is trying to park in the
	// same slot
	mutex mx;
};


class PaymentParking: public Parking
{

public:

	PaymentParking(unsigned int nr_slots, float fee_per_hour);

	virtual ~PaymentParking() { }

	int park(string car_name);

	void leave(unsigned int slot_num);

private:

	// We need to change here w.r.t. previous exercises. The
	// PaymentSlotInfo includes a not-copyable object (mutex). When we
	// resize a vector, what happens is that a new contiguous memory space
	// is allocated, and the objects in the vector are copied from the
	// previous location to the new one. This cannot be done if the object
	// are not copyable.
	vector<shared_ptr<PaymentSlotInfo>> slots;

	// fee per hour
	float fph;

	// A mutex and a condition variable will be used for the blocking
	// behaviour of the park() function in the case the parking is full

	mutex mx_slots;

	condition_variable cv_slots;

};

} // namespace

#endif // EXCPP_PARKING_H
