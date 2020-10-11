#include "CampingTrip.h"

CampingTrip::CampingTrip(const Trip & trip, const string& campingLocation, int nightsNum) throw (const string&) : Trip(trip)
{
	setCampingLocation(campingLocation);
	setNightsNum(nightsNum);
}


void CampingTrip::setCampingLocation(const string& campingLocation) throw (const string&)
{
	if (campingLocation != "")
		this->campingLocation = campingLocation;
	else
		throw "camping location cannot be empty string";
}

const string& CampingTrip::getCampingLocation() const
{
	return campingLocation;
}

void CampingTrip::setNightsNum(int nightsNum) throw (const string&)
{
	if (nightsNum > 0)
		this->nightsNum = nightsNum;
	else
		throw "nights number cannot be negative";
}

int CampingTrip::getNightsNum() const
{
	return nightsNum;
}

