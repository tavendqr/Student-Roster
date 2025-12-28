#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
#include <iostream>
using namespace std;


class Student {
public:
	Student();
	Student(string theStudentId, string theFirstName, string theLastName, string theEmail, string theAge, int daysInCourse[], DegreeProgram type);
	~Student();


	
	string GetStudentId();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	string GetStudentAge();
	int* GetDaysInCourse();
	
	virtual DegreeProgram GetDegreeProgram();

	
	void SetStudentId(string studentId);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetStudentAge(string studentAge);
	void SetDaysCourseComplete(int daysInCourse[]);
	void print();

private:
	string theStudentID;
	string theFirstName;
	string theLastName;
	string theEmailAddress;
	string theStudentAge;
	int* daysInCourse;
	DegreeProgram degreeProgram;  

};


#endif