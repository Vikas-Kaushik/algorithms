#include <iostream>
#include <limits>
using namespace std;

int main() {
  size_t testCount;
  cin >> testCount;

  while(testCount--) {
    int n,m;
    cin >> n >> m;
    // if n or m is invalid
    if(n < 1 || n > 1000 || m < 1 || m > 1000) return 0;
    for(int i = 1; i <= n; ++i) {
      double price = 100;
      double minPrice = numeric_limits<double>::max();
      int minIndex = 0;
      for(int j = 1; j <= m; ++j) {
	for(int k = 1; k <= 3; ++k) {
	  double discount;
	  cin >> discount;
	  // if discount is invalid
	  if(discount < 0 || discount > 100) return 0;
	  price -= (price * discount * 0.01);
	}
	if(minPrice > price) {
	  minPrice = price;
	  minIndex = j;
	}
      }
      cout << minIndex << " ";
    }
    cout << endl;
  }
  return 0;
}
