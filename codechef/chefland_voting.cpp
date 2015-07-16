#include <iostream>

using namespace std;

int main(){
  int testCount = 0;
  int chefCount = 0;
  /*
  do {
    cout << "Please enter total number of tests: ";
    cin >> testCount;
  } while(testCount > 0 && testCount <= 500);

  do {
    cout << "Please enter total number of chefs: ";
    cin >> chefCount;
  } while(chefCount > 0 && chefCount <= 50);
  */
  cin >> testCount;
  if(testCount < 0 || testCount > 500){ // valid number of test sets
    cout << -1;
    return 0;
  }

  while(testCount-- > 0){
    cin >> chefCount;
    if(chefCount < 0 && chefCount > 50){ // valid number of chefs
      cout << -1;
      return 0;
    }
    //    char votes[chefCount];
    //    cin.getline(votes);
    char votes[chefCount*2];
    cin.getline(votes, sizeof(votes));
    int *voteCountList = new int[chefCount];
    int j = 0;
    for(int i = 0; i < chefCount; ++i){
      if(votes[j++] != ' '){
	voteCountList[i] = (int)votes[j];
      }
    }

    // check for valid values in  vote count list
    bool isVoteValid = true;
    for(int i = 0; i < chefCount; ++i){
      int count = voteCountList[i];
      if(count < 0 || count >= chefCount){
	cout << -1;
	isVoteValid = false;
	break;
      }
    }

    if(isVoteValid){
      cout << "\ncalculating logic\n";
    }

  } // test set loop

  return 0;

}
