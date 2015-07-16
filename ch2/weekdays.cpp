// Chapter 2, Exercise 1
// enum to store weekdays

#include <iostream>

using namespace std;

enum weekdayT{sunday, monday, tuesday, wednesday, thursday, friday, saturday};

weekdayT nextDay(weekdayT);
weekdayT previousDay(weekdayT);
weekdayT incrementDay(weekdayT, int);

int main() {
  weekdayT day;
  int i;
  cout << "Enter day # : ";
  cin >> i;
  day = (weekdayT)(i%7);

  cout << "YOur day is : " << day;

  cout << endl << "next      : " << nextDay(day);
  cout << endl << "previous  : " << previousDay(day);
  cout << endl << "Increment : " << incrementDay(day, 10);
  cout << endl << "Increment : " << incrementDay(day, -100);

  cout << endl;
  return 0;
}

weekdayT nextDay(weekdayT day){
  return incrementDay(day, 1);
}
weekdayT previousDay(weekdayT day){
  return incrementDay(day, -1);
}
weekdayT incrementDay(weekdayT day, int delta){
  if (delta < 0) {
    delta = -delta;
    return (weekdayT) (((day - delta) + (delta * 7)) % 7);
  }
  else {
    return (weekdayT) ((day + delta) % 7);
  }
}
