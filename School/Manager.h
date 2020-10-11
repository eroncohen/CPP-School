#ifndef __MANAGER_H
#define __MANAGER_H

#include <iostream>
#include "Employee.h"
using namespace std;

class Manager : public Employee
{
public:
	Manager(const Employee& employee, int keys) throw (const string&);
	void setKeys(int keys) throw (const string&);
	int getKeys() const;
	// Abstract Methods
	virtual void printEmployeeData(ostream & os) const;

private:
	int keys;
};

#endif // __Manager_H