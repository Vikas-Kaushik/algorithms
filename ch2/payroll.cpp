// chapter 2, exercise 12
// implementing payroll record structure

#include <iostream>
using namespace std;

struct employeeT {
  string name;
  string title;
  string ssnum;
  double salary;
  int withholding;
};

struct payrollT {
  int empcount; // employee count
  employeeT *empList; // employee list os employeeT type
};

void displayPayroll(payrollT*);

int main(){
  payrollT *p = new payrollT;
  p->empcount = 2;
  p->empList = new employeeT[2];
  p->empList[0].name = "Sinki";

  displayPayroll(p);
  return 0;
}

void displayPayroll(payrollT* p){
  cout << endl << p->empcount;
  cout << endl << p->empList[0].name;
  cout << endl << p->empList[0].title;
  cout << endl << p->empList[0].salary;
  cout << endl;
} 
