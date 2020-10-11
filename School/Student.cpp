#include "Student.h"

Student::Student(const Person & person, int dadPhoneNumber, int momPhoneNumber, double avg) throw (const string&) : Person(person)
{
	setDadPhoneNumber(dadPhoneNumber);
	setMomPhoneNumber(momPhoneNumber);
	setAvg(avg);
}

void Student::setDadPhoneNumber(int dadPhoneNumber) throw (const string&)
{
	if (dadPhoneNumber > 999 && dadPhoneNumber <= 9999)
		this->dadPhoneNumber = dadPhoneNumber;
	else
		throw "phone number must be 4 numbers";
}

int Student::getDadPhoneNumber() const
{
	return dadPhoneNumber;
}

void Student::setMomPhoneNumber(int momPhoneNumber) throw (const string&)
{

	if (momPhoneNumber > 999 && momPhoneNumber <= 9999)
		this->momPhoneNumber = momPhoneNumber;
	else
		throw "phone number must be 4 numbers";
}

int Student::getMomPhoneNumber() const
{
	return momPhoneNumber;
}

void Student::setAvg(double avg) throw (const string&)
{
	if (avg >= 0)
		this->avg = avg;
	else
		throw "average cannot be negative";
}

double Student::getAvg() const
{
	return avg;
}

bool Student::operator>(const Student & other) const
{
	return this->avg > other.avg;
}

bool Student::operator<(const Student & other) const
{
	return other > *this;
}

const Student & Student::operator-=(double avgGap)
{
	avg -= avgGap;
	return *this;
}
ostream& operator<<(ostream& os, const Student& student)
{
	os << "Name: " << student.getName().c_str() << " Average: " << student.getAvg();
	return os;
}
