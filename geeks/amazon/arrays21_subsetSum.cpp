#include <iostream>
#include <iomanip>

using namespace std;

void printSubsetSumZero(int arr[],int n);
void printTable(int* t, int rows, int cols);
//void printTable(int rows, int cols, int t[rows][]);

int main(){
  int arr[] = {-1,0,1,2,2,-1,-1,10,-2};
  int n = sizeof(arr) / sizeof(int);
  for(int i = 0; i < n; ++i){
    cout << arr[i] << ", ";
  }
  cout << endl;

  cout << "Size : " << n << endl;
  printSubsetSumZero(arr, n);
  return 0;
}

void printSubsetSumZero(int arr[], int n){
  cout << "Printing array subsets with sum = 0" << endl;
  int t[n][n+1];

  for(int i = 0; i < n; ++i){
    for(int j = 1; j <= n; ++j){
      t[i][j] = NULL;
    }
  }

  // set all rows in first column as zero
  for(int i = 0; i < n; ++i){
    t[i][0] = 0;
  }
  printTable((int*)t,n,n+1);

  // fill up the table
  for(int i = 0; i < n; ++i){
    for(int j = (i+1); j <= n; ++j){
      t[i][j] = t[i][j-1] + arr[j-1];
      // if sum is zero then print elements from i to j
      if(t[i][j] == 0){
	cout << endl;
	for(int k = i; k < j; ++k){
	  cout << arr[k] << ", ";
	}
      }
    }
  }
  cout << endl;
  printTable((int*)t,n,n+1);
}

void printTable(int* t, int rows, int cols){
  cout << endl;
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      cout << setw(2) << *((t+i*cols)+j) << ", ";
    }
    cout << endl;
  }
  cout << endl;
}
