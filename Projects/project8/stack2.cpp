#include<iostream>
#include"stack.h"

using namespace std;

Stack::Stack(int m) {
	max = m;
	data = new char[max];
	top = -1;
}

Stack::Stack(const Stack & stack) {
	max = stack.max;
	data = new char[max];
	top = -1;
	//copies stack into data
	for(int i = 0; i < max; i++) {
		push(stack.data[i]);
	}
}

Stack::~Stack() {
	delete[] data;
	data = NULL;
}

Stack & Stack::operator=(const Stack & stack) {
	if(this != &stack)
	{
		if(max != stack.max)
		{
			//resizes if necessary
			delete[] data;
			data = new char[stack.max];
		}
		//copies data into this stack
		for(int i = 0; i < max; i++) {
			data[i] = stack.data[i];
		}
		max = stack.max;
		top = stack.top;
	}
	return *this;
}

bool Stack::push(char c) {
	//adds data to stack
	if(top < (max-1)) {
		top++;
		data[top] = c;
		return true;
	}else {
		return false;
	}
}

bool Stack::pop(char & c) {
	//removes data from top
	if(top > -1) {
		c = data[top];
		top--;
		return true;
	}else {
		return false;
	}
}

bool Stack::empty() const{
	//checks if empty
	if(top == -1) {
		return true;
	}else {
		return false;
	}
}

bool Stack::full() const{
	//checks if full
	if(top == (max-1)) {
		return true;
	}else {
		return false;
	}
}

bool Stack::clear(){
	//clears data
	delete[] data;
	data = NULL;
	max = 0;
	top = -1;
}

ostream & operator<<(ostream & os, const Stack & stack) {
	//prints data from stack
	for(int i = 0; i < stack.top+1; i++) {
		os << stack.data[stack.top-i] << " ";
	}

	return os;
}

bool Stack::operator==(const Stack & stack) const{
	bool same = true;
	//checks if size is the same
	if(max == stack.max && top == stack.top) {
		for(int i = 0; i < top+1; i++) {
			//checks if data is same;
			if(data[i] != stack.data[i]) {
				same = false;
			}
		}
	}else {
		same = false;
	}
	return same;
}
