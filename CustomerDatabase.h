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
  //this takes a file and makes each line a customer
  void calcTime(int time, Customer& tempCust, queue<Customer>& line);
  //this determines what happens each minute.
  //it first checks to see if there is anyone joining the queue
  //next it sees if there is anyone who will leave the Teller
  //finally it adds a person to the teller if there is someone in line
  bool getInTeller();
  //returns if there is someone with the teller
  double avgTime();
  //averages the wait time

private:
  string file;  //the file used
  linked_list<Customer> database; //the list of all customers
  int inside;	//the amount of time spent inside
  double totalTimeWaited; //the amount of time waited by everyone combined
  double avg; //the average time waited
  Customer atTeller;  //Who is currently with the teller
  bool inTeller;  //true if anyone is with the teller
};

#endif
