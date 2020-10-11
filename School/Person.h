#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
#pragma warning(disable : 4290)

using namespace std;

class Person
{
public:
	Person(const string& name, int age) throw (const string&);

	//added:
	virtual void toOs(ostream& os) {};
	virtual void printEmployeeData(ostream& os) const {}
	void setName(const string& str) throw (const string&);
	const string& getName() const;

	void setAge(int age) throw (const string&);
	int getAge() const;

	const Person& operator++(int);

protected:
	string name;
	int age;
};

#endif // __Person_H