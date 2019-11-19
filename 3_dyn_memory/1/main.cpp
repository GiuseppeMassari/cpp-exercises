#include <iostream>
#include <memory>

#include "person.h"

using namespace std;
using namespace excpp; // for class Person

int main(int argc, char **argv)
{
	Person * p1 = new Person("Kurt Cobain", "Seattle", Gender::MALE);
	std::shared_ptr<Person> p2 = std::make_shared<Person>("Billy Corgan", "Chicago", Gender::MALE);
	std::unique_ptr<Person> p3 = std::make_unique<Person>("Shirley Manson", "Edinburgh", Gender::FEMALE);

	std::cout << p1->get_name() << " from " << p1->get_city() << endl;
	std::cout << p2->get_name() << " from " << p2->get_city() << endl;
	std::cout << p3->get_name() << " from " << p3->get_city() << endl;

	delete p1; // we need to explicitly deallocate p1

	return 0;
}
