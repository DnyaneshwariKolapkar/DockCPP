#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};
/* Algorithm to insert element at the head of the list
      1. Create a new node with the data
      2. Make next of new node as head and previous as NULL
      3. Move the head to point to new node
*/
    
void insertAtHead(Node* &head, int val){
    Node* new_node = new Node(val);    
    new_node->next = head;            //for adding at the start our new node would be new head
    head = new_node;
}

/* Algorithm to insert element after given position
        1. Create a new node with the data
        2. Make next of new node as next of prev node
        3. Make prev node as next of new node
*/

Node* insertAfter(Node* head, int new_val, int position){
    if(position == 0){
        Node* a = new Node(new_val);
        a->data = new_val;
        a->next = head;
        return a;
    }
    else{
        int i;
        Node* a = head;
        for(i = 1; i < position; i++)
            a = a->next;
        Node* tmp = new Node(new_val);
        tmp->data = new_val;
        tmp->next = a->next;
        a->next = tmp;
        return head;
    }
}

/* Algorithm to insert element at the end of the list
      1. Create a new node with the data
      2. Move the last node to point to new node
      3. Make the new node as last node
*/
void insertAtEnd(Node* &head, int val){
    Node* new_node = new Node(val);

    if(head==NULL){             // if list is empty then new node should be 1st element of the list i.e. it will be the head node.
        head = new_node;
        return;
    }
    Node*  temp = head;        //temp variable to not tamper with the values of head
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;   // when temp cha next is NULL temp will bew out of while loop n then we set temp cha next to our new node
}

/* Algorithm to search an element in the list
      1. Move the current to point to head
      2. If current is NULL then the element is not present in the list
      3. If current is not NULL then compare the data of current with the element to be searched
      4. If the data is equal then return the current
      5. If the data is not equal then move the current to point to next of current 
*/
bool search(Node* head, int val){
    Node* current = head; // Initialize current 
    while (current != NULL) 
    { 
        if (current->data == val) 
            return true; 
        current = current->next; 
    } 
    return false; 
}

/* Algorithm to delete an element from the list
      1. Move the current to point to head
      2. If current is NULL then the element is not present in the list
      3. If current is not NULL then compare the data of current with the element to be deleted
      4. If the data is equal then make the next of current as head
      5. If the data is not equal then move the current to point to next of current 
*/
void deleteNode(Node* &head, int val){
  
    Node* temp = head;
    Node* prev = NULL;
 
    if (temp != NULL && temp->data == val) // If head node itself holds the key to be deleted
    {
        head = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
    else{                                   // Else Search for the key to be deleted,  
         while (temp != NULL && temp->data != val)
        {
            prev = temp;                         //keep track of the previous node as we need to change 'prev->next' */
            temp = temp->next;
        }
        if (temp == NULL)  // If key was not present in linked list
          return;
 
        prev->next = temp->next;   // Unlink the node from linked list
        delete temp; // Free memory
    }
}

/* Algorithm to print  the list
      1. Move the current to point to head
      2. If current is NULL then the list is empty
      3. If current is not NULL then print the data of current and move the current to point to next of current 
*/
void printList(Node* n)    //to print the linked list
{   
    if(n != NULL) {
        cout << n->data << " ";
        printList(n->next);
    }
}
 
// Driver code
int main()
{
    Node* head = NULL;
    int choice, data, position;
   
    while(1){
        cout<<"\n 1.Insert element at the end";
        cout<<"\n 2.Insert element after the :";
        cout<<"\n 3.Insert element at the start";
        cout<<"\n 4.Search for the element in the list";
        cout<<"\n 5.Delete node in a list";
        cout<<"\n 6.Exit";
        cout<<"\n Enter your choice: ";
        cin>>choice;
       if(choice>5){
           break;
       }
       switch(choice){
          case 1: 
           cout<<"\n Enter data to be inserted at the end: ";
           cin>>data;
           insertAtEnd(head, data);
           printList(head);
           break;
         
          case 2: 
           cout<<"\n Enter data to be inserted : ";
           cin>>data;
           cout<<"\n Enter index at which element is to be inserted: ";
           cin>>position;
           insertAfter(head, data, position);
           printList(head);
           break;
         

          case 3:
           cout<<"\n Enter data to be inserted at the start: ";
           cin>>data;
           insertAtHead(head, data);
           printList(head);
           break;

          case 4:
           cout<<"\n Enter data to be searched : ";
           cin>>data;
           search(head, data)? cout<<"Found" : cout<<"Not found"; 
           break;
    
          case 5:
           cout<<"\n Enter element to be deleted : ";
           cin>>data;
           deleteNode(head, data);
           printList(head);
           break;
        }
    }
 
    return 0;
} 