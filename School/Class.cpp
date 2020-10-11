#include "Class.h"

Class::Class(int classNum, int room, int maxClassTripsNum, Teacher* teacher) throw (const string&)
{
	setTeacher(teacher);
	setClassNum(classNum);
	setRoom(room);
	this->maxClassTripsNum = maxClassTripsNum;
}

void Class::addStudentToClass(Student* student) throw (const string&)
{
	if (studentsNum < MAX_STUDENTS)
	{
		studentsNum++;
		students.addToEnd(student);
		calcClassAvg();
	}
	else
		throw "student not added because class is full";
}

void Class::addTripToClass(Trip* trip) throw (const string&)
{
	if (classTrips.size() < maxClassTripsNum && trip != nullptr)
		classTrips.push_back(trip);
	else
		throw "class trip not added";
}
void Class::raiseAge()
{
	Node<Student*> head = *students.getHead();
	Student* student = head.getVal();
	(*student)++;
	while (head.getNext() != nullptr)
	{
		head = *head.getNext();
		student = head.getVal();
		(*student)++;
	}
}

Student* Class::calcTopClass()
{
	if (studentsNum > 0)
	{
		Node<Student*> head = *students.getHead();
		Student* maxStudent = head.getVal();
		while (head.getNext() != nullptr)
		{
			head = *head.getNext();
			if (*maxStudent < *head.getVal())
				maxStudent = head.getVal();
		}
		return maxStudent;
	}
	return NULL;
}

void Class::calcClassAvg()
{
	if (studentsNum > 0)
	{
		double newStudentAvg = students.getTail()->getVal()->getAvg();
		double oldSumOfAllScores = classAvg * (studentsNum - 1);
		double newSumOfAllScores = oldSumOfAllScores + newStudentAvg;
		classAvg = newSumOfAllScores / studentsNum;
	}
}

void Class::setClassNum(int classNum) throw (const string&)
{
	if (classNum > 0)
		this->classNum = classNum;
	else
		throw "class number cannot be negative";
}

int Class::getClassNum() const
{
	return classNum;
}

double Class::getClassAvg() const
{
	return classAvg;
}

void Class::setRoom(int room) throw (const string&)
{
	if (room > 0)
		this->room = room;
	else
		throw "room number cannot be negative";
}

int Class::getRoom() const
{
	return room;
}

void Class::setTeacher(Teacher* newTeacher) throw (const string&)
{
	if (teacher != newTeacher)
	{
		if (newTeacher != nullptr)
			teacher = newTeacher;
	}
	else
		throw "teacher not added";
}

const Teacher * Class::getTeacher() const
{
	return teacher;
}

int Class::getStudentsNum() const
{
	return studentsNum;
}

void Class::setClassTrips(vector<Trip*> classTrips) throw (const string&)
{
	if (classTrips.size() <= maxClassTripsNum)
		this->classTrips = classTrips;
	else
		throw "class trips is too big";
}

vector<Trip*> Class::getClassTrips() const
{
	return classTrips;
}
