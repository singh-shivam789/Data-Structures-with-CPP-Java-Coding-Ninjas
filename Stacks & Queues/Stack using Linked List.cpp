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

Output for every query will be printed in a separate line.

Note:
You are not required to print anything explicitly. It has already been taken care of. Just implement the function.

Constraints:
1 <= q <= 10^5
1 <= x <= 5
-2^31 <= data <= 2^31 - 1 and data != -1
Where 'q' is the total number of queries being performed on the stack, 'x' is the range for every query and data represents the integer pushed into the stack. 

Time Limit: 1 second

Sample Input 1:
6
1 13
1 47
4
5
2
3

Sample Output 1:
2
false
47
13

Sample Input 2:
4
5
2
1 10
5

Sample Output 2:
true
-1
false 

Explanation of Sample Input 2:
There are 4 queries in total.
The first one is Query-5: It tells whether the stack is empty or not. Since the stack is empty at this point, the output is  'true'.
The second one is Query-2: It pops the data from the stack. Since at this point in time, no data exist in the stack hence, it prints -1.
The third one is Query-1: It pushes the specified data 10 into the stack and since the function doesn't return anything, nothing is printed.
The fourth one is Query-5: It tells whether the stack is empty at this point or not. Since the stack has one element and hence it is not empty, false is printed.
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
    
    /*
        Output: 
        h
        h
        g
        f
        2
        0
    */
}
