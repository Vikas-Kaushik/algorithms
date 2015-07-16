#include <iostream>
using namespace std;

struct Node{
  int value;
  Node* next;
};

void addNode(Node**, int, int);
void deleteNode(Node**, int);
void displayList(Node*);
void push(Node**, int);
void insertAfter(Node*, int);
void append(Node*, int);
int nodeCount(Node*);

int main(){
  Node* head = NULL;

  /*
  while(true){
    int i;
    cout << endl << ":_";
    cin >> i;
    switch(i){
    case 1:
      continue;
    case 2:
      continue;
    case 3:
      continue;
    case 4:
      continue;
    case 5:
      continue;
    case 6:
      continue;
    default:
      cout << "exiting..." << endl;
      return 0;
    }
  }
  displayList(head);

  addNode(&head, 34, 1);
  displayList(head);

  addNode(&head, 32, 1);
  displayList(head);

  addNode(&head, 45, 2);
  displayList(head);

  addNode(&head, 55, 34);
  displayList(head);

  addNode(&head, 32, -1);
  displayList(head);

  deleteNode(&head, 1);
  */
  return 0;
}
int nodeCount(Node* head){
  int count = 0;
  while(head != NULL){
    ++count;
    head = head->next;
  }
  return count;
}
void displayList(Node* head){
  cout << endl;
  if(head == NULL)
    cout << "List is empty";
  while(head != NULL){
    cout << " -> " << head->value;
    head = head->next;
  }
  cout << endl;
}
void addNode(Node** head_ref, int value, int position){
  Node* head_copy = (*head_ref);
  int count = nodeCount(head_copy);

  if(head_copy == NULL){ // in case list is empty, i.e. adding very first element.
    push(head_ref, value);
  }
  else if(position == 1){ // add node at first position
    push(head_ref, value);  
  }
  else if(position > count){ // add node at the end
    append(head_copy, value);
  }
  else if((position > 1) && (position <= count)){ // add node in middle somewhere.
    for(int i = 2; i < position; ++i){ //  3rd Position means after 2nd. n means after n-1.
      head_copy = head_copy->next;
    }
    insertAfter(head_copy, value);
  }
  else {
    cout << endl << "Invalid position provided for addNode";
  }
}
void push(Node** head_ref, int value){
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;
  if(*head_ref == NULL){ // if list is empty
    (*head_ref) = newNode;
  }
  else{
    newNode->next = (*head_ref);
  }
  (*head_ref) = newNode;
 }
void insertAfter(Node* prevNode, int value){
  if(prevNode == NULL){
    cout << endl << "prevNode is provided NULL. Returning without doing anything";
    return;
  }
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = prevNode->next;
  prevNode->next = newNode;

}
void append(Node* head, int value){
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;
  if(head != NULL){ //if head is NULL ... head->next in while will fail. 
    while((head->next) != NULL){
      head = head->next;
    }
    head->next = newNode;
  }
}
void deleteNode(Node**, int){

}
