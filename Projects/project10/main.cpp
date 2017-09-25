#include <iostream>
#include"listnode.h"

using namespace std;

int main() {
	ListNode list;
	
	for(int i = 0; i < 5; i++) {
		list.insertAfter(i);
		list.insertBefore(i);
		cout << list << endl;
	}
	
	list.goToEnd();
	
	for(int i = 0; i < 5; i++) {
		list.insertAfter(i);
		list.insertBefore(i);
		cout << list << endl;
	}

	list.goToPrior();
	
	int d;
	list.get(d);
	cout << d << endl;

	//list.goToBeginning();

	list.goToNext();
	list.get(d);
	cout << d << endl;

	list.goToBeginning();
	for(int i = 0; i < 7; i++) {
		list.goToNext();
	}

	cout << list << endl;
	list.remove(d);
	cout << list << endl;

	ListNode list2(list);
	ListNode list3 = list;
	cout << list2 << endl;
	list.get(d);
	cout << d << endl;
	list2.get(d);
	cout << d << endl;
	cout << list3 << endl;
	list3.get(d);
	cout << d << endl;

	return 0;
}
