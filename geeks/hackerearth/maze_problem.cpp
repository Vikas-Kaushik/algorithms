#include <iostream>

using namespace std;

bool check(int** arry, int size, int i, int j);
void printArray(int** arry, int size);

int main() {
  int testCount;
  cin >> testCount;
  while(testCount-- != 0) {
    int n;
    cin >> n;
    int** arry = new int*[n];
    for(int i = 0; i < n; ++i) {
      arry[i] = new int[n];
      for(int j = 0; j < n; ++j) {
	cin >> arry[i][j];
      }
    }
    //    printArray(arry,n);

    if(check(arry,n,0,0)) {
      cout << "POSSIBLE" << endl;
    }
    else {
      cout << "NOT POSSIBLE" << endl;
    }
  }
  return 0;
}

bool check(int** arry, int size, int i, int j) {
  if(i == size-1 && j == size-1) {
    return true;
  }
  if(i <= size-1 && j <= size-1) {
    if((arry[i][j] == 1)
       && (check(arry, size, i, j+1) || check(arry, size, i+1, j))
       ) {
      return true;
    }
    else {
      return false;
    }
  }
  return false;
}

void printArray(int** arry, int n) {
  for(int i = 0; i < n; ++i) {
    cout << endl;
    for(int j = 0; j < n; ++j) {
      cout << arry[i][j] << " ";
    }
  }
  cout << endl;
}
