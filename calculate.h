#include <iostream>
#include <queue>
#include <string>
#include "linked_list.h"
#include "CustomerDatabase.h"
#include "Customer.h"

#ifndef CALCULATE_H
#define CALCULATE_H
using namespace std;

class Calculate {

public:
	Calculate();
	int calcClock(int calTime);
	//This calculates if the clock
	//should roll over. ex 1360 = 1400

private:
	int inside;	//the amount of time inside
	queue<Customer> line;

};

#endif
