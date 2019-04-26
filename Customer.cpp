#include <iostream>
#include <string>
#include "Customer.h"
#include "CustomerDatabase.h"
#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

Customer::Customer(){}

Customer::Customer(string name, int time, int mins){
  this->name = name;
  this->timeIn = time;
  this->mins = mins;
}


/*getters and setters*/
void Customer::setName(string name){
  this->name = name;
}

void Customer::setTime(int time){
  this->timeIn = time;
}

void Customer::setMins(int mins){
  this->mins = mins;
}

string Customer::getName(){
  return name;
}

int Customer::getTimeIn(){
  return timeIn;
}

int Customer::getMins(){
  return mins;
}

#endif
