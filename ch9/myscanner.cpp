#include <iostream>
#include <string>
#include "myscanner.h"

using namespace std;

MyScanner::MyScanner(){
  len = 0;
  cp = 0;
  buffer = "";
  spaceOption = PreserveSpaces;
  //  this.setSpaceOption(PreserveSpaces);
}

MyScanner::~MyScanner(){
  /* Empty */
}

void MyScanner::setInput(string str){
  buffer = str;
  len = str.length();
  cp = -1;
}

bool MyScanner::hasMoreToken(){
  if(cp == -1)
    Error("setInput has not been called");
  if(spaceOptionT == IgnoreSpaces)
    skipSpaces();
  return (cp < len);
}

string MyScanner::nextToken(){
  if(cp == -1)
    Error("setInput has not been called");

  string token = "";
  if(spaceOptionT == IgnoreSpaces)
    skipSpaces();

  if(cp >= len) // returns empty string if there are no tokens left
    return "";

  int start = cp;
  if(isalnum(buffer[cp]){
      int finish = scanToEndOfIdentifier();
      return buffer.substr(start, finish-start+1);
    }
    ++cp;
    return buffer.substr(start, 1);
}

void MyScanner::setSpaceOption(spaceOptionT option){
  spaceOption = option;
}

spaceOptionT MyScanner::getSpaceOption(){
  return spaceOption;
}

void MyScanner::skipSpaces(){
  while(!isaplph(buffer[cp])) && (cp < len)){
    ++cp;
  }
}

int MyScanner::scanToEndOfIdentifier(){
  while((cp < len) && (isalnum(buffer[cp]))){
    ++cp;
  }
  return cp-1;
}
