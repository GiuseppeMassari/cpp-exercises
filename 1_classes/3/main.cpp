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

	if (p1 < p2) 
		std::cout << p1.get_name() << " <  " << p2.get_name() << endl;
	else
		std::cout << p2.get_name() << " <= " << p1.get_name() << endl;

	return 0;
}
