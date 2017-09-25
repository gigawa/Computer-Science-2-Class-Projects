#include <iostream>
#include"listarray.h"

using namespace std;

//constructor
ListArray::ListArray(int d) {
	data = new int[d];
	cursor = -1;
	actual = -1;
	size = d;
}

//copy constructor
ListArray::ListArray(const ListArray & list) {
	data = new int[list.size];
	size = list.size;
	cursor = list.cursor;
	actual = list.actual;

	//copies data
	for(int i = 0; i < actual+1; i++) {
		data[i] = list.data[i];
	}	
}

//destructor
ListArray::~ListArray() {
	delete[] data;
	data = NULL;
}

//inserts before cursor
bool ListArray::insertBefore(const int & d) {
	if(!isFull()) {
		//if empty creates first element
		if(isEmpty()) {	
			data[0] = d;
			cursor = 0;
			actual = 0;
		}else {
			actual++;
			//moves data up array
			for(int i = 0; i < (actual-cursor); i++) {
				data[actual-i] = data[actual-1-i];
			}
			data[cursor] = d;
		}
		return true;
	}else {
		return false;
	}
}

//insert after
bool ListArray::insertAfter(const int & d) {
	if(!isFull()) {
		//if empty puts first element
		if(isEmpty()) {	
			data[0] = d;
			cursor = 0;
			actual = 0;
		}else {
			cursor++;
			actual++;
			//moves data up
			for(int i = 0; i < (actual-cursor); i++) {
				data[actual-i] = data[actual-1-i];
			}
			data[cursor] = d;
		}
		return true;
	}else {
		return false;
	}
}

//gets value at cursor
bool ListArray::get(int & d) const{
	//checks if empty
	if(!isEmpty()) {
		d = data[cursor];
		return true;
	}else {
		return false;
	}
}

//removes value at cursor
bool ListArray::remove(int & d){
	if(!isEmpty()) {
		d = data[cursor];
		//moves data down array
		for(int i = 0; i < actual-cursor; i++) {
			data[cursor+i] = data[cursor+1+i];
		}
		actual--;
		return true;
	}else {
		return false;
	}
}

//clears data
void ListArray::clear() {
	delete[] data;
	data = new int[size];
	cursor = -1;
	actual = -1;
}

//moves cursor to beginning
bool ListArray::goToBeginning() {
	if(!isEmpty()) {	
		cursor = 0;
		return true;
	}else {
		return false;
	}
}

//moves cursor to end
bool ListArray::goToEnd() {
	if(!isEmpty()) {	
		cursor = actual;
		return true;
	}else {
		return false;
	}
}

//moves cursor up one
bool ListArray::goToNext() {
	if(cursor < actual) {	
		cursor++;
		return true;
	}else {
		return false;
	}
}

//moves cursor to previous value in array
bool ListArray::goToPrior() {
	if(cursor > 0) {	
		cursor--;
		return true;
	}else {
		return false;
	}
}

//checks if empty
bool ListArray::isEmpty() const{
	if(actual == -1) {
		return true;
	}else {
		return false;
	}
}

//checks if full
bool ListArray::isFull() const{
	if(actual == size) {
		return true;
	}else {
		return false;
	}
}

//assigns the value into this list
ListArray & ListArray::operator=(const ListArray & list) {
	//checks if this is the same
	if(this != &list) {
		if(size != list.size) {
			delete[] data;
			data = new int[list.size];
			size = list.size;
		}
		cursor = list.cursor;
		actual = list.actual;
		//copies data
		for(int i = 0; i < actual+1; i++) {
			data[i] = list.data[i];
		}
	}

	//returns pointer to this
	return *this;
}

ostream& operator << (ostream & os, const ListArray & list) {
	//prints data from list
	for(int i = 0; i < list.actual+1; i++) {
		os << list.data[i] << " ";
	}
	return os;
}