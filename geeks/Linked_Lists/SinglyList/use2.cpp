#include <iostream>
#include "singlyList.h"

using namespace std;

bool isPalindrome(Node* head);
bool isPalindromeRec(Node** left, Node* right);
bool checkIntersection(Node* list1, Node* list2, Node** cross);

int main(){
  cout << endl << "Singly linked list... " << endl;
  Node* head = NULL;
  int data;
  while(true){
    cout << ":_";
    cin >> data;
    if(data > 100) break;
    append(&head, data);
  } 

  displayList(head);

  if(isPalindrome(head))
    cout << "list is palindrome.." << endl;
  else 
    cout << "list is not palindrome.." << endl;

  deleteList(&head);
  return 0;
}

bool isPalindrome(Node* head){
  return isPalindromeRec(&head, head);
}

// In following recursion, left pointer is working as a global variable, which we are changing in recursing back,
// so that in recursing back, right is being taken from stack i.e. from last node towards first node
// and left (global like) node, moving from first node to last node, in the same process.
bool isPalindromeRec(Node** left, Node* right){
  // if right pointer has reached end of list.
  if(right == NULL)
    return true;

  bool flag = isPalindromeRec(left, right->next);

  // if flag and data and left and right nodes is same
  if(flag && ((*left)->data == right->data)){
    // Move left pointer forward
    *left = (*left)->next;
  }
  else {  // else return false
    return false;
  }
}

bool checkIntersection(Node* list1, Node* list2, Node** cross){
  // if both list have been traversed
  if(list1 == NULL && list2 == NULL){
    return true;
  }
  bool flag;
  // list1 and list2 will move till end i.e. NULL.
  if(list1 != NULL && list2 != NULL){
    flag = checkIntersection(list1->next, list2->next, cross);
  }
  else if(list1 == NULL) {
    flag = checkIntersection(list1, list2->next, cross);
  }
  else {
    flag = checkIntersection(list1->next, list2, cross);
  }

  if(flag && (list1 == list2)){
    *cross = list1;
    return true;
  }

  return false;
}
