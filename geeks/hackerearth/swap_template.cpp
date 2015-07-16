/*
 * Creating a generic function 'swap()' using template.
 *
 */

#include <iostream>

using namespace std;

//template <class T> void swap(T &a, T &b);
template <typename T>
void swap(T const& a, T const& b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}


int main(){
  int a = 10, b = 20;
  cout << endl << "a = " << a << ", b = " << b;
  swap(a,b);
  cout << endl <<  "a = " << a << ", b = " << b;

  float c = 10.5f, d = 67.901f;
  cout << endl << "c = " << c << ", d = " << d;
  swap(c,d);
  cout << endl << "c = " << c << ", d = " << d;
}
