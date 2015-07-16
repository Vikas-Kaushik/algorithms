#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

string GetInputFileName();
void ReadFile(ifstream &infile, vector<string> &file_lines);
void PrintReverseFile(vector<string> &file_lines);

int main(){
  string file_name;
  ifstream infile;
  vector<string> file_lines;

  //  file_name = GetInputFileName();

  //  cout << endl << "-----" << file_name.c_str();
  //  infile.open(file_name.c_str());
  infile.open("file.txt");
  ReadFile( infile, file_lines);
  if(infile.fail()){
    cout << endl << "Can't open file.." << endl;
    infile.clear();
  }
  infile.close();

  PrintReverseFile(file_lines);
  return 0;
}


string GetInputFileName(){
  string file_name;
  cout << endl << "Please enter full file name : ";
  //  string file_name = cin.getline()d;
  getline(cin, file_name);
  cout << endl << "Entered file name is : " << file_name;
  return file_name;
}

void ReadFile(ifstream &infile, vector<string> &file_lines){
  string line;
  int i = 0;
  while(!infile.eof()){
    getline(infile, line);
    if(infile.fail()) break;
    file_lines[++i] = line;
    cout << endl << file_lines[i-1];
  }

  cout << endl << "Your File has been read in my vector." << endl;
}

void PrintReverseFile(vector<string> &file_lines){
  for(int i = (file_lines.size() - 1); i >= 0; --i){
    cout << endl << file_lines[i];
  }
}
