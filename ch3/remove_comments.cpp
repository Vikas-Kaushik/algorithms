#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int RmCommentsCopyF(ifstream &infile, ofstream &outfile);

int main(){
  ifstream infile;
  ofstream outfile;

  infile.open("/home/dennis/algo/ch3/input_file.txt");
  if(infile.fail())
    cout << endl << "input file opeing failed" << endl;

  outfile.open("/home/dennis/algo/ch3/output_file.txt");
  if(outfile.fail())
    cout << endl << "out file opeing failed" << endl;

  if((RmCommentsCopyF(infile, outfile)) == 0)
    cout << endl << "Copying file1 to file2 is completed" << endl;
  else
    cout << endl << "Copying file1 to file2 failed" << endl;

  infile.close();
  outfile.close();

  return 0;
}

int RmCommentsCopyF(ifstream &infile, ofstream &outfile){
  int ch;
  bool comment_flag = false;
  while((ch = infile.get()) != EOF){
    if(comment_flag){
      if(ch == '*'){
	if((ch = infile.get()) == '/')
	  comment_flag = false;
      }
      else{
	if(ch == '/'){
	  if((ch == infile.get()) == '*')
	    comment_flag = true;
	  else{
	    outfile.put('/');
	    outfile.put(ch);
	  }
	}
      }
    }
  }
  return 0;
}
