#include<iostream>
#include<fstream>
#include<string>
#include"Polynomial.h"

using namespace std;

void choosePolynomials(int & polyN1, int & polyN2);
void solvePolynomial(Polynomial * poly);
void compare(Polynomial * poly);
void scalarPolynomial(Polynomial * poly);

int main() {
	int selection;
	int polyNumber;
        char * temp = new char[20];
	int polyN1, polyN2;

	ifstream fin;

	//read in file
	cout << "Please enter a file: ";
	cin >> temp;
	fin.open(temp);
	fin >> polyNumber;
	Polynomial * poly = new Polynomial[polyNumber];

	for(int i = 0; i < polyNumber; i++) {
		fin >> poly[i];
	}

	do {
                cout << endl;
        	cout << "Polynomial Menu" << endl;
        	cout << "============================== " << endl;
       		cout << "1.  Print Polynomials"<< endl;
		cout << "2.  Solve Polynomial"<< endl;
		cout << "3.  Compare Polynomials"<< endl;
		cout << "4.  Multiply Polynomials"<< endl;
        	cout << "5.  Scalar Polynomial" << endl;
		cout << "6.  Add Polynomials" << endl;
		cout << "7.  Subtract Polynomials" << endl;
		cout << "8.  Exit" << endl;
        	cout << "Enter your selection: ";
        	cin >> selection;
		cout << endl;

		//Menu selection
        	switch (selection)
        	{			
           		case 1:
                		for(int i = 0; i < polyNumber; i++) {
					cout << i+1 << ".   " << poly[i] << endl;
				}
                		break;
			case 2:               		
				solvePolynomial(poly);
				
                		break;
			case 3: 
                		compare(poly);
                		break;
			case 4:
                		choosePolynomials(polyN1, polyN2);
				cout << "Polynomial " << polyN1 << " * " << polyN2 << " is " << (poly[polyN1-1] * poly[polyN2-1]) << endl;
                		break;
                        case 5:
                		scalarPolynomial(poly);
                		break;
                         case 6:
                		choosePolynomials(polyN1, polyN2);
				cout << "Polynomial " << polyN1 << " + " << polyN2 << " is " << (poly[polyN1-1] + poly[polyN2-1]) << endl;
                		break;
                        case 7:
                		choosePolynomials(polyN1, polyN2);
				cout << "Polynomial " << polyN1 << " - " << polyN2 << " is " << (poly[polyN1-1] - poly[polyN2-1]) << endl;
                		break;
			case 8:
                		break;
            		default:
               	 		cout << "Input not recognized" << endl;
                		break;
        	}
    	}while (selection != 8 );

	delete[] temp;
	delete[] poly;

	temp = NULL;
	poly = NULL;
	
	return 0;
}

//solves a polynomial using input from user
void solvePolynomial(Polynomial * poly) {
	int solution;
	int x;
	int polyN;
	cout << "Enter the number of a Polynomial to solve: ";
	cin >> polyN;
	cout << "Enter the number to solve for: ";
	cin >> x;
	solution = poly[polyN-1].solve(x);
	cout << "Polynomial " << polyN << " with x = " << x << " is " << solution << endl;
}

//has user choose 2 polynomials to manipulate
void choosePolynomials(int & polyN1, int & polyN2) {
	cout << "Enter Polynomial 1: ";
	cin >> polyN1;
	cout << "Enter Polynomial 2: ";
	cin >> polyN2;
}

//compares 2 polynomials
void compare(Polynomial * poly) {
	int selection;
	int polyN1, polyN2;
	choosePolynomials(polyN1, polyN2);
	cout << "Enter 1 to check if they are equal and 2 to check if they are different: ";
	cin >> selection;
	switch(selection) {
		case 1:
			if(poly[polyN1-1] == poly[polyN2-1]) {
				cout << "The polynomials are equal" << endl;
			}
			break;
		case 2:
			if(poly[polyN1-1] != poly[polyN2-1]) {
				cout << "The polynomials are different" << endl;
			}
			break;
		default:
			cout << "Input not recognized" << endl;
			break;
	}
}

//scalars polynomial based on user input
void scalarPolynomial(Polynomial * poly) {
	int solution;
	int x;
	int polyN;
	cout << "Enter the number of a Polynomial to scalar: ";
	cin >> polyN;
	cout << "Enter the number to scalar with: ";
	cin >> x;
	cout << "Polynomial " << polyN << " scaled by " << x << " is " << poly[polyN-1] * x << endl;
}
