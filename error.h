//This file defines a simple function for reporting errors
#ifndef _error_h
#define _error_h
#include <string>

//Precondition: Accepts a string as argument
//Postcondition: Writes the string message to the cerr stream & then exits the program with a standard status code indicating failure.
void error(std::string msg);

#endif

