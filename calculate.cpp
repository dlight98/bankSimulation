#include <iostream>
#include <queue>
#include "CustomerDatabase.h"
#include "Customer.h"
#include "calculate.h"
#ifndef CALCULATE_CPP
#define CALCULATE_CPP

using namespace std;

Calculate::Calculate(){}

int Calculate::calcClock(int calTime){
  int temp = 0;
  int temp2 = 0;
  int temp3 = 0;
  int ans = calTime;
  
  temp = calTime/100;
  temp = temp * 100;
  temp2 = calTime - temp;
  temp3 = temp2/60;
  if(temp3 >= 1){
    temp2 = temp2%60;
    ans = temp + 100 + temp2;
  }
  return ans; //TEMP
}


#endif
