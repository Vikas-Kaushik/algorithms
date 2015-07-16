#include <iostream>
#include "singlylist.h"

using namespace std;

Node* mergeLists(Node* head1, Node* head2);

int main(){
  Node* head1 = makeList(5,10,34,55,70,99);
  Node* head2 = makeList(4,-1,51,72,100);

  displayList(head1);
  displayList(head2);

  head1 = mergeLists(head1, head2);

  displayList(head1);
  displayList(head2);

  return 0;
}

Node* mergeLists(Node* head1, Node* head2){
  Node *merged = NULL;
  // setting first node for merged list
  if(head1->data < head2->data) {
    merged = head1;
    head1 = head1->next;
  }
  else {
    merged = head2;
    head2 = head2->next;
  }

  while(head1 != NULL && head2 != NULL) {
    if(head1->data <= head2->data){
      merged->next = head1;
      head1 = head1->next;
      merged = merged->next;
    }
    else {
      merged->next = head2;
      head2 = head2->next;
      merged = merged->next;
    }
  }

  while(head1 != NULL) {
    merged->next = head1;
    head1 = head1->next;
    merged = merged->next;
  }
  while(head2 != NULL) {
    merged->next = head2;
    head2 = head2->next;
    merged = merged->next;
  }
  return merged;
}
