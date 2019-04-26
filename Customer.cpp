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

Customer::Customer(string& line){
  string temp = "";
  string tempName = "";
  bool isTimeIn=true;
  string tempNum = "";
  for(int i = 0; i < line.size(); i++){
		if(isalpha(line.at(i))){
			tempName += line.at(i);
		}else if(isdigit(line.at(i))){
			tempNum += line.at(i);
		}else if(isspace(line.at(i))){
			if(isTimeIn){
        this->name = tempName;
				isTimeIn = false;
			} else {
        this->timeIn = stoi(tempNum);
        tempNum = "";
      }
		}
	}
  this->mins = stoi(tempNum);

  /*string temp = "";
  for(int i =0; i < line.size(); i++){
    if(!isspace(line.at(i))){
      temp += line.at(0);
    } else {
      line = line.substr(line.at(i+1), line.size());
      break;
    }
  }
  this->name = temp;
  temp = "";
  for(int i =0; i < line.size(); i++){
    if(!isspace(line.at(i))){
      temp += line.at(0);
    } else {
      break;
    }
  }
  this->timeIn = stoi(temp);
  temp = "";
  for(int i =0; i < line.size(); i++){
    if(!isspace(line.at(i))){
      temp += line.at(0);
    } else {
      break;
    }
  }
  this->mins = stoi(temp);
  temp = "";*/
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
