#ifndef _MAPPRIV_H
#define _MAPPRIV_H

static const int INITIAL_SIZE = 101;

struct cellT {
  string key;
  ValueType value;
  cellT *link;
};

cellT **buckets; // a dynamic array of buckets
int nBuckets; // allocated size of the bucket arry
int nEntries; // The number of entries in the map

int hash(string s);
cellT* findCell(cellT *chain, string key);
void deleteChain(cellT *chain);

#endif
