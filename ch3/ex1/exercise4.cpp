#include<iostream>
#include<cctype>

using namespace std;

bool EqualIgnoringCase(string str1, string str2);

int main(){
  string str1 = "string";
  string str2 = "StrinG";
  cout << endl;

  if(EqualIgnoringCase(str1, str2))
    cout << "Strings are matching...";
  else
    cout << "Strings are not matching....";

  cout << endl;
  return 0;
}

bool EqualIgnoringCase(string str1, string str2){
  int l1 = str1.length();
  int l2 = str2.length();
  char s1,s2;
  cout << endl;

  if(l1 != l2)
    return false;
  cout << "Length matched...";
  for(int i = 0; i < l1; ++i){
    s1 = toupper(str1[i]);
    s2 = toupper(str2[i]);
    if(s1 != s2)
	return false;
    else
      cout << endl << "char #" << i << " matched....";
  }
  return true;
}
