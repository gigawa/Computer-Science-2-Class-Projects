#include<iostream>
#include"stack.h"

using namespace std;

Stack::Stack(int m) {
	max = m;
	data = new char[max];
	top = 0;
	actual = 0;
}

Stack::Stack(const Stack & stack) {
	max = stack.max;
	data = new char[max];
	top = 0;
	actual = 0;
	
	//copies data from stack into this stack
	for(int i = 0; i < max; i++) {
		push(stack.data[stack.actual-i-1]);
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
		actual = stack.actual;
	}
	return *this;
}

bool Stack::push(char c) {
	//checks if full
	if(!full()) {
		actual++;
		//runs if stack is not empty
		if(!empty()) {
			//shifts data up one
			for(int i = 0; i < actual; i++) {
				data[actual-i] = data[actual-i-1];
			}
		}
		data[0] = c;
		return true;
	}else {
		return false;
	}
}

bool Stack::pop(char & c) {
	//runs if not empty
	if(!empty()) {
		c = data[0];
		//shifts data down by 1
		for(int i = 0; i < actual; i++) {
			data[i] = data[i+1];
		}
		return true;
	}else {
		return false;
	}
}

bool Stack::empty() const{
	//checks if length of stack is 0
	if(actual == 0) {
		return true;
	}else {
		return false;
	}
}

bool Stack::full() const{
	//checks if length is at max
	if(actual == max) {
		return true;
	}else {
		return false;
	}
}

bool Stack::clear(){
	delete[] data;
	data = NULL;
	max = 0;
	top = 0;
	actual = 0;
}

ostream & operator<<(ostream & os, const Stack & stack) {
	//prints out all data in stack starting at top
	for(int i = 0; i < stack.actual; i++) {
		os << stack.data[i] << " ";
	}

	return os;
}

bool Stack::operator==(const Stack & stack) const{
	bool same = true;

	//compares the size and max sizes to see if same
	if(max == stack.max && actual == stack.actual) {
		//compares data in the stacks
		for(int i = 0; i < actual; i++) {
			if(data[i] != stack.data[i]) {
				same = false;
			}
		}
	}else {
		same = false;
	}
	return same;
}
