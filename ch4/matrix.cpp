#include<iostream>
#include<gnettech
nettemnnnsdkflksdfnettech
ng namespace std;

int main(){
  Grid<int> matrix(3,3);

  cout << endl << "Matrix is here...";
  for(int i = 0; i < matrix.numRows(); ++i){
    for(int j = 0; j < matrix.numCols(); ++j){
      matrix[i][j] = i;
    }
  }

  for(int i = 0; i < matrix.numRows(); ++i){
    for(int j = 0; j < matrix.numCols(); ++j){
      cout << endl << "matrix = " << i;
    }
  }

  return 0;
}
