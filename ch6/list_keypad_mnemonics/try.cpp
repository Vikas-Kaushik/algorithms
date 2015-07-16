/**
 * To try some experiments with array of string.
 * How to access a particular char in string at a 
 * particular index of array.
 */
#include <iostream>
//#include <string>
//#include <cctype>
//#include <stdlib.h>
#include <cstdlib>
using namespace std;

string keypads[] = {
  "",
  "",
  "abc",
  "def",
  "ghi",
  "jkl",
  "mno",
  "pqrs",
  "tuv",
  "wxyz",
};

void InitializeKeypad(string keypads[]);

int main(){
  //  int key;
  string key;
  cout << endl << "Enter phone keys (number) : ";
  cin >> key;

  char *e = &key[0];
  int keyNo =  atoi(e);
  cout << endl << "You entered = " << keyNo;
  //  int keyNo = key - '0'; // char to integer conversion

  string keyString = keypads[keyNo];
  //  char keyChar = keypads[keyNo];
  cout << endl << "keyString : " << keyString << endl;
  cout << endl << "str[0] = " << keypads[keyNo][0] << endl;

  return 0;
}
