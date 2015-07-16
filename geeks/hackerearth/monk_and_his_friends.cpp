#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int testCount;
  cin >> testCount;

  while(testCount-- != 0) {
    int N, M;
    cin >> N;
    cin >> M;

    vector<int> listN;
    while(N-- != 0) {
      int i;
      cin >> i;
      listN.push_back(i); 
    }
    //sort list
    sort(listN.begin(), listN.end());

    while(M-- != 0) {
      int i;
      cin >> i;
      if(binary_search(listN.begin(), listN.end(), i)) {
	cout << "YES" << endl;
	
	vector<int>::iterator it;
	it = find (listN.begin(), listN.end(), i);
	if (it != listN.end())
	  listN.erase(it);
      }
      else {
	cout << "NO" << endl;
      }
    }
  }
  return 0;
}

