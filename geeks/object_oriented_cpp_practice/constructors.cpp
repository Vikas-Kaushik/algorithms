/*
 * This is just to practice different constructor types and other object oriented freatures.
 */
#include <iostream>
#include <string>
using namespace std;

class Base {
private:
  int x, y;
public:
  Base() {
    x = 10;
    y = 11;
  }
  virtual void who() {
    cout << endl << "I am Base class" << endl;
  }
  void printValues() {
    cout << endl << "x and y : " << x << " " << y << endl;
  }
};


class Derived : public Base {
public: 
  void who() {
    cout << endl << "I am Derived class" << endl;
  }
};

int main()
{
  Base *obj = new Derived;
  obj->printValues();
  obj->who();

  return 0;
}
