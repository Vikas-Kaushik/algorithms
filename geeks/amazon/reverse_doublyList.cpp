#include <iostream>
#include "doublylist.h"

using namespace std;

void reverseList(Node** head);
void reverseListRecursive(Node**);

int main(){
  Node* head = makeList(5,10,45,65,23,9);
  displayList(head);

  reverseList(&head);
  displayList(head);

  reverseListRecursive(&head);
  displayList(head);

  deleteList(&head);
  displayList(head);
  return 0;
}

void reverseList(Node** head){
  Node* temp = NULL;
  while(*head != NULL){
    temp = (*head)->next;
    (*head)->next = (*head)->prev;
    (*head)->prev = temp;
    temp = *head; // just to keep track of head in case head->next is null
    (*head) = (*head)->prev;
  }
  *head = temp;
}

void reverseListRecursive(Node** head){
  Node* temp = NULL;
  if((*head)->next == NULL){
    temp = (*head)->next;
    (*head)->next = (*head)->prev;
    (*head)->prev = temp;
    return;
  }
  else {
    temp = (*head)->next;
    (*head)->next = (*head)->prev;
    (*head)->prev = temp;
    (*head) = (*head)->prev; // move ahead
    reverseListRecursive(head);
  }
}
