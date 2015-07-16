#ifndef _SINGLYLIST_H
#define _SINGLYLIST_H

struct Node{
  int data;
  struct Node* next;
};

void addNode(Node** head_ref, int data, unsigned int index);
void append(Node** head_ref, int data);
void push(Node** head_ref, int data);
void deleteNode(Node** head_ref, int data);
void deleteList(Node** head_ref);
void displayList(Node *head);
unsigned int countNodes(Node* head);
int getNode(Node* head, int index);
void reverseList(Node **head_ref);

#endif
