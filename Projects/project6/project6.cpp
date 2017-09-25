#include <iostream>
#include <fstream>
#include "Agency.h" 

using namespace std;

void readFromFile(Agency &, bool &, char *);
void estimateCost(Agency &);
void search(Agency &, char *);

int main()
{
	Agency agency;
	int selection;
	bool readFile = false;
        char * temp = new char[20];
	char a[20] = "Make/Model";
	char * n = a;
	Car car(a,a,2015,122.12,1);
	car.print();

	do {
                cout << endl;
        	cout << "Rental Car Menu" << endl;
        	cout << "============================== " << endl;
       		cout << "1.  Read Data From File"<< endl;
       		cout << "2.  Print Agency Data"<< endl;
		cout << "3.  Print Available Cars"<< endl;
		cout << "4.  Find Most Expensive Car"<< endl;
		cout << "5.  Estimate Cost"<< endl;
        	cout << "6.  Sort By Make" << endl;
		cout << "7.  Sort By Price" << endl;
		cout << "8.  Search By Make" << endl;
		cout << "9.  Exit" << endl;
        	cout << "Enter your selection: ";
        	cin >> selection;
		cout << endl;

		//Menu selection
        	switch (selection)
        	{
            		case 1:
               			readFromFile(agency, readFile, temp);
                		break;			
           		case 2:
				if(readFile)
				{
                			agency.print();
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
			case 3:
				if(readFile)
				{                		
					agency.printAvailableCars();
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
			case 4:
				if(readFile)
				{ 
                			agency.findMostExpensive();
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
			case 5:
				if(readFile)
				{ 
                			estimateCost(agency);
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
                        case 6:
				if(readFile)
				{ 
                			agency.sortByMake();
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
                         case 7:
				if(readFile)
				{ 
                			agency.sortByPrice();
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
                        case 8:
				if(readFile)
				{ 
                			search(agency, temp);
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
			case 9:
                		break;
            		default:
               	 		cout << "Input not recognized" << endl;
                		break;
        	}
    	}while (selection != 9 );

        delete[] temp;

	return 0;
}

//Uses user input to have agency read in file
void readFromFile(Agency &agency, bool &readFile, char * temp) {
	cout << "Enter file name: ";
	cin >> temp;

	agency.readInData(temp);

	readFile = true;
}

//uses input from user to estimate and print cost
void estimateCost(Agency &agency) {
	int carNumber;
	int dayNumber;

	cout << "Enter car number: ";
	cin >> carNumber;
	cout << "Enter Number of Days: ";
	cin >> dayNumber;

	float cost = agency.estimateCost(carNumber,dayNumber);

	cout << "Estimated Cost: $" << cost << endl;
}

//takes user input and calls agency search
void search(Agency &agency, char * temp) {
	cout << "Enter Make: ";
	cin >> temp;

	agency.searchByMake(temp);
}
