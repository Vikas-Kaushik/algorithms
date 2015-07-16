#include <iostream>
#include "singlyList.h"

using namespace std;

int main(){
  cout << endl << "Singly linked list. Enter Option.. " << endl;
  Node* head = NULL;
  while(true){
    unsigned int index;
    int data;
    cout << endl << ":_";
    cin >> index;

    switch(index){
    case 1: // add node
      cout << "index:_";
      cin >> index;
      cout << "data:_";
      cin >> data;
      addNode(&head, data, index);
      continue;
    case 2: // delete a node
      cout << "data:_";
      cin >> data;
      deleteNode(&head, data);
      continue; 
    case 3: // display list
      displayList(head);
      continue;
    case 4: // delete list
      deleteList(&head);
      continue;
    case 5: // count nodes
      cout << "count: " << countNodes(head) << endl;
      continue;
    case 6: // append data
      cout << "data:_";
      cin >> data;
      append(&head, data);
      continue;
    case 7: // push data
      cout << "data:_";
      cin >> data;
      push(&head, data);
      continue;
    case 8: // get nth node
      cout << "index:_";
      cin >> index;
      getNode(head, index);
      continue;
    case 9: // reverse linked list
      cout << "list reversed.." << endl;
      reverseList(&head);
      continue;
    default: // exit
      cout << "exiting..." << endl;
      deleteList(&head);
      return 0;
    }
  }
  return 0;
}
