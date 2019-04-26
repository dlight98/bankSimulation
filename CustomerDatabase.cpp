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
      //cout<<temp.getName()<<" "<<temp.getTimeIn()<<" "<<temp.getMins()<<endl; //DEBUG
			this->database.InsertRear(temp);
		}
		filepointer.close();
	}
}

void CustomerDatabase::calcTime(int min, Customer& tempCust, queue<Customer>& line){
  cout<<"the minute is: "<<min<<endl; //DEBUG
  database.makeCurFirst();
  while(database.isCurLast() == false){  //FIXME
    if(min <= database.getCurrent().getTimeIn()){
      tempCust = database.getCurrent();
      break;
    } else {
      database.curNext();
    }
  }
  if(min <= database.getCurrent().getTimeIn()){ //do it one last time
    tempCust = database.getCurrent();
  }
  cout<<"got customer: "<<tempCust.getName()<<endl; //DEBUG
  if(min = tempCust.getMins()) {
    cout<<"Adding to line: "<<tempCust.getName()<<endl; //DEBUG
    line.push(tempCust);
    database.curNext();
  }if(this->inside <= 0) {
    if(this->inside == 0){
      cout<<atTeller.getName()<<" is done at "<<min<<"."<<endl;

    }
    if(!line.empty()) {
      atTeller = line.front();
      line.pop();
      inside = atTeller.getTimeIn();
      cout<<atTeller.getName()<<" has entered the teller"<<endl;//DEBUG
      inside++; //FIXME to offset the inside-- at the end
    }
  }
  inside--;
  //delete temp;
}

#endif
