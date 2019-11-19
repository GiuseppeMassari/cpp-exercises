#include <iostream>
#include <list>

#include "person.h"

using namespace std;
using namespace excpp; // for class Person

int main(int argc, char **argv)
{
	list<Person> persons;
	persons.emplace_back("Shirley Manson", "Edinburgh", Gender::FEMALE);
	persons.emplace_back("Billy Corgan", "Chicago", Gender::MALE);
	persons.emplace_back("Bruce Springsteen", "New York", Gender::MALE);
	persons.emplace_back("Kurt Cobain", "Seattle", Gender::MALE);
	persons.emplace_back("Stevie Nicks", "Phoenix", Gender::FEMALE);
	for (auto & p: persons) {
		std::cout << p.get_name() << " from " << p.get_city() << endl;
	}

	persons.sort(); // this will use the '<' operator by defaul
	std::cout << "After sorting: " << std::endl;
	for (auto & p: persons) {
		std::cout << p.get_name() << " from " << p.get_city() << endl;
	}

	return 0;
}
