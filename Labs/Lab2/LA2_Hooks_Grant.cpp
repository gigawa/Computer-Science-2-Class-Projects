#include<iostream>
#include<fstream>
#include<stdexcept>
#include<string>

using namespace std;

int main(int argc, char * argv[]) {
	if(argc != 2) {
		throw runtime_error("Invalid number of arguments");
	}

	ifstream fin(argv[1]);
	
	if(!fin) {
		throw runtime_error("Could not open file");
	}

	string message;
	fin >> message;

	while(!fin.eof()) {
		cout << message << " ";
		fin >> message;
	}

	cout << endl;

	fin.close();

	return 0;
}
