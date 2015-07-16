/* To add two numbers represented by linked list.
   Problem 2.5 in ctci. */
#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* newNode(int data);
void addNumbers_Wrap(Node* n1, Node* n2, Node** n3_ref, int & carry);
void addNumbers(Node* n1, Node* n2, Node** n3_ref);
void pushNode(Node** head_ref, int data);
void displayList(Node* head);

int main(){
  Node *n1, *n2, *n3;
  n1 = newNode(4);
  //  n1->next = newNode(1);
  //  n1->next->next = newNode(9);
  n2 = newNode(7);
  //  n2->next = newNode(8);
  //  n2->next->next = newNode(3);
  displayList(n1);
  displayList(n2);

  addNumbers(n1, n2, &n3); 
  displayList(n3);

  cout << endl;
  return 0;
}

Node* newNode(int data){
  Node* newnode = new Node;
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

void addNumbers(Node* n1, Node* n2, Node** n3_ref){
  int carry = 0;
  addNumbers_Wrap(n1, n2, n3_ref, carry);

  while(carry !=0){
    int temp = carry % 10;
    pushNode(n3_ref, temp);
    carry /= 10;
  }
}

void addNumbers_Wrap(Node* n1, Node* n2, Node** n3_ref, int & carry){
  if((n1 == NULL) && (n2 == NULL)) {
    cout << endl << "returning.";
    return;
  }
  else {
    if(n1 != NULL){
      cout << endl << "n1=n1->next, " << n1->data;
      n1 = n1->next;
    }
    if(n2 != NULL){
      cout << endl << "n2=n2->next, " << n2->data;
      n2 = n2->next;
    }
    addNumbers_Wrap(n1, n2, n3_ref, carry);
  }

  int sum = 0;
  cout << endl << "retracing";
  if((n1 != NULL) && (n2 != NULL)) {
    cout << endl << "n1 n2 both";
    sum = n1->data + n2->data + carry;
    carry = sum / 10;
    sum = sum % 10;
    cout << endl << "Values: n1,n2,carry,sum " << n1->data << ","<< n2->data << "," << carry << "," << sum;
    pushNode(n3_ref, sum);
  }
  else if(n1 != NULL){
    cout << endl << "n1 not null";
    sum = n1->data + carry;
    carry = sum / 10;
    sum = sum % 10;
    cout << endl << "Values: n1,n2,carry,sum " << n1->data << ","<< sum << "," << carry << "," << sum;
    pushNode(n3_ref, sum);
  }
  else if(n2 != NULL){
    cout << endl << "n2 not null";
    sum = n2->data + carry;
    carry = sum / 10;
    sum = sum % 10;
    cout << endl << "Values: n1,n2,carry,sum " << sum  << ","<< n2->data << "," << carry << "," << sum;;
    pushNode(n3_ref, sum);
  }
}

void pushNode(Node** head_ref, int data){
  Node* temp = *head_ref;
  *head_ref = newNode(data);
  (*head_ref)->next = temp;
}

void displayList(Node* head){
  cout << endl << "start";
  while(head){
    cout << "->" << head->data;
    head = head->next;
  }
  cout << "->NULL";
}
