/*
 * July easy
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(n < 1 || n > 1000) {
    return 0;
  }

  vector<int> zombies;
  vector<int> vamps;

  for(int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    if(k < 1 || k > 1000) {
      return 0;
    }
    else if(k%2 == 0) {
      zombies.push_back(k);
    }
    else {
      vamps.push_back(k);
    }
  }

  sort(zombies.begin(),zombies.end());
  sort(vamps.begin(),vamps.end());

  vector<int>::iterator it;
  int total = 0;
  for(it = zombies.begin(); it != zombies.end(); ++it) {
    total += *it;
    cout << *it << " ";
  }
  cout << total << " ";
  total = 0;

  for(it = vamps.begin(); it != vamps.end(); ++it) {
    total += *it;
    cout << *it << " ";
  }
  cout << total;

  return 0;
}
