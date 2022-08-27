// Function to take input into Linked List 
// Complexity O(N)

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

void print(Node*head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

int main() {
  Node*head = takeInput();
	print(head);
	return 0;
}
