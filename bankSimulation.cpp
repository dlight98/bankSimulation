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
	int curTime = 900;
	queue<Customer> line;
	while(curTime < 1701){
		listOfPeople.calcTime(curTime, tempCust, line);
		curTime++;
	}
	while(!line.empty() || listOfPeople.getInTeller() == true){
		listOfPeople.calcTime(curTime, tempCust, line);
		curTime++;
	}

	return 0;
}
#endif
