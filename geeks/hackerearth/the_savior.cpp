/*
 * July Easy
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int testCount;
  cin >> testCount;
  if(testCount < 1 || testCount > 50) {
    return 0;
  }
  while(testCount-- != 0) {
    int n;
    cin >> n;
    if(n < 0 || n > 1000) {
      return 0;
    }
    vector<size_t> list;
    for(int i = 0; i < n; ++i) {
      size_t k;
      cin >> k;
      if(k < 0 || k > 100000)
	return 0;
      list.push_back(k);
    }
    sort(list.begin(),list.end());
    int count = 0;
    for(int i = 0; i < (list.size()-1); ++i) {
      for(int j = i+1; j < list.size(); ++j) {
	if(list[i] != list[j] && (list[i] + list[j])%2 == 0)
	  ++count;
      }
    }
    cout << count << endl;
    list.clear();
  }
  return 0;
}
