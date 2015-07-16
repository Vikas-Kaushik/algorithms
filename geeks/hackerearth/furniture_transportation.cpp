// This problem was from Urban Ladder on Hacker earth
#include <iostream>
using namespace std;

int main() {
  int n,l,m;
  cin >> n >> l >> m;
  // if l or m or n is invalid
  if((n < 1 || n > 200000)
     || (l < 0 || l > 1000000000)
      || (m < 1 || m > n)) {
    cout << "returning" << endl;
    return 0;
  }

  // take value of n packages
  int *values = new int[n];
  for(int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    // if v is invalid
    if(v < 0 || v > 1000000000) return 0;
    else values[i] = v;
  }

  // count for possible valid groups
  int count = 0;
  // for 0 to last possible index in values array for m sized group
  for(int i = 0; i <= (n-m); ++i) {
    bool check = true;
    for(int j = i; (check && j < (i+m)); ++j) {
      // set flag false if the group value is greater than l
      if(values[j] > l) check = false;
    }
    if(check) ++count;
  }
  cout << count;
  delete values;
  return 0;
}
