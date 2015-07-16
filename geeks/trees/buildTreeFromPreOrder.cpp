/* problem 33 karumanchi 
   print bt from preorder when leaf and internal nodes are known and there will be eihter 0 or 2 children
*/

#include <iostream>

using namespace std;

void Fn(int max, int *a, int &b, int c);

int main(void) {
  int *a,b,c,max=5;
  a = &b;
  b = c = 0;

  cout << *a << " " << b << " " << c << " in main" << endl;

  Fn(max, a, b, c);

  cout << *a << " " << b << " " << c <<  " in main" << endl;

  return 0;
}


// Study and try to run following Fn. Also observe the values of parameters from where you have called Fn.
// Fn is a recursive function.
// Fn takes three arguments - a using pointer, b as reference and c as value.
// Fn prints these arguments and simply returns when all of them become max.

void Fn(int max, int *a, int &b, int c) {
  if(*a <= max || b <= max || c <= max) { // base case i.e. increment a,b,c till max
    cout << *a << " " << b << " " << c << " before recursive call" << endl;
    ++(*a); ++b; ++c; // incrementing all three parameters
    Fn(max, a, b, c); // recursive function call
    cout << *a << " " << b << " " << c << " after recursive call" << endl; // uncomment to see 
  }
}
