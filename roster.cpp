#include <iostream> 
#include <string>
#include <array>
#include "roster.h"

using namespace std;

/*In file roster.cpp:

#include “roster.h”

 

You must define the parse() and the add() functions now because we will need them in the next steps. Declaration for add is given in E3a. Declaration of parse is:

public void parse(string row);

The definition of the remaining functions may be deferred until they are required, that is, create stub functions (empty functions) for now.*/

Roster::Roster()
{
	this->LastIndex = 0;
	
	for (int i = 0; i < numStudents; i++)
	{
		classRosterArray[i] = NULL;
	}
}

void Roster::parseStudentData(string studentData)
{
	DegreeProgram degreeProgram = SECURITY;                          // default value
	if (studentData.back() == 'K') degreeProgram = NETWORK;          // checks last character in degreePogram
	else if (studentData.back() == 'E') degreeProgram = SOFTWARE;

	string::size_type rhs = studentData.find(",");                                // parse all student data types
	string StudentID = studentData.substr(0, rhs);

	string::size_type lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string FirstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string LastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string EmailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int DaysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int DaysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int DaysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	add(StudentID, FirstName, LastName, EmailAddress, Age, DaysInCourse1, DaysInCourse2, DaysInCourse3, degreeProgram); 
}

// add method
void Roster::add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse1, int DaysInCourse2, int DaysInCourse3, DegreeProgram degreeProgram)
{
	// DaysInCourse array for constructor
	int DaysInCourse[3] = { DaysInCourse1, DaysInCourse2, DaysInCourse3 }; 
	classRosterArray[LastIndex++] = new Student(StudentID, FirstName, LastName, EmailAddress, Age, DaysInCourse, degreeProgram);
}

//** UPDATED printAll FUNCTION **

void Roster::printAll()
{
	for (int i = 0; i < Roster::LastIndex; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			classRosterArray[i]->print();
		}

	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i < Roster::LastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;

	for (int i = 0; i < Roster::LastIndex; i++)
	{                                                                         
		string EmailAddress = (classRosterArray[i]->getEmailAddress());
		if (EmailAddress.find("@") == string::npos || (EmailAddress.find(' ') != string::npos) || (EmailAddress.find('.') == string::npos))
		{
			any = true;
			cout << EmailAddress << ": " << classRosterArray[i]->getEmailAddress() << endl;

		}
	}
	if (!any) cout << "NONE" << endl;

}

void Roster::printAverageDaysInCourse(string StudentID)					
{
	for (int i = 0; i < Roster::LastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == StudentID)
		{
			cout << "Student ID: ";
			cout << StudentID;
			cout << " averages ";
			cout << (classRosterArray[i]->getDaysInCourse()[0] +
				classRosterArray[i]->getDaysInCourse()[1] +
				classRosterArray[i]->getDaysInCourse()[2])/3.0;
			cout << " days in a course." << endl;
			cout << endl;
		}
		
	}

}

void Roster::remove(string StudentID)							
{
	bool success = false; // assume it's not found
	for (int i = 0; i < Roster::LastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == StudentID)
		{
			success = true; // found
			
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1]; 
				classRosterArray[numStudents - 1] = temp; 

			Roster::LastIndex--; // Makes last student no longer visible but not actually deleted

		}
	}

	if (success)
	{
		cout << "Student ID: " << StudentID << " removed." << endl;
	}
	else
	{
		cout << "Student ID: " << StudentID << " not found." << endl;
	}
}

Roster::~Roster()
{
	cout << "DESTRUCTOR CALLED!!!" << endl;
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			cout << "Destroying Student #" << i + 1 << endl;
			delete classRosterArray[i];
			classRosterArray[i] = NULL;
		}
	}
}

