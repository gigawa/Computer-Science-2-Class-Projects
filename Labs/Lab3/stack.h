#include <iostream>
#include<string>

using namespace std;

template<class T>
class Stack {
        public:
                Stack(int = 10);
                Stack(const Stack<T>&);
                ~Stack();
                Stack& operator=(const Stack<T>&);
                bool push(T);
                bool pop(T&);
                bool empty() const;
                bool full() const;
                bool clear();
		bool operator==(const Stack<T>&) const;

		template<typename U>
                friend ostream& operator<<(ostream&, const Stack<U>&);
        private:
                int max;
                int top;
                T * data;
};

template<class T>
Stack<T>::Stack(int m) {
	max = m;
	data = new T[max];
	top = -1;
}

template<class T>
Stack<T>::Stack(const Stack<T> & stack) {
	max = stack.max;
	data = new T[max];
	top = -1;
	//copies stack into data
	for(int i = 0; i < max; i++) {
		//push(stack.data[i]);
	}
}

template<class T>
Stack<T>::~Stack() {
	delete[] data;
	data = NULL;
}

template<class T>
Stack<T> & Stack<T>::operator=(const Stack<T> & stack) {
	if(this != &stack)
	{
		if(max != stack.max)
		{
			//resizes if necessary
			delete[] data;
			data = new T[stack.max];
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

template<class T>
bool Stack<T>::push(T c) {
	//adds data to stack
	if(!full()) {
		top++;
		data[top] = c;
		return true;
	}else {
		return false;
	}
}

template<class T>
bool Stack<T>::pop(T & c) {
	//removes data from top
	if(!empty()) {
		c = data[top];
		top--;
		//cout << "True" << c << endl;
		return true;
	}else {
		//cout << "False" << c << endl;
		return false;
	}
}

template<class T>
bool Stack<T>::empty() const{
	//checks if empty
	if(top == -1) {
		return true;
	}else {
		return false;
	}
}

template<class T>
bool Stack<T>::full() const{
	//checks if full
	if(top == (max-1)) {
		return true;
	}else {
		return false;
	}
}

template<class T>
bool Stack<T>::clear(){
	//clears data
	top = -1;
}

template<class U>
ostream & operator<<(ostream & os, const Stack<U> & stack) {
	//prints data from stack
	for(int i = 0; i < stack.top+1; i++) {
		os << stack.data[stack.top-i] << " ";
	}

	return os;
}

template<class T>
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
