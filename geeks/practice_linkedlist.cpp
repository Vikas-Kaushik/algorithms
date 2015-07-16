#include <iostream>

using namespace std;

struct Node{
  int data;
  Node* next;
};

void addNode(Node** head, int index, int data);
void deleteNode(Node** head, int index);
void deleteList(Node** head);
void displayList(Node* head);

int main(){
  Node* head = new Node;
  addNode(&head, 0, 99);
  addNode(&head, 1, 78);
  addNode(&head, 2, 34);
  displayList(head);
  deleteList(&head);
  return 0;
}

void addNode(Node** head, int index, int data){
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;

  if(index == 0){
    head = &newNode;
  }
}
void deleteNode(Node** head, int index);
void deleteList(Node** head);
void displayList(Node* head);
