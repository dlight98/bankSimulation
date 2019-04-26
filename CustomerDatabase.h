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
  double avgTime();

private:
  string file;
  linked_list<Customer> database;
  int inside;	//the amount of time inside
  double totalTimeWaited;
  double avg;
  Customer atTeller;
  bool inTeller;
};

#endif
