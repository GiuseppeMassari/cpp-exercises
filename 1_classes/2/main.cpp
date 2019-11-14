#include <iostream>
#include <list>

#include "person.h"

using namespace std;
using namespace excpp; // for class Person

int main(int argc, char **argv)
{
	Person p1("Kurt Cobain", "Seattle", Gender::MALE);
	Person p2("Billy Corgan", "Chicago", Gender::MALE);
	Person p3("Shirley Manson", "Edinburgh", Gender::FEMALE);

	std::cout << p1.get_name() << " from " << p1.get_city() << endl;
	std::cout << p2.get_name() << " from " << p2.get_city() << endl;
	std::cout << p3.get_name() << " from " << p3.get_city() << endl;

	return 0;
}
