#include "Teacher.h"

Teacher::Teacher(const Employee & employee, int markerNum, const string& book) throw (const string&) : Employee(employee)
{
	setMarkerNum(markerNum);
	setBook(book);
	//setTeachingClass(teachingClass);
}

void Teacher::printEmployeeData(ostream & os) const
{
	cout << "Teacher name: " << name.c_str() << "\nAge: " << age << "  \nMarkers num: " << markerNum << endl;
	cout << endl;
}

void Teacher::setMarkerNum(int markerNum) throw (const string&)
{
	if (markerNum >= 0)
		this->markerNum = markerNum;
	else
		throw "marker number cannot be negative";
}

int Teacher::getMarkerNum() const
{
	return markerNum;
}

void Teacher::setBook(const string& book) throw (const string&)
{
	if (book != "")
		this->book = book;
	else
		throw "book cannot be empty string";
}

const string& Teacher::getBook() const
{
	return this->book;
}
