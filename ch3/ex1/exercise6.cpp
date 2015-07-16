#include<iostream>

using namespace std;

bool IsPalindrome(string str);

int main(){
  cout << endl << "In main program...";

  if(IsPalindrome("noon"))
     cout << "noon is palindrome" << endl;

  if(IsPalindrome("n"))
     cout << "n is palindrome" << endl;

  if(!IsPalindrome(""))
     cout << "Not a palindrome" << endl;

  if(IsPalindrome("Hello"))
     cout << "Hello is not a palindrome" << endl;

  return 0;
}

bool IsPalindrome(string str){
  int l = str.length();

  cout << endl;
  cout << "You entered : " << str << endl;
  if(l <= 0)
    cout << "Invalid string length." << endl;

  else if(l == 1)
    return true;

  else {
    int i, j;
    i = 0;
    j = l - 1;

    while( (i < j) && (str[i] == str[j]) ){
      cout << endl << "comparing " << str[i] << " == " << str[j]; 
      cout << endl << " i , j : " << i << ", " << j;
      ++i;
      --j;
    }
    cout << endl << " i , j : " << i << ", " << j << endl;
    if((i - j) <= 1)
      return true;
    else
      return false;
  }
  return false;
}
