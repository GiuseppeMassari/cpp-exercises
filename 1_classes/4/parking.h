
#ifndef EXCPP_PARKING_H
#define EXCPP_PARKING_H

#include <string>
#include <vector>

using namespace std;

namespace excpp {


class SlotInfo
{
public:
	bool is_free = true;
	string car_model;
};


class Parking
{

public:
	Parking(unsigned int nr_slots);

	virtual ~Parking() { }

	int park(string car_name);

	void leave(unsigned int slot_num);

	unsigned int get_nr_free_slots() const;

private:

	vector<SlotInfo> slots;

	unsigned int free_slots_count;

};

} // namespace

#endif // EXCPP_PARKING_H
