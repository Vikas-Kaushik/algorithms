/*
This program gives count of 1's in largest group in a matrix of 0's and 1's.
 */
#include <iostream>

using namespace std;

#define rows 5;
#define cols 5;

int getMaxGroup(int arr[5][5], int m, int n);
int _getMaxGroup(int arr[5][5], int m, int n, int i, int j);

int main(){
  int arr[5][5] = {0,1,0,1,1,
		   0,1,0,0,0,
		   1,0,0,0,1,
		   0,0,0,1,1,
		   1,1,0,0,1,};

  cout << endl << "Size of largest group of 1's : " << getMaxGroup(arr, 5, 5);
  return 0;
}

int getMaxGroup(int arr[5][5], int m, int n){
  int max = 0;
  for(int i = 0; i < m; ++i){
    for(int j = 0; j < n; ++j){
      int temp = _getMaxGroup(arr, m, n, i, j);
      max = (temp > max) ? temp : max;
    }
  }
  return max;
}

int _getMaxGroup(int arr[5][5], int m, int n, int i, int j){
  if(i >= 0 && i < m && j >= 0 && j < n && arr[i][j] == 1){
    arr[i][j] = 0;

    int north = _getMaxGroup(arr, m, n, i-1, j);
    int north_east = _getMaxGroup(arr, m, n, i-1, j+1);
    int east = _getMaxGroup(arr, m, n, i, j+1);
    int south_east = _getMaxGroup(arr, m, n, i+1, j+1);
    int south = _getMaxGroup(arr, m, n, i+1, j);
    int south_west = _getMaxGroup(arr, m, n, i+1, j-1);
    int west = _getMaxGroup(arr, m, n, i, j-1);
    int north_west = _getMaxGroup(arr, m, n, i-1, j-1);

    return 1 + north + north_east + east + south_east 
      + south + south_west + west + north_west;
  }
  return 0;
}
