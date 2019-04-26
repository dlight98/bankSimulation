#include <iostream>
#include <queue>
#include <string>
#include "calculate.h"
#include "Customer.h"
#include "CustomerDatabase.h"
#ifndef MAIN_CPP
#define MAIN_CPP

using namespace std;

/*struct cust {
	string name;
	int timeEntered;
	int minutes;
};*/

int main(){
	CustomerDatabase listOfPeople("line.txt");
	Customer tempCust;
	Calculate calc;
	int curTime = 900;
	double avg = 0.0;
	queue<Customer> line;
	while(curTime < 1701){
		curTime = calc.calcClock(curTime);
		listOfPeople.calcTime(curTime, tempCust, line);
		curTime++;
	}
	while(!line.empty() || listOfPeople.getInTeller() == true){
		listOfPeople.calcTime(curTime, tempCust, line);
		curTime++;
	}
	avg = listOfPeople.avgTime();
	cout<<"Average wait time is "<<avg<<" minutes."<<endl;

	return 0;
}
#endif
