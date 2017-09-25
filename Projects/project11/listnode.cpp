#include <iostream>
#include"listnode.h"

using namespace std;

//Node constructor 
Node::Node(int d, Node * node) {
	data = d;
	next = node;
}

//List constructor
ListNode::ListNode(int) {
	head = NULL;
	cursor = NULL;
}

//copy constructor
ListNode::ListNode(const ListNode & list) {
	head = NULL;
	cursor = NULL;
	Node * temp = list.head;
	//inserts values
	while(temp != NULL) {
		insertAfter(temp->data);
		temp = temp->next;
	}
	temp = list.head;
	Node * temp2 = head;
	//moves cursor
	while(temp != list.cursor) {
		temp = temp->next;
		temp2 = temp2->next;
	}
	cursor = temp2;
}

//destructor
ListNode::~ListNode() {
	cursor = head;
	Node * temp = cursor;
	while(temp != NULL) {
		delete[] temp;
		temp = cursor->next;
		cursor = temp;
	}
	head = NULL;
	cursor = NULL;
}

//inserts data after cursor
bool ListNode::insertAfter(int d) {
	//checks if full
	if(!isFull()) {	
		Node * temp = new Node(d, NULL);
		//if empty adds first node
		if(!isEmpty()) {
			temp->next = cursor->next;
			cursor->next = temp;
			cursor = temp;
		}else {
			cursor = temp;
			head = temp;
		}
		return true;
	}else {
		return false;
	}
}

//inserts before cursor
bool ListNode::insertBefore(int d) {
	if(!isFull()) {	
		Node * temp = new Node(d, NULL);
		//if empty adds first node
		if(!isEmpty()) {
			temp->next = cursor;
			if(head == cursor) {
				head = temp;
			}else {
				Node * temp2 = head;
				//sets previous node's next to new node
				while(temp2->next != cursor) {
					temp2 = temp2->next;
				}
				temp2->next = temp;
			}
			cursor = temp;
		}else {
			cursor = temp;
			head = temp;
		}
		return true;
	}else {
		return false;
	}
}

//returns value at cursor
bool ListNode::get(int & d) const {
	if(!isEmpty()) {
		d = cursor->data;
		return true;
	}else {
		return false;
	}
}

//removes value at cursor
bool ListNode::remove(int & d) {
	if(!isEmpty()) {
		//sets d to data at cursor
		d = cursor->data;
		if(head == cursor) {
			head = cursor->next;
			delete[] cursor;
			cursor = head;
		}else {
			Node * temp = head;
			//sets previous node's next to cursor next
			while(temp->next != cursor) {
				temp = temp->next;
			}
			temp->next = cursor->next;
			delete[] cursor;
			if(temp->next == NULL) {
				cursor = temp;
			}else {
				cursor = temp->next;
			}
		}
		return true;
	}else {
		return false;
	}
}

//moves cursor to beginning
bool ListNode::goToBeginning() {
	if(!isEmpty()) {
		cursor = head;
		return true;
	}else {
		return false;
	}
}

//moves cursor to end
bool ListNode::goToEnd() {
	if(!isEmpty()) {
		while(cursor->next != NULL) {
			cursor = cursor->next;
		}
		return true;
	}else {
		return false;
	}
}

//moves cursor to next node
bool ListNode::goToNext() {
	if(cursor->next != NULL) {
		cursor = cursor->next;
		return true;
	}else {
		return false;
	}
}

//moves cursor to prior
bool ListNode::goToPrior() {
	if(cursor != head) {
		Node * temp = head;
		//moves temp until next is cursor
		while(temp->next != cursor) {
			temp = temp->next;
		}
		cursor = temp;
		return true;
	}else {
		return false;
	}
}

//clears list
void ListNode::clear() {
	cursor = head;
	Node * temp = cursor;
	while(temp != NULL) {
		delete[] temp;
		temp = cursor->next;
		cursor = temp;
	}
	head = NULL;
	cursor = NULL;
}

//checks if empty
bool ListNode::isEmpty() const{
	if(head == NULL) {
		return true;
	}else {
		return false;
	}
}

//checks if full
bool ListNode::isFull() const{
	return false;
}

ListNode & ListNode::operator=(const ListNode & list) {
	//checks if this is list
	if(this != &list) {
		//if not empty clears list
		if(!isEmpty()) {
			clear();
		}
		Node * temp = list.head;
		//copies in data
		while(temp != NULL) {
			insertAfter(temp->data);
			temp = temp->next;
		}
		temp = list.head;
		Node * temp2 = head;
		//moves cursor to list cursor
		while(temp != list.cursor) {
			temp = temp->next;
			temp2 = temp2->next;
		}
		cursor = temp2;
	}

	return *this;
}

ostream& operator << (ostream & os, const ListNode & list) {
	Node * temp = list.head;
	//prints list
	while(temp != NULL) {
		os << temp->data << " ";
		temp = temp->next;
	}
	return os;
}
