#include<iostream>
#include<cstdlib>
#include"random.h"

int RandomInteger(int low, int high){
  double d = double(rand()) / RAND_MAX;
  return low + (high - low) * d;
}

double RandomReal(double low, double high){
  double d = double(rand()) / RAND_MAX;
  return low + (high - low) * d;
}

bool RandomChance(double p){
  double d = double(rand()) / double(RAND_MAX + 1);
  return p > d;
}

void Randomize(){
  srand(int(time(NULL)));
}
