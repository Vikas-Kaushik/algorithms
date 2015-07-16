#ifnddef _MAP_H
#define _MAP_H

#include <iostream>
using namespace std;

template <typename ValueType>
class Map{
 public:
  Map();
  ~Map();
  int size();
  bool isEmpty();
  void clear();
  void put(string key, ValueType value);
  ValueType get(string key);
  bool containsKey(string key);
  void remove(string key);

 private:
#include "mappriv.h"
};

#include "mapimpl.cpp"

#endif

/* static const int INITIAL_SIZE = 101; */

/* struct cellT { */
/*   string key; */
/*   ValueType value; */
/*   cellT *link; */
/* }; */

/* cellT **buckets; // a dynamic array of buckets */
/* int nBuckets; // allocated size of the bucket arry */
/* int nEntries; // The number of entries in the map */

/* int hash(string s); */
/* cellT* findCell(cellT *chain, string key); */
/* void deleteChain(cellT *chain); */
