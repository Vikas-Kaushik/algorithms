#include<iostream>
#include<cstdlib>

using namespace std;

#define YES 1
#define NO 0
#define START_AMOUNT 50

enum wheelT{
  CHERRY, LEMON, ORANGE, PLUM, BELL, BAR
};

struct windowT{
  wheelT wheel1; 
  wheelT wheel2; 
  wheelT wheel3; 
  double balance;
};

void Play(windowT *player);
wheelT GuessWheel();

int main(){
  int choice = YES;
  char ch;
  windowT *player1 = new windowT;
  player1->balance = START_AMOUNT;
  cout << endl;
  do {
    cout << "You have " << player1->balance << ". Would you like to play ? ";
    // ch = (char)cin.get();
    cin >> ch;
    switch(ch){
    case 'y':
      choice = YES;
      Play(player1);
      break;
    case 'n':
      choice = NO;
      break;
    default :
      choice = YES;
      cout << endl << "Wrong choice !!" << endl;
    }
  }while(choice == YES);
  cout << endl;
  return 0;
}

void Play(windowT *player){
  player->wheel1 = GuessWheel();
  player->wheel2 = GuessWheel();
  player->wheel3 = GuessWheel();
  double pay;
  cout << endl;
  cout << player->wheel1 << " >> " << player->wheel2 << " >> " << player->wheel3 << endl;
  switch(player->wheel1){
  case BAR:
    if(((player->wheel2) == BAR) && ((player->wheel3) == BAR))
      pay = 250;
    break;
  case BELL:
    if(((player->wheel2) == BELL) && (((player->wheel3) == BELL) || ((player->wheel3) == BAR)))
      pay = 20;
    break;
  case PLUM:
    if(((player->wheel2) == PLUM) && (((player->wheel3) == PLUM) || ((player->wheel3) == BAR)))
      pay = 250;
    break;
  case ORANGE:
    if(((player->wheel2) == ORANGE) && (((player->wheel3) == ORANGE) || ((player->wheel3) == BAR)))
      pay = 250;
    break;
  case CHERRY:
    if((player->wheel2) == CHERRY)
      if((player->wheel3) == CHERRY)
	pay = 7;
      else
	pay = 5;
    else
      pay = 2;
    break;
  default:
    pay = -1;
    break;
  }
  (player->balance) += pay;
  cout << endl << "You won : " << pay << endl;
}

wheelT GuessWheel(){
  //  srand(int(time(NULL)));
  int i = rand()%6;
  return wheelT(i);
}
