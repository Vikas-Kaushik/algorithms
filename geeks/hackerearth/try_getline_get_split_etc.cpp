#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main() {
  size_t testCount;
  cin >> testCount >> ws;
  if(testCount < 0 || testCount > 100) return 0;
  int input;
  while(testCount--) {
    cout << "testCount " << testCount << endl;
    string instr;
    cin >> ws;
    getline(cin,instr);
    istringstream iss(instr);
    while(iss >> input) {
      cout << input << endl;
    }
  }
  return 0;
}
