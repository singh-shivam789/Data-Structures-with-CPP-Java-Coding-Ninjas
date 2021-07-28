/*
Stack Using LL
Implement a Stack Data Structure to store any type of data using a Singly Linked List.
The data members should be private.

You need to implement the following public functions :

1. Constructor:
It initialises the data members as required.

2. push(data) :
This function should take one argument of any data-type. It pushes the element into the stack and returns nothing.

3. pop() :
It pops the element from the top of the stack and in turn, returns the element being popped or deleted. In case the stack is empty, it returns 0.

4. top :
It returns the element being kept at the top of the stack. In case the stack is empty, it returns 0.

5. size() :
It returns the size of the stack at any given instance of time.

6. isEmpty() :
It returns a boolean value indicating whether the stack is empty or not.

Output for every query should be printed in a separate line.

Time Limit: 1 second

Sample Input:
100
101
102
103
104

Sample Output:
 h
 h
 g
 f
 2
 0

*/

#include<iostream>
#include<algorithm>
#include<climits>
#include <stack>
#define fio ios_base :: sync_with_stdio(false)
#define ct cin.tie(NULL)
using namespace std;
template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>
class Stack {
    Node<T>* head;
    int size;
public:
    Stack() {
        this->head = NULL;
        this->size = 0;
    }

    int getSize() {
        return this->size;
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        else return false;
    }

    void push(T element) {
        Node<T>* newNode = new Node<T>(element);
        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    T pop() {
        if (isEmpty()) {
            return 0;
        }
        T save = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return save;
    }

    T top() {
        if (isEmpty()) {
            return 0;
        }
        else return head->data;
    }
};


int main() {
    Stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;
}
