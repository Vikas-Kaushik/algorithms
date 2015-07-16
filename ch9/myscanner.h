/*
 * File: MyScanner.h
 * ------------------
 * Usage:
 * MyScanner scanner;
 * scanner.setInput(inputString);
 * scanner.setSpaceOption(spaceOptionT);
 * while(scanner.hasMoteToken()){
 *      string token = scanner.nextToken();
 *      // -- process token ---- 
 * }
 */


#ifndef _myscanner_h
#define _myscanner_h

#include <iostream>
#include <string>

using namespace std;

class MyScanner{
  //Public section
 public:

  //Constructor
  MyScanner();

  //Destructor
  ~MyScanner();

  //setInput method to link with source buffer
  void setInput(string str);

  //hasMoreToken method
  bool hasMoreToken();

  //get next token method
  string nextToken();

  enum spaceOptionT{ PreserveSpaces, IgnoreSpaces};

  void setSpaceOption(spaceOptionT option);

  spaceOptionT getSpaceOption();

  //private section
 private:

#include "myscpriv.h"

};

#endif
