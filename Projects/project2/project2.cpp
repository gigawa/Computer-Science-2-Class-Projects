#include<iostream>
#include<fstream>

using namespace std;

//rental car struct
struct rentalCar {
	int year;	
	char make[20];
	char model[20];
	float price;
	bool available;
};

//function prototypes
void readFromFile(rentalCar cars[], bool &readFile);
void printAllData(rentalCar cars[]);
void estimateCost(rentalCar cars[]);
void mostExpensive(rentalCar cars[]);
void available(rentalCar cars[]);

int main()
{
	//array of rental cars
	rentalCar cars[10];
	int selection;
	//true if user has entered file
	bool readFile = false;
	
	//display menu
	do {
        	cout << "  Rental Car Menu" << endl;
        	cout << "  ============================== " << endl;
       		cout << "  1.  Read Data From File"<< endl;
       		cout << "  2.  Print All Car Data"<< endl;
		cout << "  3.  Estimate Car Rental Cost"<< endl;
		cout << "  4.  Find Most Expensive Car"<< endl;
		cout << "  5.  Print Only Available Cars"<< endl;
        	cout << "  6.  Exit" << endl;
        	cout << "  Enter your selection: ";
        	cin >> selection;
		cout << endl;

		//Menu selection
        	switch (selection)
        	{
            		case 1:
               			readFromFile(cars, readFile);
                		break;			
           		case 2:
				if(readFile == true)
				{
                			printAllData(cars);
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
			case 3:
				if(readFile == true)
				{                		
					estimateCost(cars);
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
			case 4:
				if(readFile == true)
				{ 
                			mostExpensive(cars);
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
			case 5:
				if(readFile == true)
				{ 
                			available(cars);
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
			case 6:
                		break;
            		default:
               	 		cout << "Input not recognized" << endl;
                		break;
        	}
    	}while (selection != 6 );

	return 0;
}

//has user enter in file and reads cars into array
void readFromFile(rentalCar cars[], bool &readFile)
{
	char file[20];
	ifstream fin;

	cout << "  Please enter the file name: ";
	cin >> file;
	
	fin.open(file);
	for(int i = 0; i < 10; i++)
	{
		fin >> cars[i].year;		
		fin >> cars[i].make;
		fin >> cars[i].model;
		fin >> cars[i].price;
		fin >> cars[i].available;
	}
	readFile = true;
	cout << endl;
	fin.close();
}

//prints out all car data
void printAllData(rentalCar cars[])
{
	for(int i = 0; i < 10; i++)
	{
		cout << cars[i].year <<" ";		
		cout << cars[i].make <<" ";
		cout << cars[i].model <<" ";
		cout << "$" << cars[i].price <<" per day ";
		cout << "Available: " << boolalpha << cars[i].available <<" ";
		cout << endl;
	}
	cout << endl;
}

//estimates the cost of a car set by the user based on days user enters
void estimateCost(rentalCar cars[])
{
	int carNumber;
	int days;
	float estimatedPrice;
	cout << "  Please enter the car number: ";
	cin >> carNumber;
	cout << "  Please enter the number of days: ";
	cin >> days;
	estimatedPrice = cars[carNumber-1].price * days;
	cout << "  Estimated Price: $" << estimatedPrice << endl << endl;
}

//finds the most expensive car
void mostExpensive(rentalCar cars[])
{
	int mostExpensiveNumber;
	float highestPrice = 0.0;
	for(int i = 0; i < 10; i++)
	{
		if(cars[i].price > highestPrice)
		{
			mostExpensiveNumber = i;
			highestPrice = cars[i].price;
		}
	}
	cout << "  Most Expensive Car: ";
	cout << cars[mostExpensiveNumber].year <<" ";		
	cout << cars[mostExpensiveNumber].make <<" ";
	cout << cars[mostExpensiveNumber].model <<" ";
	cout << "$" << cars[mostExpensiveNumber].price <<" per day ";
	cout << "Available: " << boolalpha << cars[mostExpensiveNumber].available <<" ";
	cout << endl << endl;
}

//prints only available cars
void available(rentalCar cars[])
{
	for(int i = 0; i < 10; i++)
	{
		if(cars[i].available == true)
		{
			cout << cars[i].year <<" ";		
			cout << cars[i].make <<" ";
			cout << cars[i].model <<" ";
			cout << "$" << cars[i].price <<" per day ";
			cout << "Available: " << boolalpha << cars[i].available <<" ";
			cout << endl;
		}
	}
	cout << endl;
}
