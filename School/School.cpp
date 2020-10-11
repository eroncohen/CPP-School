#include "School.h"
#pragma warning(disable:4996)

School& School::getInstance(const string& name, const string& address, const Manager& schoolManager) throw (const string&)
{
	static School theSchool(name, address, schoolManager);
	return theSchool;
}

School::School(const string& name, const string& address, const Manager& newSchoolManager) throw (const string&) : schoolManager(newSchoolManager)
{
	setName(name);
	setAddress(address);
}

void School::endYear()
{
	raiseAge();
	vector<Grade*>::iterator itr = grades.begin();
	vector<Grade*>::iterator itrEnd = grades.end();
	int temp;
	for (; itr != itrEnd; ++itr)
	{
		(*itr)->printTopStudents();
		(*(*itr))++;
		temp = (*itr)->getGradeNum();
	}
	if (temp > MAX_GRADES)
		grades.pop_back();
}
void School::raiseAge()
{
	//students
	vector<Grade*>::iterator itr = grades.begin();
	vector<Grade*>::iterator itrEnd = grades.end();
	for (; itr != itrEnd; ++itr)
	{
		(**itr).raiseAge();
	}
	//employees
	vector<Employee*>::iterator itrEmp = employees.begin();
	vector<Employee*>::iterator itrEndEmp = employees.end();
	for (; itrEmp != itrEndEmp; ++itrEmp)
	{
		(**itrEmp)++;
	}
}

void School::setAnnualTrip(Grade* grade, CampingTrip * annualTrip) throw (const string&)
{
	grade->setAnnualTrip(annualTrip);
}

void School::addGrade(Grade* newGrade) throw (const string&)
{
	if (newGrade != nullptr && grades.size() < MAX_GRADES)
	{
		newGrade->calcGradeAvg();
		grades.push_back(newGrade);
	}
	else
		throw "grade not added";
}

void School::addEmployee(Employee* newEmployee) throw (const string&)
{
	if (newEmployee != nullptr)
		employees.push_back(newEmployee);
	else
		throw "employee not added";
}

double School::getGradesAvg()
{
	double sum = 0;
	vector<Grade*>::iterator itr = grades.begin();
	vector<Grade*>::iterator itrEnd = grades.end();
	for (; itr != itrEnd; ++itr)
	{
		if (*itr != NULL)
			sum += (*itr)->getGradeAvg();
	}
	return sum / grades.size();
}


void School::setName(const string& name) throw (const string&)
{
	if (name != "")
		this->name = name;
	else
		throw "name cannot be empty string";
}

const string& School::getName() const
{
	return name;
}

void School::printAllEmployees()
{
	//employees
	vector<Employee*>::iterator itrEmp = employees.begin();
	vector<Employee*>::iterator itrEndEmp = employees.end();
	cout << "The employees in school " << name.c_str() << " are: " << endl;
	for (; itrEmp != itrEndEmp; ++itrEmp)
	{
		(**itrEmp).toOs(cout);
	}
	cout << "-----------------------" << endl;
}

void School::setAddress(const string& address) throw (const string&)
{
	if (address != "")
		this->address = address;
	else
		throw "address cannot be empty string";
}

const string& School::getAddress() const
{
	return address;
}

void School::setSchoolManager(const Manager& schoolManager) throw (const string&)
{
	if (schoolManager.getName() != "")
		this->schoolManager = schoolManager;
	else
		throw "school manager not added";
}

const Manager School::getSchoolManager() const
{
	return schoolManager;
}


vector<Grade*> School::getGrades() const
{
	return grades;
}


vector<Employee*> School::getEmployees() const
{
	return employees;
}

void School::accept(IVisitor* visitor)
{
	vector<Employee*>::iterator itr = employees.begin();
	vector<Employee*>::iterator itrEnd = employees.end();
	for (; itr != itrEnd; ++itr)
		(*itr)->accept(visitor);
}