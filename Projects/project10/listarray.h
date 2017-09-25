#include <iostream>
using namespace std;

template <typename T>
class ListArray {
public:
    ListArray(int=10);
    ListArray(const ListArray<T>&);
    ~ListArray();

    bool insertBefore(const T&);
    bool insertAfter(const T&);
    bool get(T&) const;
    bool remove(T&);

    void clear();

    bool goToBeginning();
    bool goToEnd();

    bool goToNext();
    bool goToPrior();

    bool isEmpty() const;
    bool isFull() const;

    ListArray<T>& operator = (const ListArray<T>&);

    template <typename S>
    friend ostream& operator << (ostream&, const ListArray<S>&);

private:
    T *data;
    int cursor;
    int actual;
    int size;
};

//Implementation

//constructor
template <typename T>
ListArray<T>::ListArray(int d) {
	data = new T[d];
	cursor = -1;
	actual = -1;
	size = d;
}

//copy constructor
template <typename T>
ListArray<T>::ListArray(const ListArray<T> & list) {
	data = new T[list.size];
	size = list.size;
	cursor = list.cursor;
	actual = list.actual;

	//copies data
	for(int i = 0; i < actual+1; i++) {
		data[i] = list.data[i];
	}	
}

//destructor
template <typename T>
ListArray<T>::~ListArray() {
	delete[] data;
	data = NULL;
}

//inserts before cursor
template <typename T>
bool ListArray<T>::insertBefore(const T & d) {
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
template <typename T>
bool ListArray<T>::insertAfter(const T & d) {
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
template <typename T>
bool ListArray<T>::get(T & d) const{
	//checks if empty
	if(!isEmpty()) {
		d = data[cursor];
		return true;
	}else {
		return false;
	}
}

//removes value at cursor
template <typename T>
bool ListArray<T>::remove(T & d){
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
template <typename T>
void ListArray<T>::clear() {
	delete[] data;
	data = new T[size];
	cursor = -1;
	actual = -1;
}

//moves cursor to beginning
template <typename T>
bool ListArray<T>::goToBeginning() {
	if(!isEmpty()) {	
		cursor = 0;
		return true;
	}else {
		return false;
	}
}

//moves cursor to end
template <typename T>
bool ListArray<T>::goToEnd() {
	if(!isEmpty()) {	
		cursor = actual;
		return true;
	}else {
		return false;
	}
}

//moves cursor up one
template <typename T>
bool ListArray<T>::goToNext() {
	if(cursor < actual) {	
		cursor++;
		return true;
	}else {
		return false;
	}
}

//moves cursor to previous value in array
template <typename T>
bool ListArray<T>::goToPrior() {
	if(cursor > 0) {	
		cursor--;
		return true;
	}else {
		return false;
	}
}

//checks if empty
template <typename T>
bool ListArray<T>::isEmpty() const{
	if(actual == -1) {
		return true;
	}else {
		return false;
	}
}

//checks if full
template <typename T>
bool ListArray<T>::isFull() const{
	if(actual == size) {
		return true;
	}else {
		return false;
	}
}

//assigns the value into this list
template <typename T>
ListArray<T> & ListArray<T>::operator=(const ListArray<T> & list) {
	//checks if this is the same
	if(this != &list) {
		if(size != list.size) {
			delete[] data;
			data = new T[list.size];
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

template <typename S>
ostream& operator << (ostream & os, const ListArray<S> & list) {
	//prints data from list
	for(int i = 0; i < list.actual+1; i++) {
		os << list.data[i] << " ";
	}
	return os;
}
