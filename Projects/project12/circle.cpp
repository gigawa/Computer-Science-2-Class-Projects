#include"inheritance.h"
#include<iostream>
#include<cmath>

using namespace std;

Circle::Circle(float r) {
	radius = r;
	isThreeDimensional = false;
	cout << "Circle Constructor" << endl;
}

float Circle::calculateAreaOrVolume() {
	return(M_PI * (radius*radius));
}

float Circle::calculatePerimeterOrSurfaceArea() {
	return(2 * M_PI * radius);
}

void Circle::print() {
	cout << "Circle with radius: " << radius;
}
