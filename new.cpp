#include<stdio.h>
#include<iostream>
#include<iomanip>
#include <math.h>
#include <climits>

using namespace std;

int Round(float);
void numberToWords(int n);
void fillNumbers(string[]);
int countDigits(int n);

int main(){
  cout<<"hello kya haal";
  printf("Hello owrld \n");

  struct tempT{
    int balue;
  };

  tempT tp;

  tp.balue = 93;

  cout << endl << tp.balue << endl;
  int arr[4];

  const int a = 0;
  const int b = 1;

  switch(-1){
  case a: 
    cout << endl << "it's a";
    break;
  case b:
    cout << endl << "it's b";
    break;
  default:
    cout << endl << "default";
    break;
  }
  cout << endl;

  // Chapter 1, Exercise 12
  // Printing a number in words upto 999,999
  cout << endl << INT_MAX << endl;
  int n;
  cout << "Enter no : ";
  cin >> n;
  void numberToWords(int n);

  // Chapter 1, Exercise 10
  // Leibniz's series to get value of pie
  // double d = 0;
  // double sign = 1;
  // for(int i=1; i<=20001; i+=2){
  //   cout << d << "  " << i << endl;
  //   //    d = d + (sign * 1 / (double)i);
  //   d = d + (sign * ((double)1 / i ));
  //   sign = sign * -1;
  // }
  // d = d * 4;
  // cout << "pie : " << d << endl;

  // Chapter 1, Exercise 9
  // Rounding off a float no
  // float f;
  // cout << "Enter a float : ";
  // cin >> f;
  // cout << "Rounded : " << Round(f);
  // cout << endl;


  // Chapter 1, Exercise 5
  // Taking input till sentinel is entered and then output maximum number entered.
  // int max = 0;
  // int n = 0;
  // cout << endl << "Enter any integer values.";
  // cout << endl << "Please use 0 as sentinel." << endl;
  // do{
  //   cout << endl << "? ";
  //   cin >> n;
  //   max = (max > n) ? max : n;
  // }while(n != 0);

  // cout << endl << "Maximum is : " << max;
  // cout << endl;


  return 0;
}

int Round(float f){
  int sign = (f < 0) ? -1 : 1;
  f = f * sign;
  int n = (int) f;
  f = f - n;

  if(f >= 0.5)
    return (n+1)*sign;
  else
    return n*sign;
}

void numberToWords(int n){
  string number[20];
  fillNumbers(number);
  int i = countDigits(n);
}

void fillNumbers(string number[]){
  number[0] = "zero";
  number[1] = "";
  number[2] = "";
  number[3] = "";
  number[4] = "";
  number[5] = "";
  number[6] = "";
  number[7] = "";
  number[8] = "";
  number[9] = "";
  number[10] = "";
  number[11] = "";
  number[12] = "";
  number[13] = "";
  number[14] = "";
  number[15] = "";
  number[16] = "";
  number[17] = "";
  number[18] = "";
  number[19] = "";
  number[20] = "";

}

int countDigits(int n){
  int i = 0;
  while(n >= 1){
    ++i;
    n = n / 10;
  }
  return i;
}
