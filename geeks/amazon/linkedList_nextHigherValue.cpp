/*
 * geeksforgeeks linke: 
 * http://www.geeksforgeeks.org/point-to-next-higher-value-node-in-a-linked-list-with-an-arbitrary-pointer/
 * Problem: Given singly linked list with every node having an additional ¡°arbitrary¡± pointer that currently points to NULL. Need to make the ¡°arbitrary¡± pointer point to the next higher value node.
 *
 */

#include <iostream>
#include <climits>

using namespace std;

struct Node{
  int data;
  Node* next;
  Node* nextHigh; // Pointing to next higher data node
};

Node* createNode(int data);
void printList(Node *head);
void printListSorted(Node *head);
Node* buildNextHighList(Node* head);
Node* buildNextHighListRec(Node* head);

// special merge sort (on node nextHigh instead of next)
Node* mergeSort(Node *head);
Node* listPartition(Node* head);
Node* mergeLists(Node* h1, Node *h2);

int main(){
  Node *head = createNode(5);
  head->next = createNode(10);
  head->next->next = createNode(2);
  head->next->next->next = createNode(3);
  printList(head);

  // Node* head1 = buildNextHighList(head);
  // printListSorted(head1);

  Node *head1 = buildNextHighListRec(head);
  printListSorted(head1);

  printList(head);
  printList(head1);

  return 0;
}

Node* buildNextHighListRec(Node* head){
  //copying next to nextHigh of each node so that they have same value
  Node *head_copy = head;
  while(head_copy){
    head_copy->nextHigh = head_copy->next;
    head_copy = head_copy->next;
  }

  // Applying merge sort taking nextHigh as next in original sort
  head_copy = head;
  return mergeSort(head);
}

Node* buildNextHighList(Node* head){
  Node *head_copy = head;
  while(head){
    Node* temp = head_copy;
    int n = head->data;
    int max = INT_MAX;
    while(temp){
      int t = temp->data;
      if(t > n && t < max){
	head->nextHigh = temp;
	max = t;
      }
      temp = temp->next;
    }
    head = head->next;
  }
  // Now get the minimum
  Node *temp;
  int min = INT_MAX;
  while(head_copy){
    if(head_copy->data < min){
      temp = head_copy;
      min = head_copy->data;
    }
    head_copy = head_copy->next;
  }
  return temp;
}

Node* createNode(int data){
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;
  newNode->nextHigh = NULL;
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

void printListSorted(Node *head){
  cout << endl << "head";
  while(head != NULL){
    cout << " -> " << head->data;
    head = head->nextHigh;
  }
  cout << endl;
}

Node* mergeSort(Node *head){
  if(!head || !head->nextHigh){
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
  while(slowptr && fastptr && fastptr->nextHigh){
    head = slowptr;
    slowptr = slowptr->nextHigh;
    fastptr = fastptr->nextHigh->nextHigh;
  }
  // seperating two lists.
  head->nextHigh = NULL;
  return slowptr;
}

Node* mergeLists(Node* h1, Node *h2){
  if(!h1) return h2;
  if(!h2) return h1;
  Node *temp, *h3;

  if(h1->data < h2->data){
    h3 = temp = h1;
    h1 = h1->nextHigh;
  }
  else {
    h3 = temp = h2;
    h2 = h2->nextHigh;
  }

  while(h1 && h2){
    if(h1->data < h2->data){
      temp->nextHigh = h1;
      h1 = h1->nextHigh;
      temp = temp->nextHigh;
    }
    else {
      temp->nextHigh = h2;
      h2 = h2->nextHigh;
      temp = temp->nextHigh;
    }
  } 

  while(h1){
      temp->nextHigh = h1;
      h1 = h1->nextHigh;
      temp = temp->nextHigh;
  }
  while(h2){
      temp->nextHigh = h2;
      h2 = h2->nextHigh;
      temp = temp->nextHigh;
  }
  return h3;
}


// Following code is to check if a list is palindrome or not.
// I wrote this to show to Kaju magic of recursion.
// bool isPalindrome(Node **first, Node *last){
//   if(last){
//     return true;
//   }
//   else {
//     if(isPalindrome(first, last->next) && first->data == last->data){
//       (*start) = (*start)->next;
//       return true;
//     }
//     else {
//       return false;
//     }
//   }
// }
