#include "person.h"

namespace excpp
{

Person::Person(std::string const & n,
               std::string const & c,
               Gender g):
	name(n), city(c), gender(g)
{
}

Person::~Person()
{
}

std::string const & Person::get_name() const
{
	return this->name;
}

std::string const & Person::get_city() const
{
	return this->city;
}

Gender Person::get_gender() const
{
	return this->gender;
}

void Person::set_name(std::string const & name)
{
	this->name = name;
}
void Person::set_city(std::string const & city)
{
	this->city = city;
}

void Person::set_gender(Gender gender)
{
	this->gender = gender;
}

bool Person::operator<(const Person & other) 
{
	// let's exploit the compare() member function of the class std::string
	return (this->name.compare(other.get_name()) < 0);	
}


} // namespace excpp
