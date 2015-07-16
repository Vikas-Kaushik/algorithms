/*
This program implements merge sort algorithm to sort a given linked list.
 */
#include <iostream>

using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* createNode(int data);
void printList(Node *head);

// Node* mergeSort(Node *head, int length);
// Node* listPartition(Node* head);
// Node* mergeLists(Node* h1, Node *h2, int l1, int l2);

Node* mergeSort(Node *head);
Node* listPartition(Node* head);
Node* mergeLists(Node* h1, Node *h2);

int main(){
  Node *head = createNode(5);
  head->next = createNode(10);
  head->next->next = createNode(2);
  head->next->next->next = createNode(3);
  head->next->next->next->next = createNode(1);

  printList(head);
  head = mergeSort(head);
  printList(head);

  // Node *head1 = createNode(5);
  // head1->next = createNode(10);
  // head1->next->next = createNode(15);
  // head1->next->next->next = createNode(20);
  // head1->next->next->next->next = createNode(25);

  // Node *head2 = createNode(3);
  // head2->next = createNode(12);
  // head2->next->next = createNode(18);
  // head2->next->next->next = createNode(20);
  // head2->next->next->next->next = createNode(90);

  // printList(head1);
  // printList(head2);
  // head1 = mergeLists(head1, head2);
  // printList(head1);

  return 0;
}

Node* mergeSort(Node *head){
  if(!head || !head->next){
    return head;
  }
  else {
    Node *temp = listPartition(head);
    head = mergeSort(head);
    temp = mergeSort(temp);
    head = mergeLists(head, temp);
    return head;
  }
}

Node* listPartition(Node* head){
  Node *slowptr, *fastptr;
  slowptr = fastptr = head;
  while(slowptr && fastptr && fastptr->next){
    head = slowptr;
    slowptr = slowptr->next;
    fastptr = fastptr->next->next;
  }
  // seperating two lists.
  head->next = NULL;
  return slowptr;
}

Node* mergeLists(Node* h1, Node *h2){
  if(!h1) return h2;
  if(!h2) return h1;
  Node *temp, *h3;

  if(h1->data < h2->data){
    h3 = temp = h1;
    h1 = h1->next;
  }
  else {
    h3 = temp = h2;
    h2 = h2->next;
  }

  while(h1 && h2){
    if(h1->data < h2->data){
      temp->next = h1;
      h1 = h1->next;
      temp = temp->next;
    }
    else {
      temp->next = h2;
      h2 = h2->next;
      temp = temp->next;
    }
  } 

  while(h1){
      temp->next = h1;
      h1 = h1->next;
      temp = temp->next;
  }
  while(h2){
      temp->next = h2;
      h2 = h2->next;
      temp = temp->next;
  }
  return h3;
}

/*
Node* mergeSort(Node *head, int length){
  if(length <= 1){
    if(!head) head->next = NULL;
    return head;
  }
  else {
    Node *p = listPartition(head);
    int n = length/2;
    Node *h1 = mergeSort(head, n);
    Node *h2 = mergeSort(p, length-n);
    p = mergeLists(h1, h2, n, length-n);
    return p;
  }
}

Node* listPartition(Node* head){
  Node *fastptr = head;
  while(head && fastptr && fastptr->next){
    head = head->next;
    fastptr = fastptr->next->next;
  }
  return head;
}

Node* mergeLists(Node* h1, Node *h2, int l1, int l2){
  if(!h1) return h1;
  if(!h2) return h2;

  Node* temp; 
  int i1,i2;
  i1 = i2 = 1;

  do {
    if(h1->data < h2->data){
      temp = h1;
      h1 = h1->next;
      ++i1;
    }
    else {
      temp = h2;
      h2 = h2->next;
      ++i2;
    }
  } while(i1 <= l1 && i2 <= l2 && h1 && h2);

  while(h1 && i1 <= l1){
      temp = h1;
      h1 = h1->next;
      ++i1;
  }
  while(h2 && i2 <= l2){
      temp = h2;
      h2 = h2->next;
      ++i2;
  }
  return temp;
}
*/
Node* createNode(int data){
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void printList(Node *head){
  cout << endl << "head";
  while(head){
    cout << " -> " << head->data;
    head = head->next;
  }
  cout << endl;
}
