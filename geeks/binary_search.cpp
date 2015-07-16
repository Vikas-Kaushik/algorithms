#include<iostream>

using namespace std;

int binSearch(int arr[], int x);
int binSearch_Wrapper(int arr[],int x,int start,int last);

int main(){

  int arr[] = {1,2,3,4,5,6,7,8,9};
  int n = sizeof(arr)/ sizeof(arr[0]);  
  cout << endl << "binSearch called size = " << n;

  int x = 3;
  int y = binSearch(arr, x);
  cout << endl << x << " found at position : " << y;
  cout << endl;

  x = 3;
  y = binSearch(arr, x);
  cout << endl << x << " found at position : " << y;
  cout << endl;

  x = 7;
  y = binSearch(arr, x);
  cout << endl << x << " found at position : " << y;

  x = 5;
  y = binSearch(arr, x);
  cout << endl << x << " found at position : " << y;
  cout << endl;

  x = 13;
  y = binSearch(arr, x);
  cout << endl << x << " found at position : " << y;
  cout << endl;

  cout << endl;
  return 0;
}

int binSearch(int arr[], int x){
  int start = 0;
  int n = sizeof(arr)/ sizeof(arr[0]);  
  cout << endl << "binSearch called size = " << n;
  int last = n-1;
  return binSearch_Wrapper(arr,x,start,last);
}

int binSearch_Wrapper(int arr[],int x,int start,int last){

  int mid = (start + last) / 2;

  cout << endl << start << " - " << mid << " - " << last;

  if(start >= last){
    return -1;
  }
  else if(arr[mid] == x){
    return mid;
  }
  else if(arr[mid] > x){
    return binSearch_Wrapper(arr, x, start, mid-1);
  }
  else if(arr[mid] < x){
    return binSearch_Wrapper(arr, x, mid+1, last);
  }
}
