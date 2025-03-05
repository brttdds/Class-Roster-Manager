#include <iostream> 
#include <string>
#include "roster.h"

using namespace std;

int main() {

	cout << "C867 - Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 012374902" << endl;
	cout << "Name: Brett Dudley" << endl;
	cout << "\n";


const string studentData[] = 
{
"A1, John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Brett,Dudley,bdudle13@wgu.edu,28,30,11,35,SOFTWARE" 
};


const int numStudents = 5;
Roster classRoster;


for (int i = 0; i < numStudents; i++) classRoster.parseStudentData(studentData[i]); 


cout << "Displaying all students: " << endl;
classRoster.printAll();
cout << endl;

cout << "Displaying invalid emails: " << endl;    
classRoster.printInvalidEmails();
cout << endl;


for (int i = 0; i < numStudents; i++)             
{
	cout << "Average days in course: " << endl;
	classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
}


cout << "Showing students in degree program: " << degreeProgramStrings[DegreeProgram::SOFTWARE];
cout << "\n";
classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
cout << endl;


cout << "Removing A3" << endl;
classRoster.remove("A3");
cout << endl;


classRoster.printAll();
cout << endl;

cout << "Removing A3 again" << endl;
classRoster.remove("A3");
cout << endl;

cout << "DONE" << endl;

classRoster.~Roster();

return 0;
}

