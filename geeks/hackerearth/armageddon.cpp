#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isDigits(const std::string &str);
int survivalTime(string str);

int main() {
  int testCount;
  cin >> testCount;
  // for invalid test count.
  if(testCount < 1 || testCount > 10) {
    //    cout << "invalid test count" << endl;
    return 0;
  }
  while(testCount-- != 0) {
    string str;
    cin >> str;
    // if string length is out of bound and string contains non-numeric value
    size_t len = str.length();
    if(len < 1 || len > 100000 || !isDigits(str)) {
      //      cout << "invalid input" << endl;
      return 0;
    }
    reverse(str.begin(),str.end());
    //cout << str << endl;
    cout << survivalTime(str) << endl;
  }

  return 0;
}

bool isDigits(const string &str) {
  return str.find_first_not_of("0123456789") == string::npos;
}

int survivalTime(string str) {
  size_t len = str.length();
  int minutes = 0;
  for(int i = 1; i < (1<<len); ++i) {
    string str_value;
    for(int j = 0; j < len; ++j) {
      if(i&1<<j) { // if jth bit is set in i
	str_value += str[j];
      }
    }
    //convert the str_value to int_value
    reverse(str_value.begin(),str_value.end());
    char *ch = (char*)str_value.c_str();
    int int_value = atoi(ch);
    //cout << "str,int " << str_value << "," << int_value << endl;
    // check if this combination is divisible by 6
    if(int_value % 6 == 0) {
      //cout << int_value << " ";
      ++minutes;
    }
  }
  return minutes;
}
