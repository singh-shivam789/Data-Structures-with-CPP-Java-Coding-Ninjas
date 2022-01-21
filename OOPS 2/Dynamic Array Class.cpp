/*
A Dynamic array (vector in C++, ArrayList in Java) automatically grows when we try to make an insertion and 
there is no more space left for the new item. Usually the area doubles in size. 

Features: 

1. add(int element) : Adds element at the end if the array size is not enough then extend the size of the array and
add an element at the end of the original array as well as given index. 

2. add(int index, int element) : Adds the element at the provided index if the provided index is equal or less than the current size.

3. print() : Prints all the elements in the array.

4. capacity() : Prints the current Capacity of the array.

5. length(): Prints the current length of the filled array.

6. Copy assignment operator and Copy constructor : Deep copying is implemented rather than the defualt shallow one. 
*/

#include<iostream>
using namespace std;

class d_array{
	int size;
	int nextElement;
	int *data;

	public:
	d_array(){
		size = 5;
		nextElement = 0;
		data = new int[size];
	}

	d_array(d_array const& d){
		this -> size = d.size;
		this -> nextElement = d.nextElement;
		this -> data = new int[d.size];
		for(int i=0; i<d.size;i++){
			this -> data[i] = d.data[i];
		}
	}

	void operator=(d_array const& d){
		this -> size = d.size;
		this -> nextElement = d.nextElement;
		this -> data = new int[d.size];
		for(int i=0; i<d.size;i++){
			this -> data[i] = d.data[i];
		}
	}

	void add(int element){
		if(nextElement == size){
			int* temp = new int[size * 2];
			for(int i = 0; i < size; i++){
				temp[i] = data[i];
			}
			delete [] data;
			data = temp;
			data[nextElement++] = element;
			size *= 2;
		}
		else{
			data[nextElement++] = element;
		}
	}

	void add(int index, int element){
		if(index < nextElement){
			data[index] = element;
		}
		else if(index == nextElement){
			add(element);
			nextElement++;
		}
		else{
			cout<<"Invalid Index"<<endl;
			return;
		}
	}

	void print(){
		for(int i = 0; i < nextElement; i++){
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}

	void capacity(){
			cout<< this -> size <<endl;
	}

	void length(){
		cout<< this -> nextElement << endl;
	}
};

int main(){
	d_array d1;
	d1.add(10);
	d1.add(20);	
	d1.add(30);	
	d1.add(40);	
	d1.add(50);	
	d1.capacity();
	d1.length();
	d1.add(60);	
	d1.capacity();
	d1.print();
	d1.length();

	d1.add(0, 100);
	d1.add(2, 200);
	d1.print();
	d1.capacity();
	d1.length();
	d1.add(10, 5000);
	d1.print();
	d_array d2 = d1;
	d1.add(0, 1000);
	d1.print();
	d2.print();
	d_array d3(d2);
	d3.print();
	d2.add(0, 2000);
	d3.add(0, 3000);
	d2.print();
	d3.print();
} 

/*
Output for the input: 

5
5
10
10 20 30 40 50 60    
6
100 20 200 40 50 60  
10
6
Invalid Index        
100 20 200 40 50 60  
1000 20 200 40 50 60 
100 20 200 40 50 60  
100 20 200 40 50 60  
2000 20 200 40 50 60 
3000 20 200 40 50 60
*/
