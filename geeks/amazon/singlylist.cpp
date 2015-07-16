#include <iostream>
#include <cstdarg>
#include "singlylist.h"

using namespace std;
/*
struct Node{
  int data;
  Node* next;
};
*/

Node* makeList(int count, ...);
void addNode(Node** head, int data);
void deleteList(Node** head);
void displayList(Node *head);

Node* makeList(int count, ...){
  va_list ap;
  Node* head = NULL;
  int var;

  va_start(ap, count);
  for(int i = 0; i < count; ++i){
    var = va_arg(ap, int);
    addNode(&head, var);
  }
  va_end(ap);

  return head;
}


void addNode(Node** head, int data){
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;

  if(*head == NULL){ // list is empty
    *head = newNode;
  }
  else { // list is not empty insert newNode at the end
    Node *current = *head;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
  }
}

void displayList(Node *head){
  cout << "Printing list..." << endl;
  while(head != NULL){
    cout << " -> " << head->data;
    head = head->next;
  }
  cout << endl;
}

void deleteList(Node** head){
  Node *temp;
  while(*head != NULL){
    temp = *head;
    *head = (*head)->next;
    delete(temp);
  }
}
