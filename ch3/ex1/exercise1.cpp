#include<iostream>
#include<cstdlib>

using namespace std;

void Doit(int count);
double Guess();

int main(){
  int count = 0;
  cout << endl << "This program averages a series of random numbers between 0 and 1." << endl;
  cout << "How many trianl : ";
  cin >> count;

  Doit(count);

  return 0;
}

void Doit(int count){
  if(count <= 0){
    cout << "Wrong number entered." << endl;
    return;
  }
  double sum = 0;
  for(int i = 0; i < count; ++i){
    sum += Guess();
  }
  cout << endl << "The average value after " << count << " trials is " << sum/count << endl;
}

double Guess(){
  srand(int(time(NULL)));
  double guess = (double)rand() / RAND_MAX;
  return guess;
}
