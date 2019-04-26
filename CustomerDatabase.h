#include <iostream>
#include <fstream>
#include <string>
#include "linked_list.h"
#include "Customer.h"
#ifndef CUSTOMERDATABASE_H
#define CUSTOMERDATABASE_H
using namespace std;

class CustomerDatabase{
public:
  CustomerDatabase();
  CustomerDatabase(string filename);

private:
  string file;
  linked_list<Customer> database;

};

#endif
