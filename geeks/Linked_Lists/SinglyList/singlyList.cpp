#include <iostream>
#include "singlyList.h"

using namespace std;

// add a new node in list provided data and index position.
void addNode(Node** head_ref, int data, unsigned int index){
  unsigned int l = countNodes(*head_ref);

  // if index is 0 or less. OR list is empty
  if( index <= 0 || l == 0){
    push(head_ref, data);
  }
  // if index given is more than or equal to last index
  else if(index >= --l){
    append(head_ref, data);
  }
  // else case here will get index either greater than 0 or less than l-1 
  else {
    Node* current = *head_ref;
    while(index > 1){
      current = current->next;
      --index;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
  }
}

// append a new node at the end of list.
void append(Node** head_ref, int data){
  Node* newNode = new Node;
  newNode->next = NULL;
  newNode->data = data;

  // if list is empty 
  if((*head_ref) == NULL){
    *head_ref = newNode;
  }
  else {
    Node* current = (*head_ref);
    // loop till you get the last node 
    while(current->next != NULL){
      current = current->next;
    }
    // append new node as the next node of last node 
    current->next = newNode;
  }
}

// push a new node at the beginning of list.
void push(Node** head_ref, int data){
  Node* newNode = new Node;
  newNode->next = (*head_ref);
  newNode->data = data;
  *head_ref = newNode;
}

// delete a node provided data of node. First occurence of data is deleted.
void deleteNode(Node** head_ref, int data){
  // if list is empty 
  if((*head_ref) == NULL){
    cout << "List is empty." << endl;
  }
  else{
    Node* current = (*head_ref);

    // if first node is to be deleted 
    if(current->data == data){
      *head_ref = current->next;
      delete current;
    }
    else {
      Node* prev = NULL;
      current = *head_ref;
      // note in following while condition (current != NULL) check has been
      // put first. This is very important. Otherwise next check
      // "current->data" will result in segmentation fault. As current is
      // null.
      while( (current != NULL) && (current->data != data) ){
	prev = current;
	current = current->next;
      }
      // if current is null then all list had been traversed. 
      if(current == NULL){
	cout << "data to be deleted not found." << endl;
      }
      else {
	// skip and delete the current node. 
	prev->next = current->next;
	delete current;
      }
    }
  }
}

// empty or delete the whole list.
void deleteList(Node** head_ref){
  // if list is empty 
  if((*head_ref) == NULL){
    cout << "List is empty." << endl;
  }
  else{
    Node* current = (*head_ref);
    // make head_ref pointing to NULL i.e. no list 
    *head_ref = NULL;

    while(current != NULL){
      Node* temp = current;
      current = current->next;
      delete temp;
    }
  }
}

// Traverse and display list.
void displayList(Node *head){
  cout << endl << "Your list is : ";
  if( head == NULL)
    cout << "empty";
  while(head != NULL){
    cout << " -> " << head->data;
    head = head->next;
  }
  cout << endl;
}

// counts the number of nodes the list.
unsigned int countNodes(Node* head){
  int count = 0;
  while(head != NULL){
    ++count;
    head = head->next;
  }
  return count;
}

// Returns the node data in the list provided index
int getNode(Node* head, int index){

  while(index > 0 && head != NULL){
    head = head->next;
    --index;
  }
  // if list is empty or index not found
  if(head == NULL){
    cout << "data not found" << endl;
    return -1;
  }
  cout << "data found:_" << head->data << endl;
  return head->data;
}

// Reverse linked list
void reverseList(Node **head_ref){
  Node *prev, *temp, *current;
  prev = temp = NULL;
  current = *head_ref;

  while(current != NULL){
    temp = current->next;
    current->next = prev;

    prev = current;
    current = temp;
  }
  *head_ref = prev;
}
