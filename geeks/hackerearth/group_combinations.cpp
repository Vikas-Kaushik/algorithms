/*
 * This problem was in Hackerearth July Easy challenge
 */

#include <iostream>
using namespace std;

int countCombinations(int n, int k);

int main() {
  int n,k;
  cout << "Total elements: ";
  cin >> n;
  cout << "Min. elements in a group: ";
  cin >> k;
  cout << endl << countCombinations(n,k) << endl;
  return 0;
}

int countCombinations(int n, int k) {
  int t = n/k;
  int count = 1;
  for(int i = 1; i <= t; ++i) {
    int n1 = n - k*i;
    int k1 = k;
    while(n1 >= k1) {
      --n1; ++k1; ++count;
    }
  }
  return count;
}
