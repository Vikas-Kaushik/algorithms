#ifndef _doublylist_h
#define _doublylist_h

struct Node{
  int data;
  Node* next;
  Node* prev;
};

Node* makeList(int count, ...);
void addNode(Node** head, int data);
void deleteList(Node** head);
void displayList(Node *head);

/* Usage of liabray

struct Node{
  int data;
  Node* next;
};

int main(){
  Node* head = makeList(5,10,45,65,23,9);
  displayList(head);
  deleteList(&head);
  displayList(head);
  return 0;
}
*/

#endif
