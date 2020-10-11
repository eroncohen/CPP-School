#include "Employee.h"

Employee::Employee(const Person & person, const string& officeMail, double salary) throw (const string&) : Person(person)
{
	setOfficeMail(officeMail);
	setSalary(salary);
}

void Employee::accept(IVisitor * visitor)
{
	visitor->visit(this);
}

void Employee::setOfficeMail(const string& officeMail) throw (const string&)
{
	if (officeMail != "")
		this->officeMail = officeMail;
	else
		throw "Email cannot be empty string";
}

const string& Employee::getOfficeMail() const
{
	return officeMail;
}

void Employee::setSalary(double salary) throw (const string&)
{
	if (0 <= salary)
		this->salary = salary;
	else
		throw "salary cannot be negative";
}

double Employee::getSalary() const
{
	return salary;
}

const Employee & Employee::operator+=(double raise)
{
	setSalary(salary + raise);
	return *this;
}

void Employee::toOs(ostream& os) const
{
	printEmployeeData(os);
}

//Design Pattern #2 : Visitor
void RaiseSalaryVisitor::visit(IVisitable * element)
{
	Employee* emp = (Employee*)element;
	(*emp) += money;
}
