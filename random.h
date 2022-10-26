//This file expoets functions for generating pseudorandom numbers
#ifndef _random_h
#define _random_h

//Postcondition: Returns a random integer in the range, low to high, inclusive
int randomInteger(const int low, const int high);
//Precondition: Argument p must be a floating point between 0 (never) and 1 (always).
//Postcondition: Returns true with the probability indicated by p
bool randomChance(double p);
//Postcondition: Sets the internal random number seed to the specified value. Can be used to set a specific starting point for the pseudorandom sequene or to ensure that program behavior is repeatable during the debugginh phase.
void setRandomSeed(int seed); 

#endif

