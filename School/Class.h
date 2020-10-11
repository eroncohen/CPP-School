#ifndef __CLASS_H
#define __CLASS_H

#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Trip.h"
#include "Linked_List.h"
#include <vector>

using namespace std;

//class Teacher;
class Class
{
public:
	//added const int
	const int MAX_STUDENTS = 30;
	Class(int classNum, int room, int maxClassTripsNum, Teacher* teacher) throw (const string&);
	Class(const Class& other) = delete;

	void addStudentToClass(Student* student) throw (const string&);
	void addTripToClass(Trip* trip) throw (const string&);
	Student* calcTopClass();

	void setClassNum(int classNum) throw (const string&);
	int getClassNum() const;
	void raiseAge();
	double getClassAvg() const;

	void setRoom(int room) throw (const string&);
	int getRoom() const;

	void setTeacher(Teacher* newTeacher) throw (const string&);
	const Teacher* getTeacher() const;
	int getStudentsNum() const;

	void setClassTrips(vector<Trip*> classTrips) throw (const string&);
	vector<Trip*> getClassTrips() const;
	//friend class Teacher;
	//friend ostream& operator<<(ostream& os, const Class& c);

private:
	int classNum;
	double classAvg; //calc
	int room;
	Teacher* teacher;
	Linked_List<Student*> students;
	int studentsNum;
	vector<Trip*> classTrips;
	int maxClassTripsNum;
	void calcClassAvg();
};
#endif // __Class_H