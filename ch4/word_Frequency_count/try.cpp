#include <iostream> // cout, cin, 
#include <map> // map type
#include <fstream>  // iftream, 

using namespace std;

void tryMap();
void tryFileInputOutput();

int main(){
  tryMap();
  tryFileInputOutput();
  return 0;
}

/**
 * To try Map functioning
 *------------------------
 */

void tryMap(){
  map <string,int> data;
  data["Hello"] = 2;

  cout << endl << "Searching false data ";
  cout << data["yes"];
  if(!data["kuchbhi"] )
    cout << endl << "data is not found";
  cout << endl << "hello " << data["Hello"] << endl;
}

/**
 * To try file input output
 *------------------------
 */

void tryFileInputOutput(){
  string file, line;
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

  //* Reading file to the cout stream. (i.e. Monitor Screen)
  int ch;
  while((ch = infile.get()) != EOF){
    cout.put(ch);
  }
  infile.clear();

  //* Closing File.
  infile.close();
  if(infile.fail()){
    cout << endl << "Failed closing file." << endl;
    infile.clear();
    return ;
  }

}

