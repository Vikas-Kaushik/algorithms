/**
 * File: ListStringPermutation.cpp
 * --------------------
 * This program prints all the permutations 
 * of a given string.
 */

#include <iostream>
#include <string>

using namespace std;

/* Private Function Prototype */

void ListPermutations(string str);
void RecursivePermute(string prefix, string rest);
void NewListPermutations(string str, int c);
void ListPermutationsRepetition(string str);
void RecursivePermuteRepetition(string prefix, string rest, string repeatingChar);
bool findCharInString(char ch, string prefix);

/* Main Function */
int main(){
  string str;
  int count;  // count is the number of initial characters in string that user don't want to permute.
  cout << endl << "Please enter string : ";
  cin >> str;
  cout << "Printing permutations of whole string..." << endl;
  ListPermutations(str);
  cout << endl << "Please enter number of initial chars that you don't want to permute : ";
  cin >> count;
  cout << "Printing permutations of last " << count << " chars..." << endl;
  NewListPermutations(str, count);

  cout << endl << "Now enter a string with repeating chars : ";
  cin >> str;
  ListPermutationsRepetition(str);

  return 0;
}

/**
 * Function: void ListPermutations(string str)
 * Usage: 
 * -----------------------------------------
 * This function is a wrapper functions for RecursivePermute function.
 */
void ListPermutations(string str){
  string prefix = "";
  string rest = str;
  RecursivePermute(prefix, rest);
}

/**
 * Function: void RecursivePermute(string prefix, string rest)
 * Usage: 
 * -----------------------------------------
 * This function prints all permutaions of string.
 */
void RecursivePermute(string prefix, string rest){
  int l = rest.length();
  if(l == 0){
    cout << prefix << endl;
  } else {
    for(int i = 0; i < l; ++i){
      string newPrefix = prefix + rest[i];
      string newRest = rest.substr(0, i) + rest.substr(i+1);
      RecursivePermute(newPrefix, newRest);
    }
  }
}

/**
 * Function: 
 * Usage: 
 * -----------------------------------------
 * This function is a new technique to print permutations,
 * provided that how many chars you want to permute.
 */

void NewListPermutations(string str, int c){
  int l = str.length();
  if(c == l){
    cout << str << endl;
  } else {
    for(int i = c; i < l; ++i){
      string newPrefix = str.substr(0, c) + str[i];
      string newRest = str.substr(c, (i-c));
      if( i < (l-1))  // To avoid string::out of bound access error. e.g. str[l]- is invalid.
	newRest += str.substr(i+1);

      NewListPermutations((newPrefix + newRest), c+1);
    }
  }
}

/**
 * Function: void ListPermutations(string str)
 * Usage: 
 * -----------------------------------------
 * This function is a wrapper functions for RecursivePermute function.
 */
void ListPermutationsRepetition(string str){
  cout << endl << "In function void ListPermutationsRepetition(string str)" << endl;
  string prefix = "";
  string rest = str;
  string repeatingChars = "";
  RecursivePermuteRepetition(prefix, rest, repeatingChars);
}

/**
 * Function: void RecursivePermuteRepetition(string prefix, string rest)
 * Usage: 
 * -----------------------------------------
 * This function prints all permutaions of string.
 */
void RecursivePermuteRepetition(string prefix, string rest, string repeatingChars){
  int l = rest.length();
  if(l == 0){
    cout << prefix + repeatingChars << endl;
  } else {
    for(int i = 0; i < l; ++i){
      if( !findCharInString(rest[i], prefix) ){ // This check will not allow a character to be repeated in the prefix part.
	string newRepeatingChars = repeatingChars + rest[i];
	string newPrefix = prefix;
	string newRest = rest.substr(0, i) + rest.substr(i+1);
	RecursivePermuteRepetition(newPrefix, newRest, repeatingChars);
      } else {
	string newRepeatingChars = repeatingChars;
	string newPrefix = prefix + rest[i];
	string newRest = rest.substr(0, i) + rest.substr(i+1);
	RecursivePermuteRepetition(newPrefix, newRest, repeatingChars);

      }
    }
  }
}

bool findCharInString(char ch, string prefix){
      int check = prefix.find(ch);
      if(prefix == "")
	return false;

      int l = prefix.length();

      if( (l > 0) && ((check > 0) || (check < l)) )
	return true;
      else 
	return false;
}
