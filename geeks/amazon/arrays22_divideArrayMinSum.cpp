/*
  Original Array = {0,1,2,2,4,5,9,10,11,13}
  And answer should be
  A1 = {2,2,5,9,10}
  A2 = {0,1,4,11,13}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define MIN(x, y) ( (x < y) ? x : y)
#define ABS(x) ((x < 0) ? (-1*x) : x)
using namespace std;
/*
void divideWithMinDiff(int *arr, int size);

int main(){
  int arr[] = {0,1,2,2,4,5,9,10,11,13};
  int size = sizeof(arr) / sizeof(int);
  for(int i = 0; i < size; ++i){
    cout << arr[i] << ", ";
  }
  cout << endl;

  sort(arr, arr+size);
  for(int i = 0; i < size; ++i){
    cout << arr[i] << ", ";
  }
  cout << endl;

  divideWithMinDiff(arr, size);
  return 0;
}

void divideWithMinDiff(int *arr, int size){
  int first,last,sumfirst,sumlast;
  vector<int> arr1, arr2;
  first = 0;
  last = size-1;

  sumfirst = arr[first];
  sumlast = arr[last];
  arr1.push_back(arr[first]);
  arr2.push_back(arr[last]);
  ++first; --last;

  while(first < last){
    while(first < size && sumfirst <= sumlast && first < last){
      sumfirst += arr[first];
      arr1.push_back(arr[first]);
      ++first;
    }
    while(last >= 0 && sumlast <= sumfirst && first < last){
      sumlast += arr[last];
      arr2.push_back(arr[last]);
      --last;
    } 
  }
  cout << endl << "arr1 : ";
  for(int i = 0; i < arr1.size(); ++i){
    cout << arr1[i] << ", ";
  }
  cout << endl << "arr2 : ";
  for(int i = 0; i < arr2.size(); ++i){
    cout << arr2[i] << ", ";
  }
}
*/

int abs(int x) {
  return ((x < 0) ? (-1*x) : x);
}

int divide(vector<int> a, int i, int X, int Y) {
  if(i >= a.size()) {
    return abs(X-Y);
  } else {
    int x1 = divide(a, i+1, X+a[i], Y);
    int x2 = divide(a, i+1, X, Y+a[i]);
    return min(x1, x2);
  }
}

int main() {
  int N;
  scanf("%d", &N);
  vector<int> a;
  int N_ = N;
  while(N_--) {
    int x; 
    scanf("%d", &x);
    a.push_back(x);
  } 
  printf("Min diff : %d\n", divide(a, 0, 0, 0));
}
