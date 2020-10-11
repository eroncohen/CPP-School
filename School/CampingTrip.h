
#ifndef __CAMPINGTRIP_H
#define __CAMPINGTRIP_H

#include <iostream>
#include "Trip.h"
using namespace std;

class CampingTrip : virtual public Trip
{
public:
	CampingTrip(const Trip& trip, const std::string& campingLocation, int nightsNum) throw (const string&);

	void setCampingLocation(const std::string& campingLocation) throw (const string&);
	const string& getCampingLocation() const;
	void setNightsNum(int nightsNum) throw (const string&);
	int getNightsNum() const;
private:
	string campingLocation;
	int nightsNum;
};

#endif // __CampingTrip_H
