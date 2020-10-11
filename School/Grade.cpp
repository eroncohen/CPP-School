#include "Grade.h"

Grade::Grade(int gradeNum, int maxClassesNum) throw (const string&)
{
	classesNum = 0;
	setGradeNum(gradeNum);
	this->maxClassesNum = maxClassesNum;
}

void Grade::addStudentToGrade(Student* student, int whichClass) throw (const string&)
{
	for (int i = 0; i < classesNum; i++)
	{
		if (classes[i]->getClassNum() == whichClass)
			classes[i]->addStudentToClass(student);
	}
}

void Grade::addTripToGrade(Trip* trip) throw (const string&)
{
	for (int i = 0; i < classesNum; i++)
		classes[i]->addTripToClass(trip);
}

void Grade::addClassToGrade(Class* theClass) throw (const string&)
{
	if (classes.size() < maxClassesNum)
		classes.push_back(theClass);
	else
		throw "grade is full";
}

void Grade::calcGradeAvg()
{
	double sumAvg = 0, numOfStudents = 0;
	vector<Class*>::iterator itr = classes.begin();
	vector<Class*>::iterator itrEnd = classes.end();
	for (; itr!=itrEnd; ++itr)
	{
		sumAvg += (*itr)->getClassAvg() * (*itr)->getStudentsNum();
		numOfStudents += (*itr)->getStudentsNum();
	}
	gradeAvg = sumAvg / numOfStudents;
}

void Grade::printTopStudents()
{
	cout << endl << "Excelents in grade " << gradeNum << " are: " << "( grade average " << gradeAvg << " )" << endl;
	vector<Class*>::iterator itr = classes.begin();
	vector<Class*>::iterator itrEnd = classes.end();
	for (; itr != itrEnd; ++itr)
	{
		cout << "class number " << (*itr)->getClassNum() << " --> " << *((*itr)->calcTopClass()) << endl;
	}
}
void Grade::raiseAge()
{
	vector<Class*>::iterator itr = classes.begin();
	vector<Class*>::iterator itrEnd = classes.end();
	for (; itr != itrEnd; ++itr)
	{
		(**itr).raiseAge();
	}
}
void Grade::setGradeNum(int gradeNum) throw (const string&)
{
	if (gradeNum >= FIRST_GRADE && gradeNum <= LAST_GRADE)
		this->gradeNum = gradeNum;
	else
		throw "grade number invalid";
}

int Grade::getGradeNum() const
{
	return gradeNum;
}

double Grade::getGradeAvg() const
{
	return gradeAvg;
}

void Grade::setClasses(vector<Class*> classes) throw (const string&)
{
	if (classes.size() <= maxClassesNum)
		this->classes = classes;
	else
		throw "classes number is too big";
}

vector<Class*> Grade::getClasses() const
{
	return classes;
}

int Grade::getClassesNum() const
{
	return classesNum;
}

void Grade::setAnnualTrip(CampingTrip * annualTrip) throw (const string&)
{
	addTripToGrade(annualTrip);
	this->annualTrip = annualTrip;
}

const CampingTrip * Grade::getAnnualTrip() const
{
	return annualTrip;
}

const Grade& Grade::operator++(int)
{
	if (gradeNum >= FIRST_GRADE && gradeNum <= LAST_GRADE)
	{
		gradeNum++;
	}
	return *this;
}
