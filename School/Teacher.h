#ifndef __TEACHER_H
#define __TEACHER_H

#include <iostream>
#include "Employee.h"
using namespace std;
class Class;
class Teacher : public Employee
{
public:
	Teacher(const Employee& employee, int markerNum, const string& book) throw (const string&);
	// Abstract Methods
	virtual void printEmployeeData(ostream & os) const;

	void setMarkerNum(int markerNum) throw (const string&);
	int getMarkerNum() const;

	void setBook(const string& book) throw (const string&);
	const string& getBook() const;

private:
	int markerNum;
	string book;
};

#endif // __Teacher_H