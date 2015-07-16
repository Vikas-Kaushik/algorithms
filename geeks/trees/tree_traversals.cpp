/*
This file contains different tree traversal implementations
  tree
------ ----
         100                           
        /   \      
      20     500   
     /  \     / \                         
    10  30  300  600      
*/

#include <iostream>
#include <stack> // push pop top size empty
#include <queue> // push pop front back size empty
using namespace std;

struct Node {
  int data;
  Node *left,*right;
};

Node* createNode(int data);
void preOrederTraversal(Node *root);
void inOrderTraversal(Node *root);
void postOrderTraversal(Node *root);
void levelOrderTraversal(Node *root);

int main() {
  Node *root = createNode(100);
  root->left = createNode(20);
  root->left->left = createNode(10);
  root->left->right = createNode(30);
  root->right = createNode(500);
  root->right->left = createNode(300);
  root->right->right = createNode(600);

  preOrederTraversal(root);
  inOrderTraversal(root);
  postOrderTraversal(root);
  levelOrderTraversal(root);

  cout << endl;
  return 0;
}

Node* createNode(int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void preOrederTraversal(Node *root) {
  cout << endl << "Preorder ";
  stack<Node*> s;
  while(true) {
    while(root) {
      s.push(root);
      cout << root->data << " ";
      root = root->left;
    }
    if(s.empty()) break;
    root = s.top();
    s.pop();
    root = root->right;
  }
  cout << endl;
}
void inOrderTraversal(Node *root) {
  cout << endl << "Inorder ";
  stack<Node*> s;
  while(true) {
    while(root) {
      s.push(root);
      root = root->left;
    }
    if(s.empty()) break;
    root = s.top();
    s.pop();
    cout << root->data << " ";
    root = root->right;
  }
  cout << endl;
}

void postOrderTraversal(Node *root) {
  cout << endl << "Postorder ";
  stack<Node*> s;

  while(true) {
    while(root) {
      s.push(root);
      root = root->left;
    }
    if(s.empty()) break;
    root = s.top();
    s.pop();
    if(root->right) { // root->right is not null
      if((!s.empty()) 
	 && s.top() == (root->right)) { // coming back from right
	cout << root->data << " ";
	s.pop();
	root = NULL;
      }
      else { // going right for the first time
	s.push(root->right);
	s.push(root);
	root = root->right;
      }
    }
    else { // root->right is null
      cout << root->data << " ";
      root = NULL;
    }
  }

  cout << endl;
}

void levelOrderTraversal(Node *root) {
  cout << endl << "LevelOrder ";
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    root = q.front();
    q.pop();
    cout << root->data << " ";
    if(root->left)
      q.push(root->left);
    if(root->right)
      q.push(root->right);
  }
  cout << endl;
}
