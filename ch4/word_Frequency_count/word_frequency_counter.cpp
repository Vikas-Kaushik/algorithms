/**
 * File: word_frequency_counter.cpp
 * --------------------
 * This program reads a file and displays the distinct
 * words with individual counts.
 */

#include<iostream>
#include<string>
#include<iomanip>
#include<map>
#include<iterator>
#include<fstream>
#include<tokenscanner.h>

using namespace std;

/* Private Function Prototype */

void DisplayMessage();
void ProcessTask(map <string,int> &data);
void DisplayWordList(map <string,int> &data);

/* Main Function */

int main(){
  DisplayMessage();
  map <string,int> data;
  ProcessTask(data);
  DisplayWordList(data);
  return 0;
}

/*
 void DisplayMessage(); -- Displays introductory message.
 string GetFileName(); -- Gets the file name from user.
 void ProcessTask(map <string,int> &data); -- Main processing i.e. counting word frequencies and getting new words.
 void DisplayWordList(map <string,int> &data); -- Displays the recorded frequencies in map i.e. word list.
*/

void DisplayMessage(){
  cout << endl << "This program displays the distinct word frequencies in a file.";
}

void ProcessTask(map <string,int> &data){
  string  file;
  ifstream infile;

  cout << endl << "Enter file name : ";
  cin >> file;

  //* Opening File.
  infile.open(file.c_str());
  if(infile.fail()){
    cout << endl << "Failed opening file." << endl;
    infile.clear();
    return ;
  }

  TokenScanner scanner(infile);
  scanner.ignoreWhitespace();
  while(scanner.hasMoreTokens()){
    string token = scanner.nextToken();
    if(!data[token])
      data[token] = 1;
    else 
      ++data[token];
  }
  //* Closing File.
  infile.close();
  if(infile.fail()){
    cout << endl << "Failed closing file." << endl;
    infile.clear();
    return ;
  }
  }

  /**  Scanner fileScan;
  fileScan.setSpaceOption(Scanner::IgnoreSpace);
  fileScan.setNumberOption(Scanner::ScanNumbersAsLetters);
  fileScan.setInput(file);

  while(fileScan.hasMoreTokens()){
    word = fileScan.nextToken();
    if(data.containsKey(word)){
      count = data.get(word);
      data.put(word, ++count);
    }
    else {
      data.put(word, 1);
    }
    }*/


void DisplayWordList(map <string,int> &data){
  string word;
  int count;
  map<string,int>::iterator iter;

  cout << endl << setw(15) << "Word" << "  Frequency" << endl;
  for(iter = data.begin(); iter != data.end(); ++iter){
    word = iter->first;
    count = iter->second;
    cout << setw(15) << word;
    cout << setw(5) << count << endl;
  }
}
