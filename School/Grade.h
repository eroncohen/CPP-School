#ifndef __GRADE_H
#define __GRADE_H

#include <iostream>
#include "Class.h"
#include "CampingTrip.h"
#include <vector>
using namespace std;
const int FIRST_GRADE = 1;
const int LAST_GRADE = 12;

class Grade
{
public:
	Grade(int gradeNum, int maxClassesNum) throw (const string&);
	Grade(const Grade& other) = delete;


	void addStudentToGrade(Student* student, int whichClass) throw (const string&);
	void addTripToGrade(Trip* trip) throw (const string&);
	void addClassToGrade(Class* theClass) throw (const string&);
	void calcGradeAvg();
	void printTopStudents();
	void raiseAge();
	void setGradeNum(int gradeNum) throw (const string&);
	int getGradeNum() const;
	double getGradeAvg() const;

	void setClasses(vector<Class*> classes) throw (const string&);
	vector<Class*> getClasses() const;

	int getClassesNum() const;

	void setAnnualTrip(CampingTrip* annualTrip) throw (const string&);
	const CampingTrip* getAnnualTrip() const;

	const Grade& operator++(int);
private:
	int gradeNum;
	double gradeAvg;
	vector<Class*> classes;
	int classesNum;
	int maxClassesNum;
	CampingTrip* annualTrip;
};

#endif // __Grade_H