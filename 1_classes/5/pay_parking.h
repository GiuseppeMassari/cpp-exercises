
#ifndef EXCPP_PAY_PARKING_H
#define EXCPP_PAY_PARKING_H

#include <chrono>
#include <vector>

#include "parking.h"

using namespace std;

namespace excpp {


class PaymentSlotInfo: public SlotInfo
{
public:
	// arrival time
	chrono::system_clock::time_point arrival_time;
};


class PaymentParking: public Parking
{

public:

	PaymentParking(unsigned int nr_slots, float fee_per_hour);

	virtual ~PaymentParking() { }

	int park(string car_name);

	void leave(unsigned int slot_num);

private:

	vector<PaymentSlotInfo> slots;

	float fph;

};

} // namespace

#endif // EXCPP_PARKING_H
