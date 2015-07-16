#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
  int testCount;
  cin >> testCount >> ws;
  if(testCount < 1 || testCount > 10) {
    cout << "Invalid Test" << endl;
    return 0;
  }
  testCount--;    
  while(testCount--) {
    int caps=0,smalls=0,input;
    string instr;
    cin >> ws;
    getline(cin,instr);
    char *instrc = (char*)instr.c_str();
    int size = instr.length();
    //cout << size << endl;
    if(size < 1 || size > 100) {
      cout << "Invalid Test" << endl;
      continue;
    }
    else {
      for(int i = 0; i < size; ++i) {
	char ch = instrc[i];
	//	cout << ch << " ";
	if(ch >= 'A' && ch <= 'Z') {
	  ++caps;
	}
	else if(ch >= 'a' && ch <= 'z') {
	  ++smalls;
	}
	else if(!(ch >= '0' && ch <= '9') ){
	  cout << "Invalid Input" << endl;
	  break;
	}
      }
      cout << ((smalls < caps) ? smalls : caps) << endl;
    }
  }
  return 0;
}
