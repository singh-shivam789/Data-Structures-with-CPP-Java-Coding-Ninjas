/*
A Queue is a linear structure which follows a particular order in which the operations are performed. 
The order is First In First Out (FIFO). A good example of a queue is any queue of consumers for a resource where the consumer that came first is served first. 
The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added.

Operations on Queue: 
Mainly the following four basic operations are performed on queue:
Enqueue: Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition. 
Dequeue: Removes an item from the queue. The items are popped in the same order in which they are pushed. If the queue is empty, then it is said to be an Underflow condition. 
Front: Get the front item from queue. 
Rear: Get the last item from queue. 

This is implementation of the Queue data structure using Linked List and Template.

Sample Input:
enqueue(10)
enqueue(20)
enqueue(30)
enqueue(40)
enqueue(50)
enqueue(60)
front()
dequeue()
dequeue()
dequeue()
getsize()
isEmpty()

Sample Output: 
10
10
20
30
3
0
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class Queue {
    int size;
    Node<T>* head;
    Node<T>* tail;

public:
    Queue() {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    T getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T dequeue() {
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

    int front() {
        if (isEmpty()) {
            return 0;
        }
        return head->data;
    }
};

int main() {
	Queue<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);

	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;
}
