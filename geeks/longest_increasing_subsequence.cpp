/*
 * Finding length of longest increasing subsequence out of an unordered array :-
 * http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
 * https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/LongestIncreasingSubsequence.java
 *
 * lisLength, listLength2, lisLength3 are recursive funtions to get LIS.
 * lisDP is using tabulation (bottom up) to create LIS table.
 */
#include <iostream>
#include <string>
using namespace std;

int lisLength(int arr[], int n);
int _lisLength(int arr[], int n);

int lisLength2(int arr[], int n);
int _lisLength2(int arr[], int n);

int lisLength3(int arr[], int i, int &max_ref);

void lisDP(int *arr, int size);

int main(){
  int arr[] = {3,4,-1,0,6,2,3};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << endl << "length: " << n << endl;
  cout << endl << "LIS is : " << lisLength(arr, n-1) << endl;
  cout << endl << "LIS is (method 2): " << lisLength2(arr,n) << endl;
  int max_ref = 0;
  lisLength3(arr, n-1, max_ref);
  cout << endl << "LIS is (method 3): " << max_ref << endl;

  int arr1[] = {10,22,9,33,21,50,41,60,80};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << endl << "length: " << n1 << endl;
  cout << endl << "LIS is : " << lisLength(arr1, n1-1) << endl;
  cout << endl << "LIS is (method 2): " << lisLength2(arr1,n1) << endl;
  max_ref = 0;
  lisLength3(arr1, n1-1, max_ref);
  cout << endl << "LIS is (method 3): " << max_ref << endl;


  return 0;
}

int lisLength(int arr[], int i){
  int max = 0;
  if(i > 0){
    for(int j = 1; j <= i; ++j){
      int len = 0;
      //cout << j << endl;
      if(arr[j] < arr[i]){
	len = _lisLength(arr, j);
	//cout << "*Length till element " << arr[i] << " is " << len << endl;
      }
      max = (max < len) ? len : max;
    }
  }
  //cout << "returning element " << arr[n-1] << " with length " << max+1 << endl;
  return max+1;
}

int _lisLength(int arr[], int i){
  int max = 0;
  if(i > 0){
    for(int j = 0; j <= i ; ++j){
      //cout << j << endl;
      int len = 0;
      if(arr[j] < arr[i]){
	len = _lisLength(arr, j);
      }
      max = (max < len) ? len : max;
    }
  }
  //cout << "returning element " << arr[n] << " with length " << max+1 << endl;
  return max+1;
}

int lisLength2(int arr[], int n){
  //  int n = sizeof(arr) / sizeof(arr[0]);
  //  cout << "size " << sizeof(arr) << " / " << sizeof(arr[0]) << " = " << n << endl;
  int max = 0;
  for(int i = 0; i < n; ++i){
    int res = _lisLength2(arr, i);
    //  cout << "length till arr[" << i << "] (" << arr[i] << ") is " << res << endl;
    max = (max < res) ? res : max;
  }
  return max;
}

int _lisLength2(int arr[], int i){
  if(i == 0){
    return 1;
  }
  else {
    int max = 1;
    for(int j = 0; j < i; ++j){
      if(arr[j] < arr[i]){
	int res = 1 + _lisLength2(arr,j);
	max = (max < res) ? res : max;
      }
    }
    return max;
  }
}

int lisLength3(int arr[], int i, int &max_ref){
  if(i == 0){
    return 1;
  }
  else {
    int max = 1;
    for(int j = 0; j < i; ++j){
      int res = lisLength3(arr, j, max_ref);   
      if(arr[j] < arr[i]){
	res = res + 1;
	max = (max < res) ? res : max;
      }
      max_ref = (max_ref < res) ? res : max_ref;
    }
    return max;
  }
}

void lisDP(int *arr, int size){
  // here I was planning to display the LIS also. Leaving for later
}
