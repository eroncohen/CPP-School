#ifndef __CLASSTRIP_H
#define __CLASSTRIP_H

#include <iostream>
#include "Trip.h"
using namespace std;

class Class;

class ClassTrip : virtual public Trip
{
public:
	ClassTrip(const Trip& trip,Class* goingClass) throw (const string&);

	void setGoingClass(Class* goingClass) throw (const string&);
	const Class* getGoingClass() const;
private:
	Class* goingClass;
};

#endif // __ClassTrip_H
