#include <iostream>
#include <string>
using namespace std;

int main() {
  int testCount;
  cin >> testCount;
  if(testCount < 1 || testCount > 10) {
    cout << "Invalid Test" << endl;
    return 0;
  }
  string instr;
  int smalls,caps;

  while(testCount--) {
    cin >> ws;
    getline(cin,instr);
    int size = instr.length();

    if(size < 1 || size > 100) {
      cout << "Invalid Test" << endl;
      continue;
    }
    else {
      smalls = caps = 0;
      for(int i = 0; i < size; ++i) {
	char ch = instr[i];
	if(ch >= 'A' && ch <= 'Z') {
	  ++caps;
	}
	else if(ch >= 'a' && ch <= 'z') {
	  ++smalls;
	}
	else if(!(ch >= '0' && ch <= '9') ){
	  cout << "Invalid Input" << endl;
	  smalls = -1;
	  break;
	}
      }
      if(smalls == 0 && caps == 0) {
      	cout << "Invalid Input" << endl;
      }
      else if(smalls > 0){
      	cout << ((smalls < caps) ? smalls : caps) << endl;
      }
    }
  }
  return 0;
}


/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int testCount;
    cin >> testCount;
    if(testCount < 1 || testCount > 10) {
    	cout << "Invalid Test" << endl;
    	return 0;    	
    }
    
    int caps,smalls;
    string instr;
    while(testCount--) {
    	cin >> ws;
    	getline(cin,instr);
    	int size = instr.length();
    	if(size < 1 || size > 100) {
    		cout << "Invalid Input" << endl;
    		continue;
    	}
    	else {
	    	caps = smalls = 0;
	    	for(int i = 0; i < size; ++i) {
	    		char ch = instr[i];
	    		if(ch >= 'A' && ch <= 'Z') {
	    			++caps;
	    		}
	    		else if(ch >= 'a' && ch <= 'z') {
	    			++smalls;
	    		}
	    		else if(!(ch >= '0' && ch <= '9')){
	    			cout << "Invalid Input" << endl;
	    			smalls = -1;
	    			break;
	    		}
	    	}
	    	if(smalls == 0 && caps == 0) {
	    		cout << "Invalid Input" << endl;
	    	}
	    	else if(smalls >= 0){
	    		cout << ((smalls < caps) ? smalls : caps) << endl;
	    	}
    	}
    }
    
    return 0;
}

 */


