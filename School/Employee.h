#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include "Person.h"
#include "Visitor.h"
using namespace std;

class Employee : public Person, public IVisitable
{
public:
	Employee(const Person& person, const string& officeMail, double salary) throw (const string&);
	virtual void accept(IVisitor* visitor);
	void setOfficeMail(const string& mail) throw (const string&);
	const string& getOfficeMail() const;

	void setSalary(double salary) throw (const string&);
	double getSalary() const;

	const Employee& operator+=(double raise);

	// Abstract Methods
	virtual void printEmployeeData(ostream& os) const {};
	// Design Pattern #3 --> Template Method
	void toOs(ostream& os) const;

protected:
	string officeMail;
	double salary;
};

#endif // __Employee_H