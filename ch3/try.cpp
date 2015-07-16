#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<string>

using namespace std;

int main(){
  string str;
  str = "Hello world";
  cout << endl << str;

  str.replace(6, 0, "vikasu");

  cout << endl << str;
  /*
  cout << endl;
  cout << "On this computer RAND_MAX = " << RAND_MAX;
  cout << endl << "10 Trials to rand() :- ";
  for(int i = 0; i < 10; ++i){
    srand(int(time(NULL)));
    cout << endl << "time function returns " << time(NULL) << endl;
    cout << endl << i << ". trial gives " << setw(10) << rand();
  }
  */
  cout << endl;
  return 0;
}
