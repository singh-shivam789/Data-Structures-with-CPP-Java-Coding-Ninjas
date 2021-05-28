//Insert a node at a given position
/*
   -Input format-
   -The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
   -Each test case contains a list of elements followed by two integers which are the position and the data for the node to be inserted.
   
   -Output format-
   -Insert the node at the desired position and print the updated list.
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

int findLength(Node* head){
    int l = 0;
    Node* temp = head;
    while(temp != NULL){
        ++l;
        temp = temp->next;
    }
    return l;
}

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

Node* insert(Node* head, int n, int data){
    Node* newNode = new Node(data);
    if(n == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    else if(findLength(head) < n){
        return head;
    }
    else{
        Node*temp = head;
        int count = 0;
        while(count < n-1){
            ++count;
            temp = temp->next;
        }
        newNode -> next = temp->next;
        temp->next = newNode;
        return head;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
    Node*head = takeInput();
	    int pos, data;
	    cin>>pos>>data;
	    head = insert(head, pos, data);
      print(head);
      cout<<endl;
    }
	return 0;
}
