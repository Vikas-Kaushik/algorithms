/* problem 29 made easy algo 
print ancestors of a given node
*/
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};
Node* createNode(int data);
bool printAncestors(Node*,int);

int main() {
  Node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  printAncestors(root,4);
  cout << endl;
  printAncestors(root,5);
  cout << endl;
  printAncestors(root,2);
  cout << endl;
  printAncestors(root,3);
  cout << endl;
  printAncestors(root,1);
  cout << endl;
  printAncestors(root,7);
  return 0;
}

Node* createNode(int data) {
  Node* temp = new Node;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

bool printAncestors(Node *root,int data){
  if(!root) {
    return false;
  }
  else if(root->data == data) {
    return true;
  }
  else {
    if(printAncestors(root->left, data)) {
      cout << root->left->data << endl;
      return true;
    }
    else if(printAncestors(root->right,data)){
      cout << root->right->data << endl;
      return true;
    }
    else {
      return false;
    }
  }
}
