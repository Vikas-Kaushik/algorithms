#include<iostream>
#include<cstdlib>

#define HEAD_CHANCE 0.5

enum coin{ head, tail};

coin FlipCoin();

using namespace std;

int main(){
  int head_count = 0;
  int toss_count = 0;
  coin side;
  cout << endl << "Flipping coin...." << endl;
  while(head_count <= 3){
    side = FlipCoin();
    ++toss_count;
    switch(side){
    case head : 
      ++head_count;
    default : 
      continue;
    }
  }
  cout << endl << "It took " << toss_count << " tires." << endl;
  return 0;
}

coin FlipCoin(){
  srand(int(time(NULL)));
  double guess = (double)rand()/((double)RAND_MAX+1);

  if(guess < HEAD_CHANCE){
    cout << "It's.... HEAD" << endl;
    return head;
  }
  else {
    cout << "It's.... TAIL" << endl;
    return tail;
  }
}
