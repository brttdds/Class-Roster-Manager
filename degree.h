#pragma once
#include <string>

using namespace std;

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE, NUM_DEGREE_PROGAMS/* why this ?*/ };  //define enumerated data type DegreeProgram

static const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };