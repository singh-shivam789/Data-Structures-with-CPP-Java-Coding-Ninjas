/*
Delete Alternate Nodes
Given a Singly Linked List of integers, delete all the alternate nodes in the list.

Example:
List: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> null
Alternate nodes will be:  20, 40, and 60.

Hence after deleting, the list will be:
Output: 10 -> 30 -> 50 -> null

Input format :
The first and the only line of input will contain the elements of the Singly Linked List separated by a single space and terminated by -1.

Output Format :
The only line of output will contain the updated list elements.

Input Constraints:
1 <= N <= 10 ^ 6.
Where N is the size of the Singly Linked List

Time Limit: 1 sec

Sample Input 1:
1 2 3 4 5 -1

Sample Output 1:
1 3 5

Explanation of Sample Input 1:
2, 4 are alternate nodes so we need to delete them 

Sample Input 2:
10 20 30 40 50 60 70 -1

Sample Output 2:
10 30 50 70 

*/
#include<iostream>
#define null NULL
using namespace std;
class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node() {
        if(next) {
            delete next;
        }
    }
};

void deleteAlternateNodes(Node *head) {
    if(head == null){
        return;
    }

    Node* prev = head;
    Node* temp = head;

    int count = 0;
    while(temp != null){
        if(count % 2 != 0){
			Node* save = temp -> next;
            prev -> next = save;
            free(temp);
            temp = save;
            prev = save;
            count++;
        }
        else{
            temp = temp -> next;
            count++;
        }
    }
}

Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
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

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}
