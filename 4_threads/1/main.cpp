#include <iostream>
#include <list>
#include <thread>

#include "person.h"

using namespace std;
using namespace excpp; // for class Person

void print_person_info(Person const & p) 
{
	std::cout << p.get_name() << " from " << p.get_city() << endl;
}

int main(int argc, char **argv)
{
	Person p1("Kurt Cobain", "Seattle", Gender::MALE);
	Person p2("Billy Corgan", "Chicago", Gender::MALE);
	Person p3("Shirley Manson", "Edinburgh", Gender::FEMALE);
	Person p4("Liam Gallagher", "Manchester", Gender::MALE);

	// std::ref() function is used to pass a reference to the object.
	// This is required since thread(...) pass the function arguments
	// per copy by default.
	thread t1(print_person_info, std::ref(p1));
	thread t2(print_person_info, std::ref(p2));
	thread t3(print_person_info, std::ref(p3));
	thread t4(print_person_info, std::ref(p4));

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}
