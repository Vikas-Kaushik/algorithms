#include<iostream>
#include"random.h"

using namespace std;

int ThrowDice();
bool TryToMakePoints(int points);

int main(){
  int point = ThrowDice();

  cout << endl;
  switch(point){
  case 7: case 11:
    cout << "You won with a natural !!";
    break;
  case 2: case 3: case 12:
    cout << "Thats craps.. You loose !!";
    break;
  default:
    cout << "Your total points are : " << point;
  if(TryToMakePoints(point))
    cout << endl << "You made your points. You win";
  else
    cout << endl << "You didn't make your points. You loose";
  break;
    }
  cout << endl;
}

int ThrowDice(){
  int point;
  cout << endl;
  cout << "Throwing two dices... ";
  Randomize();
  point =   RandomInteger(1, 6);
  point += RandomInteger(1,6);
  cout << "You rolled total points : " << point;
  cout << endl;
}

bool TryToMakePoints(int points){
  int new_points = ThrowDice();
  while(true){
    if(new_points == points)
      return true;
    else if(new_points == 7)
      return false;
    else 
      continue;
  }
}
