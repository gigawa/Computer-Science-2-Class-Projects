#include<iostream>
#include<string>
#include"Polynomial.h"
#include<cmath>

using namespace std;

//default constructor
Polynomial::Polynomial() {
	degree = 3;
	coefficients = new int[4];
}

//paramaterized constructor
Polynomial::Polynomial(int d, int * c) {
	degree = d;
	coefficients = new int[degree+1];
	for(int i = 0; i < degree+1; i++) {
		coefficients[i] = c[i];
	}
}

//copy constructor
Polynomial::Polynomial(const Polynomial & poly) {
	degree = poly.degree;
	coefficients = new int[degree+1];
	for(int i = 0; i < degree+1; i++) {
		coefficients[i] = poly.coefficients[i];
	}
}

//destructor
Polynomial::~Polynomial() {
	delete[] coefficients;
	coefficients = NULL;
}

//solves polynomial returns int
int Polynomial::solve(int n) {
	int number;
	int x;
	for(int i = 0; i < degree+1; i++) {
		x = pow(n, (degree-i));
		number += (coefficients[i]*x);
	}
	return number;
}

//assignment operator
Polynomial & Polynomial::operator=(const Polynomial & poly) {
	if(this != &poly)
	{
		if(degree != poly.degree)
		{
			//resizes if necessary
			delete[] coefficients;
			coefficients = new int[poly.degree+1];
		}
		for(int i = 0; i < degree+1; i++) {
			coefficients[i] = poly.coefficients[i];
		}
		degree = poly.degree;
	}
	return *this;
}

//checks if polynomials are equal
bool Polynomial::operator==(const Polynomial & poly) const{
	bool same = true;
	//degrees must be equal to be equal
	if(degree == poly.degree) {
		for(int i = 0; i < degree+1; i++) {
			if(coefficients[i] != poly.coefficients[i]) {
				same = false;
			}
		}
	}else {
		same = false;
	}
	return same;
}

//checks if polynomials are not equal
bool Polynomial::operator!=(const Polynomial & poly) const{
	bool same = false;

	//if degrees are different polynomials are different
	if(degree == poly.degree) {
		for(int i = 0; i < degree+1; i++) {
			//compares coefficients
			if(coefficients[i] != poly.coefficients[i]) {
				same = true;
			}
		}
	}else {
		same = true;
	}
	return same;
}

//multiplies two polynomials
Polynomial operator*(const Polynomial & polyL, const Polynomial & polyR) {
	int length = 0;
	length = polyR.degree + polyL.degree;
	int * temp = new int[length+1];

	//sets temp to 0
	for(int i = 0; i < length + 1; i++) {
		temp[i] = 0;
	}

	//creates new polynomial to hold result
	Polynomial answer(length, temp);
	int k = 0;

	//multiplies polynomials
	for(int i = 0; i < polyL.degree+1; i++) {
		k = i;
		for(int j = 0; j < polyR.degree+1; j++) {
			answer.coefficients[k] += (polyL.coefficients[i] * polyR.coefficients[j]);
			k++;
		}
	}
	delete[] temp;
	temp = NULL;
	return answer;
}

//scales polynomial
Polynomial operator*(const Polynomial & poly, int n) {
	Polynomial answer(poly);
	for(int i = 0; i < answer.degree+1; i++) {
		answer.coefficients[i] = (answer.coefficients[i] * n);
	}
	return answer;
}

ostream & operator<<(ostream & os, const Polynomial & poly) {
	for(int i = 0; i < poly.degree+1; i++) {
		if(poly.coefficients[i] != 0) {
			if(poly.coefficients[i] != 1 || poly.degree-i <= 0) {
				//if coefficient is negative prints minus sign before coefficient
				if(poly.coefficients[i] < 0 && i != 0) {
					os << "- " << poly.coefficients[i]*(-1);
				}else {
					os << poly.coefficients[i];
				}
			}
			//prints 'x' if variable is present in coefficient
			if(poly.degree-i > 0) {
				os << "x";
				//raises to power if necessary
				if(poly.degree-i > 1) {
					os << "^" << (poly.degree-i);
				}
			}
			os << " ";
		}
		//if next coefficient is positive prints '+'
		if(poly.coefficients[i+1] > 0 && i < poly.degree) {
			os << "+ ";
		}
	}
	return os;
}

//reads in polynomial
istream & operator>>(istream & is, Polynomial & poly) {
	is >> poly.degree;
	delete[] poly.coefficients;
	poly.coefficients = new int[poly.degree+1];
	for(int i = 0; i < poly.degree+1; i++) {
		is >> poly.coefficients[i];
	}
	return is;
}

//adds polynomials
Polynomial operator + (const Polynomial & polyL, const Polynomial & polyR) {
	int * temp = new int[20];
	int length = polyL.degree+1;
	Polynomial answer(polyL);
	for(int i = 0; i < answer.degree+2; i++) {
		if(polyR.degree+1-i >= 0 && answer.degree+1-i >= 0) {
			answer.coefficients[answer.degree+1-i] += polyR.coefficients[polyR.degree+1-i];
			if(polyR.degree > answer.degree) {
				temp[polyR.degree+1-i] = answer.coefficients[answer.degree+1-i];
			}else {
				temp[answer.degree+1-i] = answer.coefficients[answer.degree+1-i];
			}
		}
	}

	//checks if degrees are different
	if(answer.degree < polyR.degree) {
		answer.degree = polyR.degree;
		delete[] answer.coefficients;
		answer.coefficients = new int[polyR.degree+1];
		for(int i = 0; i < length+1; i++) {
			answer.coefficients[length-i] = temp[length-i];
		}
		for(int i = 0; i < (polyR.degree - length + 1); i++) {
			answer.coefficients[polyR.degree - length + i] = polyR.coefficients[polyR.degree - length + i];
		}
	}
	delete[] temp;
	temp = NULL;
	return answer;
}

//subtracts polynomials
Polynomial operator - (const Polynomial & polyL, const Polynomial & polyR) {
	int * temp = new int[20];
	int length = polyL.degree+1;
	Polynomial answer(polyL);
	for(int i = 0; i < answer.degree+2; i++) {
		if(polyR.degree+1-i >= 0 && answer.degree+1-i >= 0) {
			answer.coefficients[answer.degree+1-i] -= polyR.coefficients[polyR.degree+1-i];
			if(polyR.degree > answer.degree) {
				temp[polyR.degree+1-i] = answer.coefficients[answer.degree+1-i];
			}else {
				temp[answer.degree+1-i] = answer.coefficients[answer.degree+1-i];
			}
		}
	}

	//checks if degrees are different
	if(answer.degree < polyR.degree) {
		answer.degree = polyR.degree;
		delete[] answer.coefficients;
		answer.coefficients = new int[polyR.degree+1];
		for(int i = 0; i < length+1; i++) {
			answer.coefficients[length-i] = temp[length-i];
		}
		for(int i = 0; i < (polyR.degree - length + 1); i++) {
			answer.coefficients[polyR.degree - length + i] = (-1)*polyR.coefficients[polyR.degree - length + i];
		}
	}
	delete[] temp;
	temp = NULL;
	return answer;
}
