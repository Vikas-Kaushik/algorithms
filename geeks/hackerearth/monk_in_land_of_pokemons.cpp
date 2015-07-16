/*
 * code monk hashing challenge
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  size_t testCount;
  cin >> testCount;
   	
  if(testCount < 1 || testCount > 10)	return 0;
   		
  while(testCount--)	{
    size_t count = 0;
    size_t n;
    cin >> n;
    if(n < 1 || n > 100000) return 0;
    vector<size_t> food;
    vector<size_t>::iterator it;
    while(n--) {
      size_t a,b;
      bool found = false;
      cin >> a >> b;
      if(a < 1 || a > 1000000 || b < 1 || b > 1000000) return 0;
      food.push_back(a);
      //      food.erase(remove(food.begin(), food.end(), b), food.end());

      it = find(food.begin(), food.end(), b);
      if(it != food.end()) {
	food.erase(it);
      }
      else {
	++count;
      }
      /*
      if(!food.empty()) {
	for(it = food.begin(); it < food.end(); ++it) {
	  cout << *it << " ";
	}
	cout << endl;
	}
      */
 
    }
    cout << count;
  }
}
