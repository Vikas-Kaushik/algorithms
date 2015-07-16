#include<iostream>

using namespace std;

int main(){

  char keys[10][4] = {
    {'*','*','*','*'},    // key #0
    {'*','*','*','*'},    // key #1
    {'a','b','c','*'},    // key #2 
    {'d','e','f','*'},    // key #3 
    {'g','h','i','*'},    // key #4 
    {'j','k','l','*'},    // key #5 
    {'m','n','o','*'},    // key #6 
    {'p','q','r','s'},    // key #7 
    {'t','u','v','*'},    // key #8 
    {'w','x','y','z'},    // key #9 
  };

  // Let's take 3 keys i.e. 2,3,4 to print all permutations.

  int key_seq[3] = {2,3,4};
  char prnt_strn[3] = {' ',' ',' '};
  /*
  for(int i = 0; keys[(key_seq[0])][i] != '*'; ++i){
    prnt_strn[0] = keys[(key_seq[0])][i];

    for(int j = 0; keys[(key_seq[1])][j] !='*'; ++j){
      prnt_strn[1] = keys[(key_seq[1])][j];

      for(int k = 0; keys[(key_seq[2])][k] != '*'; ++k){
	prnt_strn[2] = keys[(key_seq[2])][k];
	cout << endl << prnt_strn << endl;
      }
    }
  } 
  */
  int count = 0;

  for(int i = 0; i < 3; ++i){
    prnt_strn[0] = keys[(key_seq[0])][i];

    for(int j = 0; j < 3; ++j){
      prnt_strn[1] = keys[(key_seq[1])][j];

      for(int k = 0; k < 3; ++k){
	prnt_strn[2] = keys[(key_seq[2])][k];
	cout << endl << prnt_strn << endl;
	++count;
      }
    }
  } 

  cout << endl << "count = " << count;
  cout << endl << "keys[1][1] " << keys[1][1] << endl;

  return 0;
}
