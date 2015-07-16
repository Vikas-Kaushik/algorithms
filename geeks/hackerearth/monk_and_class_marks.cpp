#include <iostream>
#include <map>
#include <climits>
#include <vector>

using namespace std;

int main() {
  map<string, int> markList;
  int size;
  cin >> size;
  while(size-- != 0) {
    string name;
    int marks;
    cin >> name >> marks;
    markList[name] = marks;
  }

  vector<string> names;
  vector<int> marks;
  map<string, int>::iterator it;
  map<string, int>::iterator itMax;

  while(!markList.empty()) {
    int max = INT_MIN;
    for(it = markList.begin(); it != markList.end(); ++it) {
      if(it->second > max) {
	max = it->second;
	itMax = it;
      }
    }
    names.push_back(itMax->first);
    marks.push_back(itMax->second);
    markList.erase(itMax);
  }

  size = names.size();
  for(int i = 0; i < size; ++i) {
    cout << names[i] << " " << marks[i] << endl;
  }

  return 0;
}

// vector<pair<k,v>> items;
// sort(items.begin(),items.end());
// stable_sort(items.begin(),items.end());
