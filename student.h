#pragma once
#include <string>
#include "degree.h"

using namespace std;

/*For the Student class, do the following :

1.  In files student.h and student.cpp create the Student class, which includes each of the following variables :

•  student ID

•  first name

•   last name

•  email address

•  age

•  array of number of days to complete each course

•  degree program

2.  Create each of the following functions in the Student class :

	a.an accessor(i.e., getter) for each instance variable from part D1

	b.a mutator(i.e., setter) for each instance variable from part D1

	c.All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.

	d.constructor using all of the input parameters provided in the table

	e.print() to print specific student data */ 




class Student {
	
public:
	
	// constant for array
	const static int numCourses = 3;

private:
	string StudentID;
	string FirstName;
	string LastName;
	string EmailAddress;
	int Age;
	int DaysInCourse[numCourses];
	DegreeProgram degreeProgram;

public:
	Student();                          // constructor
	Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse[], DegreeProgram degreeProgram); // full constructor
	~Student();                         // destructor
	                                    
	                                   // accessors or getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();            // pointer
	DegreeProgram getDegreeProgram();
	                                   
	                                  // mutators or setters
	void setStudentID(string StudentID);
	void setFirstName(string FirstName);
	void setLastName(string LastName);
	void setEmailAddress(string EmailAddress);
	void setAge(int Age);
	void setDaysInCourse(int DaysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);
	
	static void printHeader();
	void print();

};


