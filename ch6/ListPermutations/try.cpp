#include <iostream>
//#include <string>

using namespace std;

bool findCharInString(char ch, string prefix);

int main(){
  string str;
  int count = 2;  // count is the number of initial characters in string that user don't want to permute.
  cout << endl << "Please enter string : ";
  cin >> str;

  cout << "Printing permutations of last " << count << " chars..." << endl;

  int l = str.length();
  cout << str.substr(0) << endl;
  cout << str.substr(0, l) << endl;
  cout << str.substr(0, 0) << endl;
  //cout << str.substr(l+1) << endl;

  if(-1)
    cout << "minus one in if" << endl;
  if(0)
    cout << "zero in if" << endl;
  if(!0)
    cout << "!0 in if" << endl;
  if(1)
    cout << "one in if" << endl;
  cout << str.find("x") << endl;
  cout << str.find('x') << endl;
  cout << str.find("w") << endl;
  if(str.find("x"))
    cout << "x char not found in your string" << endl;

  str = "";
  cout << "Length of a blank string = " << str.length() << endl;
  cout << findCharInString('x', str) << endl;
  cout << "Entering loop enter char q in char to quit" << endl;
  char ch;
do
    cout << "Enter String : " ;
    cin >> str;
    cout << "Enter char to search in String : ";
    cin >> ch;
    if(findCharInString(ch, str))
      cout << "Char found at" << findCharInString(ch, str) <<endl;
    else 
      cout << "Char not found" << endl;
  } while(ch != 'q');
  return 0;
}

bool findCharInString(char ch, string prefix){
      int check = prefix.find(ch);
      if(prefix == "")
	return false;

      int l = prefix.length();

      if( (check > 0) || (check < l) )
	return true;
      else 
	return false;
}
