#include<iostream>
#include"queueN.h"

using namespace std;

Node::Node(int d, Node * node) {
	next = node;
	data = d;
}

//initializes front and rear to NULL
Queue::Queue(int m) {
	front = NULL;
	rear = NULL;
}

//copy constructor
Queue::Queue(const Queue & queue) {
	front = NULL;
	rear = NULL;
	Node * ptr = queue.front;
	//copies data
	while(ptr != NULL) {
		enqueue(ptr->data);
		ptr = ptr->next;
	}
}

//assignment operator
Queue & Queue::operator=(const Queue & queue) {
	//checks if same queue
	if(this != &queue) {
		front = NULL;
		rear = NULL;
		Node * ptr = queue.front;
		//copies data
		while(ptr != NULL) {
			enqueue(ptr->data);
			ptr = ptr->next;
		}
	}
	return * this;
}

//destructor
Queue::~Queue() {
	Node * temp = front;
	while(temp != NULL) {
		delete[] temp;
		temp = front->next;
		front = temp;
	}
}

bool Queue::enqueue(int d) {
	//checks if full
	if(!full()) {
		Node * temp = new Node(d, NULL);
		//checks if empty
		if(!empty()) {
			rear->next = temp;
		}else {
			front = temp;
		}
		//sets rear to new node
		rear = temp;
		return true;
	}else {
		return false;
	}
}

bool Queue::dequeue(int & d) {
	//checks if empty
	if(!empty()) {
		Node * temp = front;
		//returns front to d
		d = front->data;
		//moves front to next
		front = front->next;
		delete[] temp;
		temp = NULL;
		return true;
	}else {
		return false;
	}
}

//checks if empty
bool Queue::empty() const{
	if(front == NULL) {
		return true;
	}else {
		return false;
	}
}

//checks if full
bool Queue::full() const{
	return false;
}

//clears queue
bool Queue::clear() {
	Node * temp = front;
	while(temp != NULL) {
		delete[] temp;
		temp = front->next;
		front = temp;
	}
	return true;
}

bool Queue::operator==(const Queue & queue) const {
	bool same = true;
	Node * qptr = queue.front;
	Node * ptr = front;
	while(ptr != NULL) {
		if(qptr != NULL) {
			//checks if same
			if(ptr->data != qptr->data) {
				same = false;
			}
			//moves pointers to next
			qptr = qptr->next;
			ptr = ptr->next;
		}else {
			same = false;
		}
	}

	//checks if more values in qptr
	if(qptr != NULL) {
		same = false;
	}

	return same;
}

ostream & operator<<(ostream & os, const Queue & queue) {
	Node * ptr = queue.front;

	//prints queue
	while(ptr != NULL) {
		os << ptr->data << " ";
		ptr = ptr->next;
	}

	return os;
}
