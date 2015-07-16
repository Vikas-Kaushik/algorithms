#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int testCount;
  cin >> testCount;
  while(testCount-- != 0) {
    vector<string> lexicon;
    int size;
    cin >> size;
    while(size-- != 0) {
      string name;
      cin >> name;
      lexicon.push_back(name);
    }

    sort(lexicon.begin(),lexicon.end());

    vector<string>::iterator it;
    string prev = "";
    for (it = lexicon.begin(); it != lexicon.end(); ++it) {
      if(prev == *it) {
	lexicon.erase(it);
      }
      else {
	prev = *it;
	cout << *it << endl;
      }
    }
  }
  return 0;
}
