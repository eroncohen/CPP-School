
#ifndef __TRIP_H
#define __TRIP_H

#include <iostream>
using namespace std;

class Trip
{
public:
	Trip(const string& destination, int buses) throw (const string&);

	void setDestination(const string& destination) throw (const string&);
	const string& getDestination() const;

	void setBuses(int busesNum) throw (const string&);
	int getBuses() const;
private:
	string destination;
	int buses;
};

#endif // __Trip_H