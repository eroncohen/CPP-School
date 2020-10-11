#include "ClassTrip.h"

const Class* ClassTrip::getGoingClass() const
{
	return goingClass;
}


void ClassTrip::setGoingClass(Class * goingClass) throw (const string&)
{
	if (goingClass != nullptr)
		this->goingClass = goingClass;
	else
		throw "goingclass not added";
}

ClassTrip::ClassTrip(const Trip & trip,Class* goingClass) throw (const string&) : Trip(trip)
{
	setGoingClass(goingClass);
}
