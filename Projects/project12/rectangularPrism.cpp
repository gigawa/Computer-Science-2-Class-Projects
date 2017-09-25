#include"inheritance.h"
#include<iostream>

using namespace std;

RectangularPrism::RectangularPrism(float l, float w, float h) {
	length = l;
	width = w;
	height = h;
	isThreeDimensional = true;
	cout << "RectangularPrism Constructor" << endl;
}

float RectangularPrism::calculateAreaOrVolume() {
	return(length * width * height);
}

float RectangularPrism::calculatePerimeterOrSurfaceArea() {
	return((2*(length * width)) + (2*(length*height)) + (2*(width*height)));
}

void RectangularPrism::print() {
	cout << "Rectangular Prism with length: " << length << " width: " << width << " and height: " << height;
}