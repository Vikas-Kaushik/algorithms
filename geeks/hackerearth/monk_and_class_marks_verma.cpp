#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

int main() {
  int count;
  map<int, list<string> > students;
  typedef map<int, list<string> >::const_iterator students_it;
  typedef map<int, list<string> >::const_reverse_iterator rstudents_it;
  typedef list<string>::const_iterator names_it;

  cin >> count;

  while(count--) {
    string name;
    int marks;
    cin >> name >> marks;
    students_it existing = students.find(marks);
    if(existing != students.end()) {
      list<string> l;
      l = existing->second; l.push_back(name); // l.sort();
      students[marks] = l;
    }
    else {
      list<string> l; l.push_back(name);
      students[marks] = l;
    }
  }
  //Displaying
  for(rstudents_it i = students.rbegin(); i != students.rend(); ++i) {
    list<string> l = i->second; l.sort(); //i->second = l;
    int marks = i->first; students[marks] = l;
    //    (list<string>)(i->second).sort();
    for(names_it j = (i->second).begin(); j != (i->second).end(); ++j) { 
    //for(names_it j = (i->second).rbegin(); j != (i->second).rend(); ++j) { 
    //for(names_it j = (i->second).end(); j != (i->second).begin(); --j) { 
      cout << *j << " " << i->first << endl;
    }
  }
  return 0;
}
