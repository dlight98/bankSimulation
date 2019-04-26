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



#endif
