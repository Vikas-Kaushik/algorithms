#inlcude<iostream>

using namespace std;


int main(){
  while(true){
    cout << "Your Pick : ";
    cin >> pick;
    cout << "Coins = " << coins-=pick;
    pick = ComputerPick(coins);
    cout << endl << "My Pick  : " << pick << endl;
    cout << "Coins = " << coins-=pick << endl;
  }
  return 0;
}

int Nim(int Coins, int pick){
  coint -= pick;
  if(coins == 1)
    return pick;
  if(coins < 1)
    return -1;
  else{
    for(int i = 1; i < 4; ++i){
      return Nim(coins, i);
    }
  }
}
