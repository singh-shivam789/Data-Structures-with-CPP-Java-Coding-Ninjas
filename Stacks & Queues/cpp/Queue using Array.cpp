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

This is implementation of the Queue data structure using Array and Template.

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
class queue {
	int size;
	int capacity;
	int nextIndex;
	int firstIndex;
	T* data;

public:
	queue(int s) {
		this->capacity = s;
		this->size = 0;
		nextIndex = 0;
		firstIndex = -1;
		data = new T[s];
	}

	int getsize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void enqueue(T element) {
		if (size == capacity) {
			T* newData = new T[2 * capacity];
			int j = 0;
			for (int i = firstIndex; i < capacity; i++) {
				newData[j++] = data[i];
			}
			for (int i = 0; i < nextIndex; i++) {
				newData[j++] = data[i];
			}
			delete[] data;
			data = newData;
			firstIndex = 0;
			nextIndex = capacity;
			capacity *= 2;
		}

		if (firstIndex == -1) {
			firstIndex = 0;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity;
		size++;
	}

	T front() {
		if (isEmpty()) {
			cout << "Queue is empty!" << endl;
			return 0;
		}
		return data[firstIndex];
	}

	T dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty!" << endl;
			return 0;
		}
		T save = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if (size == 0) {
			firstIndex = -1;
			nextIndex = 0;
		}
		return save;
	}

};

int main() {
	queue<int> q(5);
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

	cout << q.getsize() << endl;
	cout << q.isEmpty() << endl;
}
