/* 
 * Detecting largest group of 1's in a 2d binary matrix.
 * Problem 5 of Kurumanchi
 */

#include <iostream>

using namespace std;

int fn(int arr[5][5], int I, int J);
int _fn(int arr[5][5], int I, int J, int i, int j);

int main(){
  int arr[][5] = { {1,1,0,0,0},
		  {0,1,1,0,0},
		  {0,0,1,0,1},
		  {1,0,0,0,1},
		  {0,1,0,1,1}, };
  int I, J;
  I = J = 5;

  cout << "Count of 1's in largest group = " << fn(arr, I, J) << endl;
  return 0;
}

int fn(int arr[5][5], int I, int J){
  int max = 0;
  if(I < 1 || J < 1){
    return max;
  }
  for(int i = 0; i < I; ++i){
    for(int j = 0; j < J; ++j){
      if(arr[i][j] < 1){
	int temp = _fn(arr, I, J, i, j);
	max = (max < temp)? temp: max;
      }
    }
  }
  return max;
}
int _fn(int arr[5][5], int I, int J, int i, int j){
  int max = 0;
  if(i > 0 && j > 0 && i < I && j < J && arr[i][j] >= 1){
    int temp;

    temp = _fn(arr, I, J, i-1, j);
    max = (max < temp)? temp: max;

    temp = _fn(arr, I, J, i-1, j+1);
    max = (max < temp)? temp: max;

    temp = _fn(arr, I, J, i, j+1);
    max = (max < temp)? temp: max;

    temp = _fn(arr, I, J, i+1, j+1);
    max = (max < temp)? temp: max;

    temp = _fn(arr, I, J, i+1, j);
    max = (max < temp)? temp: max;

    temp = _fn(arr, I, J, i+1, j-1);
    max = (max < temp)? temp: max;

    temp = _fn(arr, I, J, i, j-1);
    max = (max < temp)? temp: max;

    temp = _fn(arr, I, J, i-1, j-1);
    max = (max < temp)? temp: max;

    ++max;
  }
  return max;
}
