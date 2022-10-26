//When prog is complete, # of cust served, avg time cust spends in
//the waiting line, avg length of waiting line r all displayed.
#include <iostream>
#include <iomanip>
#include <cmath>
#include "queue.h"
//#include <queue>
#include "random.h"
using namespace std; //223

//constants
const double ARRIVAL_PROBABILITY = 0.05; //prob new cust will arrive
const int MIN_SERVICE_TIME = 5; //cust service time, determined by
const int MAX_SERVICE_TIME = 15; //a random integer in the range
const int SIMULATION_TIME = 20000; //simulation duration
//function prototypes
void runSimulation(int& nServed, int& totalWait, int& totalLength);
void printReport (int nServed, int totalWait, int totalLength);
//Main program
int main() {
	int nServed;
	int totalWait;
	int totalLength;
	runSimulation(nServed, totalWait, totalLength);
	printReport(nServed, totalWait, totalLength);
    return 0;
}

/*Function: runSimulation
  Precondition:
  Postcondition: Returns the results of the simulation through the reference parameters, which record the number of outcomes served, the total number of seconds that customers were waiting in a queue, and the sum of the queue length in each time step
*/
void runSimulation(int& nServed, int& totalWait, int& totalLength) {
	Queue<int> q;
	int timeRemaining = 0;
	nServed = 0;
	totalWait = 0;
	totalLength = 0;
	for(int t=0; t<SIMULATION_TIME; t++) {
		if(randomChance(ARRIVAL_PROBABILITY)) {
			q.enqueue(t);
		}
		if(timeRemaining > 0) {
			timeRemaining--;
		}else if(!q.isEmpty()) {
			totalWait += t - q.dequeue();
			nServed++;
			timeRemaining = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
		}
		totalLength += q.size();
	}
}

/* Function: printReport
   Postcondition: Reports the results of the simulation */
   void printReport(int nServed, int totalWait, int totalLength) {
       cout<<"Simulation results given the following constants:"<<endl;
       cout<<fixed<<setprecision(2);
       cout<<" SIMULATION_TIME:    "<<setw(4)
           <<SIMULATION_TIME<<endl;
       cout<<"  ARRIVAL_PROBABILITY: "<<setw(7)
           <<ARRIVAL_PROBABILITY<<endl;
       cout<<"  MIN_SERVICE_TIME: "<<setw(4)
           <<MIN_SERVICE_TIME<<endl;
       cout<<"  MAX_SERVICE_TIME: "<<setw(4)
           <<MAX_SERVICE_TIME<<endl;
       cout<<endl;
       cout<<"Customers served:   "<<setw(4)<<nServed<<endl;
       cout<<"Average waiting time: "<<setw(7)
           <<double(totalWait) / nServed<<" secons"<<endl;
       cout<<"Average queue length: "<<setw(7) 
          <<double(totalLength) / SIMULATION_TIME<<" people"<<endl;
   }

