#include<iostream>
#include<fstream>
#include"inheritance.h"

using namespace std;

int main() {

	int numberOfShapes;
	char * file = new char[20];
	int shapeID;

	//has user enter file name
	cout << "Please enter file name: ";
	cin >> file;

	ifstream fin(file);

	//checks if file can be read
	if(!fin) {
		cout << "file could not be read" << endl;
		return 1;
	}

	//reads in number of shapes and creates double pointer for shapes
	fin >> numberOfShapes;
	Shape ** shape = new Shape * [numberOfShapes];

	//reads in all shapes
	for(int i = 0; i < numberOfShapes; i++) {
		fin >> shapeID;
		if(shapeID == 1) {
			float width, length;
			fin >> width;
			fin >> length;
			shape[i] = new Rectangle(width, length);
		}else if(shapeID == 2) {
			float width, length, height;
			fin >> width;
			fin >> length;
			fin >> height;
			shape[i] = new RectangularPrism(width, length, height);
		}else if(shapeID == 3) {
			float radius;
			fin >> radius;
			shape[i] = new Circle(radius);
		}else if(shapeID == 4) {
			float radius, height;
			fin >> radius;
			fin >> height;
			shape[i] = new Cylinder(radius, height);
		}
	}
	
	cout << endl;

	//prints surface area or perimeter of shapes
	for(int i = 0; i < numberOfShapes; i++) {
		if(shape[i]->is3D()) {
			cout << "The Surface Area of a ";
			shape[i]->print();
			cout << " is: " << shape[i]->calculatePerimeterOrSurfaceArea() << endl;
		}else {
			cout << "The Perimeter of a ";
			shape[i]->print();
			cout << " is: " << shape[i]->calculatePerimeterOrSurfaceArea() << endl;
		}
	}

	cout << endl;

	//prints volume or area of shapes
	for(int i = 0; i < numberOfShapes; i++) {
		if(shape[i]->is3D()) {
			cout << "The Volume of a ";
			shape[i]->print();
			cout << " is: " << shape[i]->calculateAreaOrVolume() << endl;
		}else {
			cout << "The Area of a ";
			shape[i]->print();
			cout << " is: " << shape[i]->calculateAreaOrVolume() << endl;
		}
	}

	//deallocates all shapes
	for(int i = 0; i < numberOfShapes; i++) {
		delete shape[i];
		shape[i] = NULL;
	}

	//deallocates pointer to shapes
	delete[] shape;

	//deallocates filename
	delete[] file;
	file = NULL;
	shape = NULL;

	return 0;
}
