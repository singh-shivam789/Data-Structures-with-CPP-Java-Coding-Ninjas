//Insert a node at a given position
/*
   -Input format-
   -The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
   -Each test case contains a list of elements followed by two integers which are the position and the data for the node to be inserted.
   
   -Output format-
   -Insert the node at the desired position and print the updated list.
*/

#include<iostream>
using namespace std;
class Node{
  public: 
  int data; 
  Node* next;

  Node(int data){
    this -> data = data;
    this -> next = NULL;
  }

};

  Node* takeInput(){
    Node* head = NULL;
    Node* temp = NULL;
    int data;
    cin>>data;  
    while(data != -1){
      Node* newNode = new Node(data);
      if(head == NULL){
        head = newNode;
        temp = head;  
      }
      else{
        temp -> next = newNode;
        temp = newNode;
      }
      cin>>data;
    }

    return head;
  }

  void print(Node* head){
    while(head != NULL){
      cout << head->data <<" ";
      head = head -> next;
    }
    cout<<endl;
  }

  Node* insertNode(Node* head, int pos, int data){
    int count = 0;
    if(pos == 0){
      Node* newNode = new Node(data);
      Node* temp = head -> next;
      head -> next = NULL;
      delete head;
      newNode -> next = temp;
      return newNode;
    }
    else{
      Node* temp = head;
      while(count != pos-1 && temp != NULL){
        temp = temp -> next;
        count++;
      }
      if(temp != NULL && count == pos-1){
        Node* newNode = new Node(data);  
        Node* deleteNode = temp -> next;
        newNode -> next = deleteNode -> next;
        delete deleteNode;
        temp -> next = newNode;
      }
      return head;
    }
  }

int main(){
    Node* head = takeInput();

    int pos, data;
    cin >> pos >> data;
    head = insertNode(head, pos, data);
    
    print(head);
}
