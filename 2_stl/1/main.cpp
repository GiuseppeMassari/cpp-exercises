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

	list<Person> persons;
	persons.push_back(p1);
	persons.push_back(p2);
	persons.push_back(p3);

	persons.emplace_back("Bruce Springsteen", "New York", Gender::MALE);
	persons.emplace_back("Stevie Nicks", "Phoenix", Gender::FEMALE);
	for (auto & p: persons) {
		std::cout << p.get_name() << " from " << p.get_city() << endl;
	}

	return 0;
}
