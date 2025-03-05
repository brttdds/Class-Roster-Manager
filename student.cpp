#include <iostream> 
#include <string>
#include "student.h"


using namespace std;

// parameterless constructor
Student::Student() 
{
	this->StudentID = "";
	this->FirstName = "";
	this->LastName = "";
	this->EmailAddress = "";
	this->Age = 0;
	for (int i = 0; i < numCourses; i++) {
		this->DaysInCourse[i] = 0;
	}
	this->degreeProgram = DegreeProgram::SECURITY; // default value
}

// parameter constructor
Student::Student(string StudentID, string FirstName, string LastName, string EmailAddress, int age, int DaysInCourse[], DegreeProgram degreeProgram)
{
	this->StudentID = StudentID;
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->EmailAddress = EmailAddress;
	this->Age = age;
	for (int i = 0; i < numCourses; i++) { 
		this->DaysInCourse[i] = DaysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

// destructor that does nothing
Student::~Student() {}

// accessors or getters
string Student::getStudentID() {
	return this->StudentID;
}
string Student::getFirstName() {
	return this->FirstName;
}
string Student::getLastName() {
	return this->LastName;
}
string Student::getEmailAddress() {
	return this->EmailAddress;
}
int Student::getAge() {
	return this->Age;
}
int* Student::getDaysInCourse() {
	return this->DaysInCourse;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

// mutators or setters
void Student::setStudentID(string StudentID) {
	this->StudentID = StudentID;
}
void Student::setFirstName(string FirstName) {
	this->FirstName = FirstName;
}
void Student::setLastName(string LastName) {
	this->LastName = LastName;
}
void Student::setEmailAddress(string EmailAddress) {
	this->EmailAddress = EmailAddress;
}
void Student::setAge(int Age) {
	this->Age = Age;
}
void Student::setDaysInCourse(int DaysInCourse[])
{
	for (int i = 0; i < numCourses; i++) this->DaysInCourse[i] = DaysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::printHeader()
{
	//cout << " StudentID | FirstName | LastName | EmailAddress | Age | DaysInCourse | DegreeProgram\n";    //******************************************** COMMENT OUT
}

void Student::print() // using tab separated output and getters
{
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysInCourse()[0] << ',';
	cout << this->getDaysInCourse()[1] << ',';
	cout << this->getDaysInCourse()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
};
