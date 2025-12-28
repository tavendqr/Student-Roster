#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


#include "student.h"


class Roster {
public: 
	Roster();
	Roster(int max);
	~Roster();
	void ParseValues(string studentData);
	
	//functions for E3
	 
	void add(string theStudentID, string theFirstName, string theLastName, string theEmailAddress, string theAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram type);
	void remove(string theStudentID);
	void printAll();
	void printAverageDaysInCourse(string theStudentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

private:
	int max = 0;
	Student** classRosterArray; 
	string theStudentID; 
	string theFirstName;
	string theLastName;
	string theEmail;
	string theAge;
	int* daysInCourse;
	int index = 0;
	DegreeProgram degreeProgram;  


};


#endif