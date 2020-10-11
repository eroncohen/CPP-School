#include "ClassCampingTrip.h"
#include "ClassCampingTrip.h"

ClassCampingTrip::ClassCampingTrip(const ClassTrip& classTrip, const CampingTrip & campingTrip, const std::string& printedShirt) throw (const string&) : Trip(classTrip.getDestination(), classTrip.getBuses()), CampingTrip(campingTrip), ClassTrip(classTrip)
{
	setPrintedShirt(printedShirt);
}



void ClassCampingTrip::setPrintedShirt(const string& printedShirt) throw (const string&)
{
	if (printedShirt != "")
		this->printedShirt = printedShirt;
	else
		throw "printed shirt cannot be empty string";
}

const string& ClassCampingTrip::getPrintedShirt() const
{
	return printedShirt;
}
