#include <iostream>
#include <list>
#include <string>

#include "person.h"

using namespace std;
using namespace excpp; // for class Person


bool sort_by_city_name(
	Person const & first, Person const & second)
{
	return (first.get_city().compare(second.get_city()) < 0);
}

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
	std::cout << std::endl << "After sorting: " << std::endl;
	for (auto & p: persons) {
		std::cout << p.get_name() << " from " << p.get_city() << endl;
	}

	persons.sort(sort_by_city_name); // this will call the custom function above
	std::cout << std::endl << "After sorting (per city name): " << std::endl;
	for (auto & p: persons) {
		std::cout << p.get_name() << " from " << p.get_city() << endl;
	}

	return 0;
}
