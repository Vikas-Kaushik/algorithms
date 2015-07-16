/*
 * July Easy
 */

#include <iostream>
using namespace std;
int countGroups(int n, int k);

int main() {
  int testCount;
  cin >> testCount;
  if(testCount < 1 || testCount > 30) {
    return 0;
  }
  while(testCount-- != 0) {
    int n,k;
    cin >> n >> k;
    if(n < 0 || k < 0 || n > 200 || k > 200) {
      return 0;
    }
    cout << countGroups(n,k) << endl;
  }
  return 0;
}

int countGroups(int n, int k) {
  if(n < k) {
    return 0;
  }
  else if (n == k) {
    return 1;
  }
  else {
    // working on this part
    return n-k;
  }
}
