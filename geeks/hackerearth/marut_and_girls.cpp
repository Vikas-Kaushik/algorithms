/*
 * Hackerearth - bookmyshow - marut and girls problem
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n,m,q; // n:#girls, m:#qualities, q:quality_identifier

  cin >> m;
  // if number of qualities is invalid
  if(m < 0 || m > 100) return 0;

  vector<int> qualities;
  for(int i = 0; i < m; ++i) {
    cin >> q;
    // if quality identifier is invalid
    if(q < 1 || q > 10000) return 0;
    qualities.push_back(q);
  }
  //sort vector of qualities for binary search
  sort(qualities.begin(), qualities.end());

  // for(vector<int>::iterator it = qualities.begin(); 
  //     it <= qualities.end(); ++it) {
  //   cout << *it << " ";
  // }

  cin >> n;
  // if number of girls is invalid
  if(n < 0 || n > 9000) return 0;

  bool allFound[m];
  int count = 0;
  //  cout << endl << "loop times : " << n << endl;
  for(int i = 0; i <= n; ++i) {
    int index = 0;
    for(int j = 0; j < m; ++j) {
      allFound[i] = false;
    }
    vector<int>::iterator it;
    int c = 0;
    while((c = cin.get()) != '\n') {
      q = c - '0';
      //      cout << " " << q << " ";
      if(q >= 1 && q <= 10000) {
	it = find(qualities.begin(),qualities.end(),q);
	if(it != qualities.end()){
	  int index = distance(qualities.begin(),it);
	  allFound[index] = true;
	}
      }
    }
    // if girl is eligible increment count;
    bool eligible = true;
    for(int k = 0; k < m; ++k) {
      if(!allFound[k]) eligible = false;
    }
    if(eligible) ++count;
  }

  cout << count;
  return 0;
}
