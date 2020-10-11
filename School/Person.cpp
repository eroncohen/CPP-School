#include "Person.h"

Person::Person(const string& name, int age) throw (const string&)
{
	setName(name);
	setAge(age);
}

void Person::setName(const string& name) throw (const string&)
{
	if (name != "")
		this->name = name;
	else
		throw "name cannot be empty string";
}

const string& Person::getName() const
{
	return name;
}

void Person::setAge(int newAge) throw (const string&)
{
	if (newAge > 0)
		age = newAge;
	else
		throw "age cannot be 0 or negative";
}

int Person::getAge() const
{
	return age;
}

const Person & Person::operator++(int)
{
	age++;
	return *this;
}


