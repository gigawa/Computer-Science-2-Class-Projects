#include<iostream>
#include"queue.h"

using namespace std;

//constructor
Queue::Queue(int m) {
	max = m;
	front = 0;
	rear = -1;
	data = new int[max];
}

//destructor
Queue::~Queue() {
	delete[] data;
	data = NULL;
}

//copy constructor
Queue::Queue(const Queue & queue) {
	max = queue.max;
	front = 0;
	rear = -1;
	data = new int[max];
	for(int i = 0; i < queue.rear+1; i++) {
		enqueue(queue.data[i]);
	}
}

//assignment operator
Queue & Queue::operator=(const Queue & queue) {
	//checks if same as assigned	
	if(this != &queue) {
		if(max != queue.max) {
			delete[] data;
			data = new int[queue.max];
			max = queue.max;
		}
		front = 0;
		rear = -1;
		//copies data
		for(int i = 0; i < queue.rear+1; i++) {
			enqueue(queue.data[i]);
		}
	}

	return *this;
}

bool Queue::enqueue(int d) {
	//checks if full
	if(!full()) {
		//adds data to end
		rear++;
		data[rear] = d;
		return true;
	}else {
		return false;
	}
}

bool Queue::dequeue(int & d) {
	//checks if empty
	if(!empty()) {
		//returns data at front
		d = data[0];
		//shuffles data
		for(int i = 0; i < rear; i++) {
			data[i] = data[i+1];
		}
		rear--;
		return true;
	}else {
		return false;
	}
}

//checks if empty
bool Queue::empty() const {
	if(rear == -1) {
		return true;
	}else {
		return false;
	}
}

//checks if full
bool Queue::full() const {
	if(rear == (max-1)) {
		return true;
	}else {
		return false;
	}
}

//clears data
bool Queue::clear() {
	delete[] data;
	data = new int[max];
	front = 0;
	rear = -1;
	return true;
}

bool Queue::operator==(const Queue & queue) const {
	bool same = true;

	//compares the size and max sizes to see if same
	if(max == queue.max && rear == queue.rear) {
		//compares data in the stacks
		for(int i = 0; i < queue.rear+1; i++) {
			if(data[i] != queue.data[i]) {
				same = false;
			}
		}
	}else {
		same = false;
	}
	return same;
}

//prints queue
ostream& operator<<(ostream & os, const Queue & queue) {
	for(int i = queue.front; i < (queue.rear+1)%max; i++) {
		os << queue.data[i] << " ";
	}

	return os;
}
