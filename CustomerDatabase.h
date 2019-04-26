#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "linked_list.h"
#include "Customer.h"
#ifndef CUSTOMERDATABASE_H
#define CUSTOMERDATABASE_H
using namespace std;

class CustomerDatabase{
public:
  CustomerDatabase();
  CustomerDatabase(string filename);
  void calcTime(int time, Customer& tempCust, queue<Customer>& line);
  bool getInTeller();

private:
  string file;
  linked_list<Customer> database;
  int inside;	//the amount of time inside
	//queue<Customer> line;
  Customer atTeller;
  bool inTeller;
};

#endif
