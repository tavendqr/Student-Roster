#include "student.h"
#include "roster.h"
#include <iostream>
#include <string>

Student::Student() {
    theStudentID = "";
    theFirstName = "";
    theLastName = "";
    theEmailAddress = "";
    theStudentAge = "";
    daysInCourse = nullptr;
    degreeProgram;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, string studentAge, int daysInCourse[], DegreeProgram type) {
    theStudentID = studentId;
    theFirstName = firstName;
    theLastName = lastName;
    theEmailAddress = emailAddress;
    theStudentAge = studentAge;

    // Allocate and copy the array
    this->daysInCourse = new int[3];
    for (int i = 0; i < 3; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }

    degreeProgram = type;
}

Student::~Student() {
    // Deallocate memory for the dynamically allocated array
    delete[] daysInCourse;
}

// Getters
string Student::GetStudentId() { 
    return theStudentID; 
}
string Student::GetFirstName() {
    return theFirstName; 
}
string Student::GetLastName() { 
    return theLastName; 
}
string Student::GetEmailAddress() { 
    return theEmailAddress; 
}
string Student::GetStudentAge() { 
    return theStudentAge;
}
int* Student::GetDaysInCourse() {
    return daysInCourse; 
}
DegreeProgram Student::GetDegreeProgram() { 
    return degreeProgram; 
}

// Setters
void Student::SetStudentId(string studentId) { 
    theStudentID = studentId; 
}
void Student::SetFirstName(string firstName) {
    theFirstName = firstName; 
}
void Student::SetLastName(string lastName) { 
    theLastName = lastName;
}
void Student::SetEmailAddress(string emailAddress) { 
    theEmailAddress = emailAddress;
}
void Student::SetStudentAge(string studentAge) {
    theStudentAge = studentAge; 
}
void Student::SetDaysCourseComplete(int daysInCourse[]) {
    // Deallocation of the old array
    delete[] this->daysInCourse;

    // Allocate a new array and copy the values
    this->daysInCourse = new int[3];
    for (int i = 0; i < 3; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}



void Student::print() {
    int* tempDays = this->GetDaysInCourse();

    

    int daysInCourseA = tempDays[0];
    int daysInCourseB = tempDays[1];
    int daysInCourseC = tempDays[2];


    cout << this->GetStudentId() << "\t"
         << "First Name: " << this->GetFirstName() << "\t"
         << "Last Name: " << this->GetLastName() << "\t"
         << "Age: " << this->GetStudentAge() << "\t"
         << "daysInCourse: {" << daysInCourseA << ", " << daysInCourseB << ", " << daysInCourseC << "} "
         << "Degree Program: " << ConvertToString(this->GetDegreeProgram()) << endl << endl;
}


