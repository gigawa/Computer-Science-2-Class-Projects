#include<iostream>
#include<string>
#include"stack.h"

using namespace std;

template<typename T>
Stack<T>::Stack(int m) {
	max = m;
	data = new char[max];
	top = -1;
}

template<typename T>
Stack<T>::Stack(const Stack<T> & stack) {
	max = stack.max;
	data = new char[max];
	top = -1;
	//copies stack into data
	for(int i = 0; i < max; i++) {
		//push(stack.data[i]);
	}
}

template<typename T>
Stack<T>::~Stack() {
	delete[] data;
	data = NULL;
}

template<typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & stack) {
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

template<typename T>
bool Stack<T>::push(T c) {
	//adds data to stack
	if(top < (max-1)) {
		top++;
		data[top] = c;
		return true;
	}else {
		return false;
	}
}

template<typename T>
bool Stack<T>::pop(T & c) {
	//removes data from top
	if(top > -1) {
		c = data[top];
		top--;
		return true;
	}else {
		return false;
	}
}

template<typename T>
bool Stack<T>::empty() const{
	//checks if empty
	if(top == -1) {
		return true;
	}else {
		return false;
	}
}

template<typename T>
bool Stack<T>::full() const{
	//checks if full
	if(top == (max-1)) {
		return true;
	}else {
		return false;
	}
}

template<typename T>
bool Stack<T>::clear(){
	//clears data
	max = 0;
	top = -1;
}

template<typename U>
ostream & operator<<(ostream & os, const Stack<U> & stack) {
	//prints data from stack
	for(int i = 0; i < stack.top+1; i++) {
		os << stack.data[stack.top-i] << " ";
	}

	return os;
}

template<typename T>
bool Stack<T>::operator==(const Stack<T> & stack) const{
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
