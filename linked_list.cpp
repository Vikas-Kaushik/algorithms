#include<iostream>

using namespace std;

struct Node{
  struct Node *next;
  int value;
};
//Node* CreateList(); // To create a new list.
int AddNode(Node **list, int value, int position); // To add a new Node.
int DeleteNode(Node **list, int position); // To delete a Node.
int DisplayList(Node **list); // To display list.
int CountNode(Node **list); // To count number of nodes.
void PrintChoice(); // To show user the choices available.
void GetChoice(Node **list, int position, int value); // To get choice from user
void DeleteList(Node **list);

int main(){
  cout << "hello world" << endl;
  Node **real_node;
  Node *temp_node = new Node;
  temp_node->next = NULL;
  temp_node->value = 1;
  real_node = &temp_node;
  int position = 0;
  int value = 0;

  while(1){
    DisplayList(real_node);
    PrintChoice();
    GetChoice(real_node, position, value);
    cout <<"*********************************************************";
  }
  /*
  AddNode(real_node, 10, 1);
  DisplayList(*real_node);
  AddNode(real_node, 20, 1);
  DisplayList(*real_node);
  */
  return 0;
}
/*
Node* CreateList(){
  Node *new_node = new Node;
  new_node->next = NULL;
  new_node-value = 99;
  return new_node;
}
*/

int CountNode(Node **list){
  Node *temp;
  temp = *list;
  int count = 0;

  while(temp != NULL){
    ++count;
    temp = temp->next;
  }
  return count;
}

int AddNode(Node **list, int value, int position){
  int length = CountNode(list); // Calculating length of list
  if(length <= 0){
    cout << endl <<"There is not value in list. Hence it's not a list";
    return 1;     //First you need to create a list with at least one
  }               // node in it to use AddNode. It's not for empty list.

  cout << endl << "Existing Node count = " << length;
  cout << endl << "Adding Node at position = " << position;

  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  if((position < 1) || (position > (length+1))){
    cout << endl << "Incorrect position entered.";
    return 1;
  }
  else if(position == 1){   // Add node in the beginning.
    newNode->next = *list;
    *list = newNode;
  }
  else if(position == length+1){ // Add node at the end.
    Node *temp;
    temp = *list;

    // To point temp pointer to last node,'for'loop should run length -1 times.
    for(int count = 1; count < length; ++count){
      temp = temp->next;
    }

    /*    while(temp->next != NULL){
      temp = temp->next;
    }
    */
    temp->next = newNode;
  }
  else{  // Only case pending is adding node in middle somwhere.
    Node *temp;
    temp = *list;
    //    int count = position - 2;

    for(int count = 1; count < position-1; ++count){
      temp = temp->next;
    }

    /*    while(count > 0){
      temp = temp->next;
      --count;
    }
    */
    newNode->next = temp->next;
    temp->next = newNode;
  }

  cout << endl << "The node is added with value = " << value << endl;
  return 0;
}

int DeleteNode(Node **list, int position){
  int length = CountNode(list); // Calculating length of list
  if(length <= 0){
    cout << endl <<"There is not value in list. Hence it's not a list";
    return 1;     //First you need to create a list with at least one
  }               // node in it to use AddNode. It's not for empty list.

  cout << endl << "Existing Node count = " << length;
  cout << endl << "Deleting node at position = " << position;

  if((position < 1) && (position > length)){
    cout << endl << "Incorrect position entered.";
    return 1;
  }
  else if(position == 1){   // Deleting node in the beginning.
    Node *temp;
    temp = *list;
    *list = temp->next;
    delete(temp);
  }
  else if(position == length){ // Deleting node at the end.
    Node *temp;
    temp = *list;
    // To point temp pointer to 2nd last node,'for'loop should run length -2 times.
    for(int count = 1; count < length-1; ++count){
      temp = temp->next;
    }
    (*list) = temp;
    (*list)->next = NULL;
    delete(temp);
  }
  else{  // Only case pending is deleting node in middle somwhere.
    Node *temp;
    temp = *list;

    for(int count = 1; count < position-1; ++count){
      temp = temp->next;
    }
    (*list) = temp;
    temp->next = (temp->next)->next;
    delete(temp);
  }

  cout << endl << "The node is deleted at position = " << position;
  return 0;

  return 0;
}

int DisplayList(Node **list){
  Node *temp;
  temp = *list;
  cout << endl << "Your Linked-List is now like...." << endl;
  cout << "start->";
  while(temp != NULL){
    cout << temp->value << "->";
    temp = temp->next;
  }
  cout << "end" << endl;
  cout << "That's all !!" << endl;
  return 0;
}

void PrintChoice(){
  cout << endl;
  cout << "Please enter any choice number :-" << endl;
  cout << "To add a node       - 1" << endl;
  cout << "To delete a node    - 2" << endl;
  cout << "To display the list - 3" << endl;
  cout << "To delete the list  - 4" << endl;
  cout << "To exit the program - 0" << endl;
  cout << endl;
}
void GetChoice(Node **list, int position, int value){
  int c;
  cout << endl;
  cout << "So... Your Choice? :_";
  cin >> c;

  switch(c){
  case 0 : 
    //    exit();
    break;
  case 1 :
    cout << "Enter position where node is to be entered : ";
    cin >> position;
    cout << "Enter node value : ";
    cin >> value;
    AddNode(list, value, position);
    break;
  case 2 :
    cout << "Enter position where node is to be deleted : ";
    cin >> position;
    DeleteNode(list, position);
    break;
  case 3 :
    DisplayList(list);
    break;
  case 4 :
    DeleteList(list);
    break;
  default :
    cout << "Invalid choice.";
    break;
  }
  cout << endl;
}

void DeleteList(Node **list){
  cout << endl;
  cout << "Deleting whole list... ";
  Node *temp, *del;
  temp = *list;

  while(temp != NULL){
    del = temp;
    temp = temp->next;
    delete(del);
  }
  cout << endl;
}
