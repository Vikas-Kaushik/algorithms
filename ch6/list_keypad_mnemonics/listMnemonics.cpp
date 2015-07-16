/**
 * File: file_name.cpp
 * --------------------
 * This program prints all combinations corresponding to 
 * the number typed on a phone keypad.
 */
#include <iostream>
#include <cstdlib>

using namespace std;
/**
 * A global variable of grid type is needed to represent 
 * phone keypad and to be accessed anywhere.
 */
//Grid<int> keypad(12,5);
int count = 0;
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

/* Private Function Prototype */
//void InitializeKeypad(Grid<int> &keypad(12,5));
void ListMnemonics( string keys, string printChars);

/* Main Function */
int main(){
  string keys;
  string printChars = "";
  cout << endl << "Enter phone keys (number) : ";
  cin >> keys;
  ListMnemonics( keys, printChars);
  cout << endl;
  return 0;
}
/**
 * Function: void ListMnemonics( string keys, string printChars)
 * Usage: 
 * -----------------------------------------
 * This recursive function prints all combinations corresponding to the key number typed on phone keypad.
 */
void ListMnemonics( string keys, string printChars){
  int l = keys.length();
  if(l == 0){ //no keys entered i.e. key string is empty.
    cout << endl << ++count << "  " << printChars;
  } else {
    int keyNo = atoi( &keys[l-1]);
    int k = keypads[keyNo].length();
    for(int i = 0; i < k; ++i){
      char ch = keypads[keyNo][i];
      string newKeys = keys.substr(0, l-1);
      string newPrintChars = ch + printChars;
      ListMnemonics( newKeys, newPrintChars);
    }
  }
}

/**
 * Function: InitializeKeypad(Grid<int> &keypad(12,5))
 * Usage: 
 * -----------------------------------------
 * This function initializes the keypad grid.
 * Commenting this function as I am going to use
 * an array of string instead of a grid.
 */
/**
void InitializeKeypad(Grid<int> &keypad(12,5)){
  cout << endl << "Initialising Phone Keypad.." << endl;
  keypad.setAt(0,0) = 
}
*/
