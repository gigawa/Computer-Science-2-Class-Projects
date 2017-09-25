#include<iostream>
#include<fstream>
#include"listnode.h"
#include"listarray.h"

using namespace std;

int Fibonacci(int);
void sort(ListNode &, ListArray &);
int binarySearch(ListArray, int, int, int);

int main() {
	int f;
	int elements = 10;
	int temp;
	char * file = new char[20];

	cout << "Please Enter file name: ";
	//reads in file name
	cin >> file;

	ifstream fin(file);

	//checks if file can be read
	if(!fin) {
		cout << "file could not be read" << endl;
		return 1;
	}

	fin >> elements;

	//creates lists
	ListNode list;
	ListArray listA(elements-1);

	//reads in elements of file
	for(int i = 0; i < elements; i++) {
		fin >> temp;
		list.insertAfter(temp);
	}
	fin.close();
	
	//prints unsorted list
	cout << "Unsorted list: " << list << endl;

	//sorts list
	sort(list, listA);

	//prints sorted list
	cout << "Sorted list: " << listA << endl;

	//gets and searches number
	cout << "Enter a number to search: ";
	cin >> temp;
	f = binarySearch(listA, temp, 0, elements);
	cout << "The value " << temp << " was found at " << f << endl;

	//runs fibonacci
	cout << "Please Enter a Number: ";
	cin >> temp;
	f = Fibonacci(temp);
	cout << "The Fibonacci Sequence at " << temp << " is " << f << endl;

	//deletes file
	delete[] file;
	file = NULL;

	return 0;
}

//gets fibonacci sequence at passed in int
int Fibonacci(int n) {
	if(n > 2) {
		//recursively gets previous numbers in sequence
		return (Fibonacci(n-1) + Fibonacci(n-2));
	}else if(n == 0) {
		return 0;
	}else {
		return 1;
	}
}

//sorts list and makes listarray of it
void sort(ListNode & list, ListArray & listA) {
	//returns cursor to beginning of list
	list.goToBeginning();
	bool swap = true;
	int curr;
	list.get(curr);
	int temp;
	//while swapped in last run
	while(swap) {
		swap = false;
		list.get(curr);
		//runs while not at end of list
		while(list.goToNext()) {
			list.get(temp);
			//if greater than previous
			if(temp < curr) {
				list.remove(temp);
				list.goToPrior();
				list.insertBefore(temp);
				if(list.goToNext()) {
					swap = true;
				}
			}
			list.get(curr);
		}
		//returns list to beginning
		list.goToBeginning();
	}

	list.get(temp);
	listA.insertAfter(temp);

	//copies node list to array list
	while(list.goToNext()) {
		list.get(temp);
		listA.insertAfter(temp);
	}
}

//binary search
int binarySearch (ListArray list, int search, int start, int end) {
	//determines if exists
	if(start <= end) {
		int pivot = (end+start)/2;
		int temp;
		list.goToBeginning();
		//moves cursor to half way between
		for(int i = 0; i < pivot; i++) {
			list.goToNext();
		}
		list.get(temp);
		//if less moves to first half
		if(search < temp) {
			return binarySearch(list, search, start, pivot-1);
		//if more moves to second half
		}else if(search > temp) {
			return binarySearch(list, search, pivot+1, end);
		//if same returns location
		}else if(search == temp) {
			return pivot;
		}
	}else {
		return -1;
	}
}
