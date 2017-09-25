#include<iostream>
#include"stack.h"

using namespace std;

int main() {
	Stack stack(10);
	Stack stack2;

	char c = 'z';
	
	cout << boolalpha << stack.empty() << " " << stack.full() << endl;

	for(int i = 0; i < 10; i++) {
		stack.push(c);
		c -= 1;
	}

	cout << boolalpha << stack.empty() << " " << stack.full() << endl;

	Stack stack1(stack);

	stack2 = stack;

	cout << stack1 << endl;// << stack1 << endl;

	if(stack1 == stack2) {
		cout << "same" << endl;
	}else {
		cout << "different" << endl;
	}

	for(int i = 0; i < 10; i++) {
		stack.pop(c);
		cout << c << " ";
	}

	stack.clear();

	cout << boolalpha << stack.empty() << " " << stack.full() << endl;


	//cout << endl;

	//cout << stack;

	/*Stack stack2(stack);

	cout << "stack2: " << stack2 << endl;

	stack1 = stack;

	if(stack2 == stack) {
		cout << "same" << endl;
	}else {
		cout << "different" << endl;
	}

	cout << stack << endl;

	cout << boolalpha << stack.empty() << endl;

	cout << stack1 << endl;

	//cout << stack;*/

	return 0;
}
