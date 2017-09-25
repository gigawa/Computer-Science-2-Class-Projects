#include<iostream>
#include"queue.h"

using namespace std;

//constructor
Queue::Queue(int m) {
	max = m;
	front = -1;
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
	front = -1;
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
		front = -1;
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
		//checks if empty
		if(empty()) {
			front++;
			rear = front-1;
		}	
		rear = ((rear + 1)%max);
		//adds data to end
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
		d = data[front];
		data[front] = 0;
		//sets rear to -1 if empty
		if(front == rear) {
			rear = -1;
		}
		//moves front
		front = ((front+1)%max);
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
	if(rear == (front-1) || (front < rear && front+rear == max-1)) {
		return true;
	}else {
		return false;
	}
}

//clears data
bool Queue::clear() {
	delete[] data;
	data = new int[max];
	front = -1;
	rear = -1;
	return true;
}

bool Queue::operator==(const Queue & queue) const {
	bool same = true;

	int location = front;
	int queueLocation = queue.front;

	//compares the size and max sizes to see if same
	if(max == queue.max) {
		//compares data in the stacks
		for(int i = 0; i < queue.rear+1; i++) {
			location = (front + i)%max;
			queueLocation = (queue.front + i)%max;
			if(data[location] != queue.data[queueLocation]) {
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
	int j = queue.front;
	int m;

	if(queue.rear > queue.front) {
		m = queue.rear-(queue.front-1);
	}else if(queue.rear < queue.front) {
		m = (queue.rear+queue.max)-(queue.front-1);
	}else {
		m = 1;
	}

	if(queue.rear == -1) {
		m = 0;
	}else if(m < 0) {
		m *= -1;
	}
	for(int i = 0; i < m; i++) {
		os << queue.data[j] << " ";
		j = ((j+1)%queue.max);
	}

	return os;
}