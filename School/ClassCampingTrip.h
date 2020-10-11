
#ifndef __CLASSCAMPINGTRIP_H
#define __CLASSCAMPINGTRIP_H

#include <iostream>
#include "ClassTrip.h"
#include "CampingTrip.h"
using namespace std;

class ClassCampingTrip : public ClassTrip, public CampingTrip
{
public:
	ClassCampingTrip(const ClassTrip& classTrip, const CampingTrip& campingTrip, const string& printedShirt) throw (const string&);

	void setPrintedShirt(const string& printedShirt) throw (const string&);
	const string& getPrintedShirt() const;
private:
	string printedShirt;
};

#endif // __ClassCampingTrip_H
