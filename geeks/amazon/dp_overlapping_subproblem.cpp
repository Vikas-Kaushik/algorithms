// This program is from geeksforgeeks.com
// Dynamic programming - optimal substructue 
// example of fibonacci nos

#include <iostream>

#define NIL -1
#define MAX 100

using namespace std;

int fib(int n);
void initialize();

int fib_arr[MAX];

int main(){
  int n;
  initialize();
  cout << "Enter no: ";
  cin >> n;
  cout << "Fib no : " << fib(n);
  cout << endl;
  return 0;
}

void initialize(){
  fib_arr[0] = 0;
  fib_arr[1] = 1;
  for(int i = 2; i < 100; ++i) {
    fib_arr[i] = NIL;
  }
}

int fib(int n){
  if(fib_arr[n] == NIL)
    fib_arr[n] = fib(n-1) + fib(n-2);
   
  return fib_arr[n];
}
