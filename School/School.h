#ifndef __SCHOOL_H
#define __SCHOOL_H

#include <iostream>
#include "Grade.h"
#include "Class.h"
#include "Manager.h"
#include "Student.h"
#include "ClassCampingTrip.h"
#include <vector>
using namespace std;

class School
{
public:
	const int MAX_GRADES = 12;
	static School& getInstance(const string& name, const string& address, const Manager& schoolManager) throw (const string&); // for SINGLETONE
	void endYear();
	void addGrade(Grade* newGrade) throw (const string&);
	void addEmployee(Employee* newEmployee) throw (const string&);
	double getGradesAvg();
	void setAnnualTrip(Grade* grade, CampingTrip* annualTrip) throw (const string&);
	void raiseAge();
	void setName(const string& name) throw (const string&);
	const string& getName() const;
	void printAllEmployees();

	void setAddress(const string& address) throw (const string&);
	const string& getAddress() const;

	void setSchoolManager(const Manager& schoolManager) throw (const string&);
	const Manager getSchoolManager() const;

	vector<Grade*> getGrades() const;

	vector<Employee*> getEmployees() const;

	//DesignPattern #2 - visitor
	void School::accept(IVisitor* visitor);

private:
	static School theSchool;  // for SINGLETONE
	School(const string& name, const string& address, const Manager& schoolManager) throw (const string&);

	string name;
	string address;
	Manager schoolManager;
	vector<Grade*> grades;
	vector<Employee*> employees;
};

#endif // __School_H




