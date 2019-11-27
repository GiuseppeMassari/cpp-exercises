#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "person.h"

using namespace std;
using namespace excpp; // for class Person


int main(int argc, char **argv)
{
	map<string, shared_ptr<Person>> persons;

	persons.emplace("Shirley Manson", make_shared<Person>("Shirley Manson", "Edinburgh", Gender::FEMALE));
	persons.emplace("Billy Corgan", make_shared<Person>("Billy Corgan", "Chicago", Gender::MALE));
	persons.emplace("Bruce Springsteen", make_shared<Person>("Bruce Springsteen", "New York", Gender::MALE));
	persons.emplace("Kurt Cobain", make_shared<Person>("Kurt Cobain", "Seattle", Gender::MALE));
	persons.emplace("Stevie Nicks", make_shared<Person>("Stevie Nicks", "Phoenix", Gender::FEMALE));

	for (auto & p: persons) {
		std::cout << p.second->get_name() << " from " << p.second->get_city() << endl;
	}

	return 0;
}
