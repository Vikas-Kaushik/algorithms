/*
 * This program is to get kth minimum element of kth maximum element
 * from a Binary Search Tree(BST). 
 */

#include <iostream>
#include <stack>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node* createNode(int data);
void printInorder(Node *root);
int minNode(Node *root, int k = 1);
int maxNode(Node *root, int k = 1);

int main(){
  Node *root = createNode(15);
  root->left = createNode(10);
  root->left->left = createNode(8);
  root->left->right = createNode(12);
  root->right = createNode(20);
  root->right->left = createNode(16);
  root->right->right = createNode(25);

  printInorder(root);

  cout << endl << "Min. Node is : " << minNode(root);
  cout << endl << "3rd Min. Node is : " << minNode(root, 3);
  cout << endl << "5th Min. Node is : " << minNode(root, 5);

  cout << endl;
  cout << endl << "Max. Node is : " << maxNode(root);
  cout << endl << "3rd Max. Node is : " << maxNode(root, 3);
  cout << endl << "5th Max. Node is : " << maxNode(root, 5);

  return 0;
}

Node* createNode(int data){
  Node *newNode = new Node();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

int minNode(Node *root, int k){
  stack<Node*> s;
  int count = 1;
  int data = -1; 
  while(count <= k){
    while(root != NULL){
      s.push(root);
      root = root->left;
    }
    if(s.empty()){
      break;
    }
    root = s.top();
    s.pop();
    //    cout << endl << root->data;
    if(count == k){
      data = root->data;
    }
    ++count;
    root = root->right;
  } 
  return data;
}
int maxNode(Node *root, int k){
  stack<Node*> s;
  int count = 1;
  int data = -1;
  while(count <= k){
    while(root != NULL){
      s.push(root);
      root = root->right;
    }
    if(s.empty()){
      break;
    }
    root = s.top();
    s.pop();
    if(count == k){
      data = root->data;
    }
    ++count;
    root = root->left;
  }
  return data;
}

void printInorder(Node *root){
  stack<Node*> s;
  while(true){
    while(root != NULL){
      s.push(root);
      root = root->left;
    }
    if(s.empty()){
      break;
    }
    root = s.top();
    s.pop();
    cout << endl << root->data;
    root = root->right;
  } 
  cout << endl;
}
