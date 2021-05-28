/*
Length of LL
For a given singly linked list of integers, find and return its length. 
Do it using an iterative method.
*/

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data!=-1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}
int length(Node* head){
  Node* temp = head;
  int l = 0;
  while(temp != NULL){
    ++l;
    temp = temp->next;
  }
  return l;
}
int main() {
  Node*head = takeInput();
	int l = length(head);
  cout<<l<<endl;
  return 0;
}
