#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person
{
public:
	Student(const Person& person, int dadPhoneNumber, int momPhoneNumber, double avg) throw (const string&);
	Student(const Student& other) = delete;

	void setDadPhoneNumber(int dadNumber) throw (const string&);
	int getDadPhoneNumber() const;

	void setMomPhoneNumber(int momPhoneNumber) throw (const string&);
	int getMomPhoneNumber() const;

	void setAvg(double avg) throw (const string&);
	double getAvg() const;

	bool operator>(const Student& other) const;
	bool operator<(const Student& other) const;
	const Student& operator-=(double avg);
	friend ostream& operator<<(ostream& os, const Student& student);
private:
	int dadPhoneNumber;
	int momPhoneNumber;
	double avg;
};

#endif // __Student_H