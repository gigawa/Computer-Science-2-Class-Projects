#include<iostream>
#include"queue.h"

using namespace std;

int main() {
	Queue queue;

	int n = 0;
	
	for(int i = 0; i < 7; i++) {
		queue.enqueue(i);
	}

	cout << queue << endl;

	Queue queue1(queue);
	Queue queue2 = queue1;

	cout << boolalpha << queue.empty() << " " << queue.full() << endl;

	cout << queue << endl;
	cout << "Queue1: " << queue1 << endl;
	cout << "Queue2: " << queue2 << endl;

	for(int i = 0; i < 7; i++) {
		queue.dequeue(n);
		cout << n << "N ";
		cout << queue << endl;
	}

	for(int i = 0; i < 10; i++) {
		queue.enqueue(i);
	}

	for(int i = 0; i < 10; i++) {
		queue.dequeue(n);
		cout << n << "N ";
		cout << queue << endl;
	}

	if(queue == queue1) {
		cout << "True" << endl;
	}else {
		cout << "False" << endl;
	}

	if(queue1 == queue2) {
		cout << "True" << endl;
	}else {
		cout << "False" << endl;
	}

	cout << boolalpha << queue.empty() << " " << queue.full() << endl;

	cout << queue << endl;

	return 0;
}
