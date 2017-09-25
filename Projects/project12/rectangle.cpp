#include"inheritance.h"
#include<iostream>

using namespace std;

Rectangle::Rectangle(float l, float w) {
	length = l;
	width = w;
	isThreeDimensional = false;
	cout << "Rectangle Constructor" << endl;
}

float Rectangle::calculateAreaOrVolume() {
	return(length * width);
}

float Rectangle::calculatePerimeterOrSurfaceArea() {
	return((length*2) + (width*2));
}

void Rectangle::print() {
	cout << "Rectangle with length: " << length << " and width: " << width;
}
