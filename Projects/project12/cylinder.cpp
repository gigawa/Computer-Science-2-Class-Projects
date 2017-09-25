#include"inheritance.h"
#include<iostream>
#include<cmath>

using namespace std;

Cylinder::Cylinder(float r, float h) {
	radius = r;
	height = h;
	isThreeDimensional = true;
	cout << "Cylinder Constructor" << endl;
}

float Cylinder::calculateAreaOrVolume() {
	return((M_PI * (radius*radius)) * height);
}

float Cylinder::calculatePerimeterOrSurfaceArea() {
	return(((2 * M_PI * radius) * height) + ((M_PI * (radius*radius)) * 2));
}

void Cylinder::print() {
	cout << "Cylinder with radius: " << radius << " and height: " << height;
}
