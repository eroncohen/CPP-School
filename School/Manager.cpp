#include "Manager.h"

Manager::Manager(const Employee & employee, int keys) throw (const string&) :Employee(employee)
{
	setKeys(keys);
}

void Manager::setKeys(int keys) throw (const string&)
{
	if (keys >= 0)
		this->keys = keys;
	else
		throw "number of keys cannot be negative";
}

int Manager::getKeys() const
{
	return keys;
}

void Manager::printEmployeeData(ostream & os) const
{
	cout << "Manager Name: " << name.c_str() << "\nAge: " << age << "\nKeys number: " << keys << endl;
	cout << endl;
}
