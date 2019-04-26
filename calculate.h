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

private:
	int inside;	//the amount of time inside
	queue<Customer> line;

};

#endif
