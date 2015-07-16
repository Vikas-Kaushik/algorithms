#include <iostream>
using namespace std;

int main(){

}

void recursive_reverse(Node** head, Node* prev){
  if((*head) == NULL){
    (*head) = prev;
    return;
  }
  else{
    Node* temp = (*head)->next;
    (*head)->next = prev;
    prev = (*head);
    (*head) = temp;

    recursive_reverse(&head, prev);
  }
}

void recursiveReverse(struct node** head_ref)
{
    struct node* first;
    struct node* rest;
      
    /* empty list */
    if (*head_ref == NULL)
       return;   
 
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;  
    rest  = first->next;
 
    /* List has only one node */
    if (rest == NULL)
       return;   
 
    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;  // Did not understood this step
     
    /* tricky step -- see the diagram */
    first->next  = NULL;          
 
    /* fix the head pointer */
    *head_ref = rest;              
}
