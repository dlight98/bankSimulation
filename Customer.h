/*
Nick Turner
2019.4.25
*/
#include <iostream>
#include <string>
#ifndef CUSTOMER_H
#define CUSTOMER_H
using namespace std;

class Customer{
public:
  Customer(); //default constructor
  Customer(string name, int time, int mins);  //constructor
  Customer(string& line); //makes the Customer from one file line

  //getters
  string getName();
  int getTimeIn();
  int getMins();
  //setters
  void setName(string name);
  void setTime(int time);
  void setMins(int mins);

private:
  string name;
  int timeIn;
  int mins;
};

#endif
