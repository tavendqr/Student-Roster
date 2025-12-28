#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"
#include <array>
#include <string>
using namespace std;



Roster::Roster(int max) {
	
	this-> max = max;

	this->classRosterArray = new Student *[max];

}



//each value is separated based on position relative to ther commas and calls the add function
void Roster::ParseValues(string studentData) {
	stringstream studentStream(studentData);
	vector<string> studentVector;



	for (int i = 0; i < 9; i++) {
		string substring;
		getline(studentStream, substring, ',');
		studentVector.push_back(substring);
	}

	theStudentID = studentVector.at(0);
	theLastName = studentVector.at(1);
	theFirstName = studentVector.at(2);
	theEmail = studentVector.at(3);
	theAge = studentVector.at(4); //   stoi

	this->daysInCourse = new int[3];

	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = stoi(studentVector.at(i + 5));
	}

	degreeProgram = ConvertToDegree(studentVector.at(8));


	add(theStudentID, theFirstName, theLastName, theEmail, theAge, daysInCourse[0], daysInCourse[1], daysInCourse[2], degreeProgram);
}



//Deallocates memory from classRosterArray
Roster::~Roster() {
	cout << "Destructor has been called" << endl;
	delete[] classRosterArray;
}

void Roster::add(string theStudentID, string theFirstName, string theLastName, string theEmail, string theAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

	// Create a temporary array to hold the updated classRosterArray
	Student** temp = new Student * [max + 1];

	// Copy the existing students to the temporary array
	for (int i = 0; i < max; i++) {
		temp[i] = classRosterArray[i];
	}

	// Create a new Student object for the new student
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	temp[max] = new Student(theStudentID, theFirstName, theLastName, theEmail, theAge, daysInCourse, degreeProgram);

	// Delete the old classRosterArray and update it with the new array
	delete[] classRosterArray;
	classRosterArray = temp;

	// Increment max to reflect the updated number orf students
	max++;
}


//Print all the class variables of every object in classRosterArray
void Roster::printAll() {
	for (int i = 0; i < max; i++) {

		classRosterArray[i]->print();
	}

	

}





//Add all the DaysInCourse of each object that has the studentID of the argument and divide the sum by three
void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;

	for (int i = 0; i < max; i++) {
		if (classRosterArray[i]->GetStudentId() == studentID) {
			found = true;
			int* temp = classRosterArray[i]->GetDaysInCourse();
			int avg = 0;

			for (int l = 0; l < 3; l++) {
				avg += temp[l];
			}
			avg /= 3; // Calculate the average

			cout << "StudentID lookup for: " << classRosterArray[i]->GetStudentId() << endl;
			cout << "Student spent on average " << avg << " days per course" << endl;
			break; // Once found, exit the loop
		}
	}

	if (!found) {
		cout << "Student with ID " << studentID << " not found" << endl;
	}
}





void Roster::printInvalidEmails() {
	for (int i = 0; i < max; i++) {
		string currentEmail = classRosterArray[i]->GetEmailAddress();
		bool isValid = true;

		// Check for the presence of the '@' symbol
		size_t atPos = currentEmail.find('@');
		if (atPos == std::string::npos) {
			isValid = false;
		}
		else {
			// Check for the presence of a dot (.) after the '@'
			size_t dotPos = currentEmail.find('.', atPos);
			if (dotPos == std::string::npos) {
				isValid = false;
			}
		}

		// Check for spaces
		if (currentEmail.find(' ') != std::string::npos) {
			isValid = false;
		}

		// Output if the email is invalid
		if (!isValid) {
			std::cout << "Invalid email: " << currentEmail << std::endl;
		}
	}
	cout << endl;
}



void  Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	int count = 0; 
	string degreeString;
	string valueHolder;

	for (int i = 0; i < max; i++) {

		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {

			valueHolder +=  "Student ID: " + classRosterArray[i]->GetStudentId() +
				"\nFirst Name: " + classRosterArray[i]->GetFirstName() +
				"\nLast Name: " + classRosterArray[i]->GetLastName() +
				"\nEmail: " + classRosterArray[i]->GetEmailAddress() + "\n" + "\n";

			count++;
		}

		
	}
//Use string equivalent of DegreeProgram value
	if (degreeProgram == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		degreeString = "SOFTWARE";
	}

	
	cout << endl << count << " students have " << degreeString << endl << endl << valueHolder;

}

void Roster::remove(string studentID) {
	bool found = false;

	for (int i = 0; i < max; ++i) {
		if (classRosterArray[i]->GetStudentId() == studentID) {
			found = true;

			// Remove the student's entry from the classRosterArray
			delete classRosterArray[i];

			// Shift remaining elements to fill the gap
			for (int j = i; j < max - 1; ++j) {
				classRosterArray[j] = classRosterArray[j + 1];
			}

			classRosterArray[max - 1] = nullptr; // Set the last element to nullptr for safety
			max--; // Decrement the count of students

			cout << "Student with ID " << studentID << " has been removed" << endl;
			break; // Exit the loop once the student is found and removed
		}
	}

	if (!found) {
		cout << "Student with ID " << studentID << " not found" << endl;
	}
}
