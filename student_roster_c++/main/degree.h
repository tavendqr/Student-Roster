#pragma once
#ifndef DEGREE_H
#define DEGREE_H
#include <string>
#include <iostream>
using namespace std;

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

inline DegreeProgram ConvertToDegree(const std::string& degreeString) {
    if (degreeString == "SECURITY") {
        return SECURITY;
    }
    else if (degreeString == "NETWORK") {
        return NETWORK;
    }
    else if (degreeString == "SOFTWARE") {
        return SOFTWARE;
    } 
    else {
        cout << "Invalid degree: " << degreeString << endl;
        return SOFTWARE; 
    }
    

}

//converts DegreeProgram enum to string
inline string ConvertToString(DegreeProgram myDegree) {
    if (myDegree == SECURITY) {
        return "SECURITY";
    }
    else if (myDegree == NETWORK) {
        return "NETWORK";
    }
    else if (myDegree == SOFTWARE) {
    return "SOFTWARE";
    }
    else {
        cout << "invalid Degree Program type" << endl;
        return "UNKNOWN";
    }
}


#endif



