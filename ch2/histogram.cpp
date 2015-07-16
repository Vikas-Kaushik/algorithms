// chapter 2, exercise 6 and 7
// Printing frequency of data in grapho form

#include <iostream>
#include <iomanip>

using namespace std;

// functions to make horizontal and vertical graphs, data frequency is passed.
// graph interval is like 0-9 10-19 20-29 upto 100
void horGraph(int *freq);
void verGraph(int *freq);
void callByReference(int &, char &);

int main(){
  // following code was just to check out call by reference syntax.
  // int m = 99;
  // char n = 'n';
  // cout << "m,n " << m << n;
  // callByReference(m, n);
  // cout << " new m,n " << m << n << endl;

  int data[] = {100, 95, 47, 88, 86, 92, 75, 89, 81, 70, 55, 80,};
  int freq[11];
  for(int i = 0; i <= 10; ++i){
    freq[i] = 0;
  }
  int size = sizeof data / sizeof data[0];
  for(int i = 0; i < size; ++i){
    int j = data[i]/10;
    ++freq[j];
  }
  horGraph(freq);
  verGraph(freq);
  cout << endl;
  return 0;
}

void horGraph(int *freq){
  for(int i = 0; i <= 100; i+=10){
    cout << endl << setw(4) << i << " : " << setw(3) << freq[i/10];
    int k = freq[i/10];
    while(k > 0){
      cout << " *";
      --k;
    }
  }
}
// This one is awesome. I was very happy after getting the idea to print vertical graph this way.
void verGraph(int *freq){
  int max = 0;
  for (int i = 0; i < 11; ++i){
    max = (freq[i] > max) ? freq[i] : max;
  }

  for (int i = max; i > 0; --i) {
    cout << endl << "| ";
    for (int j = 0; j < 11; ++j) {
      if (freq[j] == i) { // this line is special.
	cout << " * ";
	--freq[j];
      }
      else {
	cout << "   ";
      }
    }
  }
  cout << endl << "  ";
  for (int i = 0; i < 11; ++i){
    cout << " " << i*10;
  }
}

void callByReference(int &i, char &c){
  i = 786;
  c = 'z';
}
