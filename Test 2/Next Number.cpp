/*
Next Number

Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).

Input Constraints:
1 <= Length of Linked List <=10^6.

Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)

Output Format :
Line 1: Updated linked list elements 

Sample Input 1 :
3 9 2 5 -1

Sample Output 1 :
3 9 2 6

Sample Input 2 :
9 9 9 -1

Sample Output 1 :
1 0 0 0 
*/

#include<iostream>
#define null NULL
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node *reverseLinkedList(Node *head) {
    if(head == null){
        return head;
    }
    Node* current = head;
    Node* prev = null;
    while(current != null){
        Node* sav = current->next;
        current -> next = prev;
        prev = current;
        current = sav;
    }
    return prev;
}

Node* NextLargeNumber(Node *head) {
    head = reverseLinkedList(head);
    int carry = 1;
    int prevElement = 0;
    Node* current = head;
    Node* prev = null;
    while(current != null){
        Node* sav = current->next;
        if(carry == 1){
            current -> data = (current -> data + carry) % 10;
            if(current -> data == 0){
                carry = 1;
            }
            else carry = 0;
        }
        prevElement = current -> data;
        current -> next = prev;
        prev = current;
        current = sav;
    }
    head = prev;
    if(head -> data == 0 && carry == 1){
        Node* newNode = new Node(carry);
        newNode -> next = head;
		head = newNode;
    }
    return head;
}

Node* takeinput(){
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Node *head = takeinput();
    head = NextLargeNumber(head);
    print(head);
    return 0;
}
