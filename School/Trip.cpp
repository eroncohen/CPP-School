#include "Trip.h"

Trip::Trip(const string& destination, int buses) throw (const string&)
{
	setDestination(destination);
	setBuses(buses);
}

void Trip::setDestination(const string& destination) throw (const string&)
{
	if (destination != "")
		this->destination = destination;
	else
		throw "destination cannot be empty";
}
const string& Trip::getDestination() const
{
	return destination;
}


void Trip::setBuses(int busesNum) throw (const string&)
{
	if (busesNum >= 0)
		buses = busesNum;
	else
		throw "bussees number cannot be negative";
}

int Trip::getBuses() const
{
	return buses;
}
