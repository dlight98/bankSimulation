#include <iostream>
#include <fstream>
#include <string>
#include "CustomerDatabase.h"
#include "Customer.h"
#include "linked_list.h"
#ifndef CUSTOMERDATABASE_CPP
#define CUSTOMERDATABASE_CPP
using namespace std;

CustomerDatabase::CustomerDatabase(){}

CustomerDatabase::CustomerDatabase(string filename){
  this->file = filename;
  this->inside = -1;
  this->totalTimeWaited = 0;
  inTeller = false;
  ifstream filepointer;
	filepointer.open(filename);
	if(!filepointer.is_open()){
		cout<<"File not found."<<endl;
	}else{
		string tempS;
		while(!filepointer.eof()){
			getline(filepointer, tempS);
			if(filepointer.eof()){
				break;
			}
			Customer temp = Customer(tempS);
			this->database.InsertRear(temp);
		}
		filepointer.close();
	}
}

bool CustomerDatabase::getInTeller(){
  return inTeller;
}

void CustomerDatabase::calcTime(int calTime, Customer& tempCust, queue<Customer>& line){
  database.makeCurFirst();
  while(database.isCurLast() == false){
    if(calTime == database.getCurrent().getTimeIn()){
      tempCust = database.getCurrent();
      break;
    } else {
      database.curNext();
    }
  }
  if(calTime == database.getCurrent().getTimeIn()){ //do it one last time
    tempCust = database.getCurrent();
  }
  if(calTime == tempCust.getTimeIn()){
    cout<<tempCust.getName()<<" got in line at "<<calTime<<"."<<endl;
    line.push(tempCust);
  }if(inside <= 0){
    if(inside == 0){
      cout<<atTeller.getName()<<" is done at "<<calTime<<"."<<endl;
      inTeller = false;
    }
  }
    if(!line.empty() && !inTeller) {
      inTeller = true;
      atTeller = line.front();
      line.pop();
      inside = atTeller.getMins();
    }
  inside--;
  this->totalTimeWaited += line.size();
}

double CustomerDatabase::avgTime(){
  double count = 0.0;
  database.makeCurFirst();
  while(database.isCurLast() == false){
    count++;
    database.curNext();
  }
  count++;
  avg = totalTimeWaited / count;
  return avg;
}

#endif
