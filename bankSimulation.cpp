#include <iostream>
#include <queue>
#include <string>
#include "calculate.h"
#include "Customer.h"
#include "CustomerDatabase.h"
#ifndef MAIN_CPP
#define MAIN_CPP

using namespace std;

int main(){
	CustomerDatabase listOfPeople("line.txt");
	Customer tempCust;
	Calculate calc;
	int curTime = 900;
	double avg = 0.0;
	queue<Customer> line;
	while(curTime < 1701){
		curTime = calc.calcClock(curTime);		//first calculates to see if time should roll over
		listOfPeople.calcTime(curTime, tempCust, line);
		curTime++; //goto next minute
	}
	//once it is past 1700 go until empty
	while(!line.empty() || listOfPeople.getInTeller() == true){
		listOfPeople.calcTime(curTime, tempCust, line);
		curTime++;
	}
	avg = listOfPeople.avgTime();	//average the wait time
	cout<<"Average wait time is "<<avg<<" minutes."<<endl;

	return 0;
}
#endif
