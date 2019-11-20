#include <iostream>
#include <list>
#include <memory>

#include "person.h"

using namespace std;
using namespace excpp; // for class Person

int main(int argc, char **argv)
{
	list<shared_ptr<Person>> persons;

	persons.emplace_back(make_shared<Person>("Bruce Springsteen", "New York", Gender::MALE));
	persons.emplace_back(make_shared<Person>("Stevie Nicks", "Phoenix", Gender::FEMALE));
	persons.emplace_back(make_shared<Person>("Billy Corgan", "Chicago", Gender::MALE));
	persons.emplace_back(make_shared<Person>("Kurt Cobain", "Seattle", Gender::MALE));

	for (auto & p: persons) {
		std::cout << p->get_name() << " from " << p->get_city() << endl;
	}

	return 0;
}
