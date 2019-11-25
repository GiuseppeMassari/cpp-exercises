#include <iostream>
#include <list>
#include <mutex>
#include <thread>

#include "person.h"

using namespace std;
using namespace excpp; // for class Person

std::mutex mx;

void print_person_info(Person const & p) 
{
	std::lock_guard<std::mutex> lck(mx);
	std::cout << p.get_name() << " from " << p.get_city() << endl;
}

int main(int argc, char **argv)
{
	Person p1("Kurt Cobain", "Seattle", Gender::MALE);
	Person p2("Billy Corgan", "Chicago", Gender::MALE);
	Person p3("Shirley Manson", "Edinburgh", Gender::FEMALE);
	Person p4("Liam Gallagher", "Manchester", Gender::MALE);

	list<thread> workers; 
	workers.emplace_back(print_person_info, std::ref(p1));
	workers.emplace_back(print_person_info, std::ref(p2));
	workers.emplace_back(print_person_info, std::ref(p3));
	workers.emplace_back(print_person_info, std::ref(p4));

	for (auto & t: workers)
		t.join();

	return 0;
}
