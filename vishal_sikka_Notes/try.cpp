#include<iostream>

using namespace std;

int main(){
  cout << endl;



  // following example shows the difference between c-style string and string type in c++. 
  // a char array automatically adds null character at the end i.e. '\0'
  // that's why char array "hello" have length 6 rather than 5 as in string type
  /*
  char str[] = "hello";
  int l = sizeof(str)/sizeof(str[0]);
  cout << "String length is " << l << endl;
  cout.write(str,l);

  string s1 = "hello";
  cout << endl << "s1 length is = " << s1.length();
  */
  /*
  cout << "Size of an int is = " << sizeof(int) << endl;
  cout << "Size of an float is = " << sizeof(float) << endl;
  cout << "Size of an short is = " << sizeof(short) << endl;
  cout << "Size of an char is = " << sizeof(char) << endl;
  cout << "Size of an unsigned int  is = " << sizeof(unsigned int) << endl;
  cout << "Size of an long is = " << sizeof(long) << endl;
  cout << "Size of an double is = " << sizeof(double) << endl;
  */
  cout << endl;
  return 0;
}
