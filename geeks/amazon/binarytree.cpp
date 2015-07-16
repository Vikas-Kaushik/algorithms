#include <iostream>
#include <cstdarg>

using namespace std;

Node* add(int data);
Node* makeTree(int count, ...);
// Node* makeTreeByInorder(int count, ...);
// Node* makeTreeByPreorder(int count, ...);
// Node* makeTreeByPostorder(int count, ...);

void traverseInorder(Node*);
void traversePreorder(Node*);
void traversePostorder(Node*);

struct Node{
  int data;
  Node *left;
  Node *right;
}

int main(){
  // Node *root1 = makeTreeByInorder();
  // Node *root2 = makeTreeByPreorder();
  // Node *root3 = makeTreeByPostorder();

  traverseInorder(root1);
  traversePreorder(root2);
  traversePostorder(root3);

  return 0;
}

Node* makeTree(int count, ...){
  int arr[count];
  va_list vl;

  va_start(vl,count);
  for(int i = 0; i < count; ++i){
    arr[i] = va_arg(vl, int);

  }
  va_end(vl);
} 

void traverseInorder(Node*);
void traversePreorder(Node*);
void traversePostorder(Node*);
