#include <iostream>
#include "School.h"
#include "Linked_List.h"

using namespace std;

void main()
{
	//Linked_List<int> l1;
	//l1.addToEnd(1);
	//l1.printList();
	//l1.removeItem(1);
	//l1.printList();
	Person orit("Orit", 54);
	Employee oritEmployee(orit, "Jabotinski 20, Giv'atayim", 12000.5);
	Manager oritManager(oritEmployee, 30);

	//Singelton - DesignPattern #1
	School& rabinSchool = School::getInstance("Rabin", "SOKOLOV69", oritManager);
	rabinSchool.addEmployee(&oritManager);

	//Teachers
	Person keren("Keren", 18);//1
	Employee kerenEmployee(keren, "TLV", 30000);
	Teacher kerenTeacher(kerenEmployee, 1, "C");
	rabinSchool.addEmployee(&kerenTeacher);
	Person micha("Micha", 24);//2
	Employee michaEmployee(micha, "Jerusalem", 6500.3);
	Teacher michaTeacher(michaEmployee, 2, "Python");
	rabinSchool.addEmployee(&michaTeacher);
	Person david("David", 40);//3
	Employee davidEmployee(david, "Haifa", 8000);
	Teacher davidTeacher(davidEmployee, 3, "Java");
	rabinSchool.addEmployee(&davidTeacher);
	Person itzik("Itzik", 70);//4
	Employee itzikEmployee(itzik, "ROSH_HA_EIN", 50);
	Teacher itzikTeacher(itzikEmployee, 4, "Liteture");
	rabinSchool.addEmployee(&itzikTeacher);
	Person eyal("Eyal", 37);//5
	Employee eyalEmployee(eyal, "SomeWhere", 9000);
	Teacher eyalTeacher(eyalEmployee, 5, "Linux");
	rabinSchool.addEmployee(&eyalTeacher);
	Person alex("Alex", 66);//6
	Employee alexEmployee(alex, "Netania", 5555.5);
	Teacher alexTeacher(alexEmployee, 6, "Scala");
	rabinSchool.addEmployee(&alexTeacher);
	//end of creation theachers

	//Students:
	Person mor("Mor", 7);
	Student morStudent(mor, 2654, 3978, 70);
	Person amit("Amit", 7);
	Student amitStudent(amit, 3333, 2222, 90);
	Person eron("Eron", 7);
	Student eronStudent(eron, 2000, 1111, 50);
	Person jojo("Jojo", 7);
	Student jojoStudent(jojo, 5000, 7000, 60);
	Person gogo("Gogo", 11);
	Student gogoStudent(gogo, 4000, 7777, 30);
	Person momo("Momo", 11);
	Student momoStudent(momo, 1234, 8888, 90);
	Person yoyo("Yoyo", 11);
	Student yoyoStudent(yoyo, 6000, 2121, 80);
	Person dodo("Dodo", 12);
	Student dodoStudent(dodo, 3000, 3333, 40);
	Person zozo("Zozo", 12);
	Student zozoStudent(zozo, 2654, 3978, 70);
	Person toto("Toto", 12);
	Student totoStudent(toto, 7333, 7222, 90);
	Person guy("Guy", 13);
	Student guyStudent(guy, 2450, 1231, 70);
	Person ben("Ben", 13);
	Student benStudent(ben, 5670, 7790, 20);
	Person roy("Roy", 13);
	Student royStudent(roy, 4340, 5777, 30);
	Person lior("Lior", 13);
	Student liorStudent(lior, 1674, 9888, 50);
	Person yossi("Yossi", 13);
	Student yossiStudent(yossi, 8900, 8121, 80);
	Person koko("Koko", 13);
	Student kokoStudent(koko, 7800, 9333, 95);
	//end of students creation

	//grades
	Grade grade1(1, 4);
	Grade grade2(5, 4);
	Grade grade3(6, 4);
	Grade grade4(7, 4);
	//end of grades creation

	//classes
	Class a1(1, 100, 5, &kerenTeacher);
	Class a2(2, 101, 5, &michaTeacher);
	Class h1(1, 201, 5, &davidTeacher);
	Class h2(2, 202, 5, &itzikTeacher);
	Class v1(1, 301, 5, &eyalTeacher);
	Class z1(1, 401, 5, &alexTeacher);
	//end of classes creation

	//addStudents and grades to school
	a1.addStudentToClass(&morStudent);
	a1.addStudentToClass(&amitStudent);
	a2.addStudentToClass(&eronStudent);
	a2.addStudentToClass(&jojoStudent);
	h1.addStudentToClass(&gogoStudent);
	h1.addStudentToClass(&momoStudent);
	h2.addStudentToClass(&yoyoStudent);
	v1.addStudentToClass(&dodoStudent);
	v1.addStudentToClass(&zozoStudent);
	v1.addStudentToClass(&totoStudent);
	z1.addStudentToClass(&guyStudent);
	z1.addStudentToClass(&benStudent);
	z1.addStudentToClass(&royStudent);
	z1.addStudentToClass(&liorStudent);
	z1.addStudentToClass(&yossiStudent);
	z1.addStudentToClass(&kokoStudent);

	grade1.addClassToGrade(&a1);
	grade1.addClassToGrade(&a2);
	grade2.addClassToGrade(&h1);
	grade2.addClassToGrade(&h2);
	grade3.addClassToGrade(&v1);
	grade4.addClassToGrade(&z1);

	rabinSchool.addGrade(&grade1);
	rabinSchool.addGrade(&grade2);
	rabinSchool.addGrade(&grade3);
	rabinSchool.addGrade(&grade4);
	//end of adding

	Trip trip1("Sde Boker", 2);
	CampingTrip campingTrip(trip1, "Sde Boker", 1);
	Trip trip2("Hermon", 2);
	ClassTrip classTrip(trip2, &a1);
	ClassCampingTrip classCampingTrip(classTrip, campingTrip, "Yeaaaaaa");
	a1.addTripToClass(&classCampingTrip);
	rabinSchool.getGradesAvg();

	//Design Pattern #2 -> Visitor
	rabinSchool.accept(new RaiseSalaryVisitor(1020.8));
	Trip trip3("Eilat", 6);
	CampingTrip annualTrip(trip3, "Eilat", 2);
	rabinSchool.setAnnualTrip(&grade2, &annualTrip);
	rabinSchool.endYear();

	//#Design Pattern #3 -> Template 
	rabinSchool.printAllEmployees();

	system("Pause");
}