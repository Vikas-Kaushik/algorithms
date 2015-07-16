int main(){
  Node *n1, *n2;

  n1 = newNode(1);
  n1->next = newNode(2);
  n1->next->next = newNode(2);
  n1->next->next->next = newNode(1);

  n2 = newNode(1);
  n2->next = newNode(2);
  n2->next->next = newNode(3);
  n2->next->next->next = newNode(1);
  n2->next->next->next->next = newNode(1);

  displayList(n1);
  displayList(n2);

  if(checkPalindrome(n1))
    cout << endl << "n1 is palindrome";
  else
    cout << endl << "n1 is not palindrome";

  if(checkPalindrome(n2))
    cout << endl << "n2 is palindrome";
  else
    cout << endl << "n2 is not palindrome";

  cout << endl;
  return 0;
}

bool checkPalindrome(Node* head){
  if(head == NULL){
    return true; // here empty string assumed as palindrome
  }
  Node *first, *last;
  first = last = head;
  int count = 0;
  return _checkPalindrome(last, &first, count);
}

bool _checkPalindrome(Node* last, Node** first_ref, int &count){
  if(last == NULL){
    return true;
  }
  else {
    if(_checkPalindrome(last->next, first_ref, count)){
      if(last->data == (*first_ref)->data){
	(*first_ref) = (*first_ref)->next;
	return true;
      }
      else {
	return false;
      }
    }
    else {
      return false;
    }
  }
}

Node* newNode(int data){
  Node* newnode = new Node;
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
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
