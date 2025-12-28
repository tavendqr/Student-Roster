 // main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "student.h"
#include "roster.h"
using namespace std;
int main()
{
	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Dartaven,Fosnaugh,dartavenf@gmail.com,19, 14,13,8,SOFTWARE" };


	cout << "Course title: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming language: C++" << endl;
	cout << "Student ID:010909671" << endl;
	cout << "Name: Dartaven Fosnaugh" << endl << endl;


	Roster classRoster(0);

	//adds values in studentData to variables in Student objects
	for (int i = 0; i < 5; i++) {
		
		classRoster.ParseValues(studentData[i]);	
	}

	classRoster.printAll();

	classRoster.printInvalidEmails();

	classRoster.printAverageDaysInCourse("A5");


	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");




	return 0;
}

