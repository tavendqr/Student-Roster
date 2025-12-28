When unzipped open file main.vcxproj to run properly 

Use Visual Studio


Parsers string and adds students to object then adds object to classRosterArray

Prints all student information

Print all emails with invalid format

print average degree by specified ID

Prints degree program by specified job type

Removes student by ID



 I completed a C++ project where I built a student information system. The goal was to simulate migrating part of an existing student management platform.

I created two main classes:

Student, which held details like ID, name, email, age, days to complete courses, and degree program (as an enum: SECURITY, NETWORK, SOFTWARE).

Roster, which stored a dynamic array of Student objects and handled adding, removing, and displaying students.

The system parsed a list of students from a string array, split the data, and created student objects. I implemented methods to:

Print all student data

Validate and display invalid emails

Calculate average days in courses

Filter by degree program

Remove students by ID, including error handling

I also wrote a destructor to clean up memory from the dynamic array, which helped me understand C++ memory management better.

Overall, the project reinforced my skills in object-oriented programming, data parsing, and manual memory handling—core concepts in C++.



