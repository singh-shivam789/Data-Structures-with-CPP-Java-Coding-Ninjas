/*
Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).

Mainly the following three basic operations are performed in the stack:
Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
Peek or Top: Returns top element of stack.
isEmpty: Returns true if stack is empty, else false.
Note:push(), pop(), isEmpty() and peek() all take O(1) time. We do not run any loop in any of these operations.

Sample Input:
push(97)
push(98)
push(99)
push(100)
push(101)
top()
pop()
top()
size()

Sample Output:  
e
d
4 

This is implementation of the Dynamic Stack data structure using array and template:
*/

#include<iostream>
#include<algorithm>
#include<climits>
#define fio ios_base :: sync_with_stdio(false)
#define ct cin.tie(NULL)
using namespace std;
template<typename T>
class Stack {
    T* data;
    int capacity;
    int nextIndex;

public:
    Stack() {
        this->capacity = 5;
        data = new T[capacity];
        nextIndex = 0;
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        return nextIndex == 0;
    }

    T top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    void push(T element) {
        if (nextIndex == capacity) {
            T* newData = new T[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            capacity = capacity * 2;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

};

int main() {
    fio; ct;
    Stack<char> s1;
    s1.push(97);
    s1.push(98);
    s1.push(99);
    s1.push(100);
    s1.push(101);
    cout<<s1.top()<<endl;
    s1.pop();
    cout << s1.top() << endl;
    cout << s1.size() << endl;
    return 0;
}
