/*
 * Longest common subsequence
 * printing lcs is incomplete, need to relook it, lcs array is not been made properly.
 */

#include <iostream>
#include <string>

using namespace std;

int lcsTable(char *x, char *y, int m, int n);
//void printLcs(int m, int n, int c[m][n]);
//void printLcs(int m, int n, int c[][n]);
//void printLcs(int m, int n, int *c[]);
void printLcs(int m, int n, void *c, char *x, char *y);

int main(){
  char x[] = "abcbdab";
  char y[] = "bdcaba";
  int m = sizeof(x) / sizeof(x[0]);
  int n = sizeof(y) / sizeof(y[0]);
  cout << m << "  " << n << endl;
  cout << "LCS length: " << lcsTable(x, y, m-1, n-1) << endl;
  return 0;
}

int lcsTable(char *x, char *y, int m, int n){
  int c[m+1][n+1];
  for(int i = 0; i <= m; ++i) {
    for(int j = 0; j <= n; ++j) {
      if(i == 0 || j == 0){
	c[i][j] = 0;
      }
      else if(x[i-1] == y[j-1]) {
	c[i][j] = 1 + c[i-1][j-1];
      }
      else {
	c[i][j] = (c[i][j-1] > c[i-1][j]) ? c[i][j-1] : c[i-1][j];
      }
      //      cout << "c(" << i << "," << j << ") = " << c[i][j] << endl;
    }
  }
  for(int l = 0; l <= m; ++l){
    for(int p = 0; p <= n; ++p){
      cout << c[l][p] << "  ";
    }
    cout << endl;
  }
  cout << endl;

  int i = m;
  int j = n;
  while(i >= 0 && j >= 0){
    if(x[i] == y[j]){
      cout << x[i];
      --i; --j;
    }
    else {
      if(c[i][j] == c[i][j-1])
	--j;
      else if(c[i][j] == c[i-1][j])
	--i;
    }
  }
  cout << endl;
  //  printLcs(m,n,c,x,y);
  return c[m][n];
}

//void printLcs(int m, int n, int c[m][n]){
//void printLcs(int m, int n, int c[][n]){
//void printLcs(int m, int n, int *c[]){
void printLcs(int m, int n, void *c, char *x, char *y ){
  int (*arr)[n] = static_cast<int (*)[n]>(c);
  int i = m;
  int j = n;
  for(int l = 0; l <= m; ++l){
    for(int p = 0; p <= n; ++p){
      cout << arr[l][p] << "  ";
    }
    cout << endl;
  }

  while(i > 0 && j > 0){
    if(x[i] == y[j]){
      cout << x[i];
      --i; --j;
    }
    else {
      if(arr[i][j] == arr[i][j-1])
	--j;
      else if(arr[i][j] == arr[i-1][j])
	--i;
    }
  }
  cout << endl << "lcs done" << endl;
}
