//This file implements the random.h interface
#include <cstdlib>
#include <cmath>
#include "random.h"
using namespace std;

/* Private function prototype */
void initRandomSeed();
//Postcondition: Generates a random real number d in the range [0…1]. Since the calculattion can overflow the integer reange, we use doubles instead.
int randomInteger(int low, int high) {
	initRandomSeed();
	double d = rand() / (double(RAND_MAX) + 1);
	double s = d*(double(high)-low+1);
	return int(floor(low+s));
}
//Postcondition: Calls randomReal(0,1) & then checks whether the result is < the requested probability
bool randomChance(double p) {
	initRandomSeed();
	return randomReal(0,1)<p;
}
//Postconditon: Forwards its argument to srand. The call to initRandomSeed is required to set the initialized flag.
void setRandomSeed(int seed) {
	initRandomSeed();
	srand(seed);
}

