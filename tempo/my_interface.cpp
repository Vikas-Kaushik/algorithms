#include<iostream>

#include"my_interface.h"

using namespace std;

int Fn1(int a, int b){
  cout << endl;
  cout << "In Fn1 and summing a and b...";
  int c = a + b;
  cout << endl;
  return c;
}

void Fn2(){
  cout << endl << "In Fn2......" << endl;
}
