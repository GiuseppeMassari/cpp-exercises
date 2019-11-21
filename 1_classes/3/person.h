#ifndef EXCPP_PERSON
#define EXCPP_PERSON

#include <string>

namespace excpp
{

enum class Gender {
	MALE,
	FEMALE
};

class Person
{
public:

	Person(std::string const & name,
	       std::string const & city,
	       Gender gender);

	Person(const Person &) = delete;
	Person & operator=(const Person &) = delete;

	bool operator<(const Person & other) const;
	bool operator==(const Person & other) const;
	bool operator>(const Person & other) const;

	virtual ~Person();

	std::string const & get_name() const;
	std::string const & get_city() const;
	Gender get_gender() const;

	void set_name(std::string const & name);
	void set_city(std::string const & city);
	void set_gender(Gender gender);

private:
	std::string name;
	std::string city;
	Gender gender;
};

} // namespace excpp

#endif // EXCPP_PERSON
