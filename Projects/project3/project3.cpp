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

//rental agency struct
struct rentalAgency {
	char name[20];
	int zip[5];
	rentalCar cars[5];
};

//function prototypes
void readFromFile(rentalCar *carptr, rentalAgency *agencyptr, bool &readFile, char *fileptr);
void printAllData(rentalCar *carptr, rentalAgency *agencyptr);
void estimateCost(rentalCar *carptr, rentalAgency *agencyptr);
void mostExpensive(rentalCar *carptr, rentalAgency *agencyptr);
void available(rentalCar *carptr, rentalAgency *agencyptr);
int findAgency(rentalCar *carptr, rentalAgency *agencyptr, char *targetptr, int agencyNumber);

int main()
{
	//array of rental cars
	int selection;
	//true if user has entered file
	bool readFile = false;
	char file[20];
	//pointer to file input by user
	char *fileptr = file;
	rentalAgency agency[3];
	//pointers to rental agency and cars
	rentalAgency *agencyptr;
	rentalCar *carptr;
	agencyptr = &agency[0];
	carptr = (*agencyptr).cars;
	
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
               			readFromFile(carptr, agencyptr, readFile, fileptr);
                		break;			
           		case 2:
				if(readFile == true)
				{
                			printAllData(carptr, agencyptr);
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
			case 3:
				if(readFile == true)
				{                		
					estimateCost(carptr, agencyptr);
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
			case 4:
				if(readFile == true)
				{ 
                			mostExpensive(carptr, agencyptr);
				}else
				{
					cout << "Please choose selection '1' to Read Data From File" << endl << endl;
				}
                		break;
			case 5:
				if(readFile == true)
				{ 
                			available(carptr, agencyptr);
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

//has user enter in file and reads cars and agencies through pointers
void readFromFile(rentalCar *carptr, rentalAgency *agencyptr, bool &readFile, char *fileptr)
{
	char zipChar;
	int zipint;
	int *zipptr = (*agencyptr).zip;
	ifstream fin;

	cout << "  Please enter the file name: ";
	cin >> fileptr;
	
	fin.open(fileptr);
	for(int j = 0; j < 3; j++)
	{
		carptr = (*agencyptr).cars;
		fin >> (*agencyptr).name;
		zipptr = (*agencyptr).zip;
		//reads and converts zipcode from char to int
		for(int j = 0; j < 5; j++)
		{
			fin >> zipChar;
			zipint = (zipChar - 48);
			*zipptr = zipint;			
			zipptr++;
		}
		//reads in car information
		for(int i = 0; i < 5; i++)
		{
			fin >> (*carptr).year;		
			fin >> (*carptr).make;
			fin >> (*carptr).model;
			fin >> (*carptr).price;
			fin >> (*carptr).available;
			carptr++;
		}
		agencyptr++;
	}
	readFile = true;
	cout << endl;
	fin.close();
}

//prints out all car data
void printAllData(rentalCar *carptr, rentalAgency *agencyptr)
{
	int *zipptr = (*agencyptr).zip;
	for(int j = 0; j < 3; j++)
	{
		carptr = (*agencyptr).cars;
		cout << (*agencyptr).name << " ";
		zipptr = (*agencyptr).zip;
		//prints out zipcode
		for(int i = 0; i < 5; i++)
		{
			cout << *zipptr;	
			zipptr++;
		}
		cout << endl;
		//prints out car data
		for(int i = 0; i < 5; i++)
		{
			cout << (*carptr).year <<" ";		
			cout << (*carptr).make <<" ";
			cout << (*carptr).model <<" ";
			cout << "$" << (*carptr).price <<" per day ";
			cout << "Available: " << boolalpha << (*carptr).available <<" ";
			cout << endl;
			carptr++;
		}
		agencyptr++;
		cout << endl;
	}
	cout << endl;
}

//estimates the cost of a car set by the user based on days user enters
void estimateCost(rentalCar *carptr, rentalAgency *agencyptr)
{
	int carNumber;
	int days;
	int agencyNumber;
	float estimatedPrice;
	char targetName[20];
	char *targetptr = targetName;

	//colls functon findAgency to determine which agency was input
	agencyNumber = findAgency(carptr, agencyptr, targetptr, agencyNumber);

	cout << "  Please enter the car number: ";
	cin >> carNumber;
	cout << "  Please enter the number of days: ";
	cin >> days;
	for(int j = 0; j < agencyNumber; j++)
	{
		agencyptr++;
	}
	cout << (*agencyptr).name;
	carptr = (*agencyptr).cars;
	for(int i = 0; i < carNumber-1; i++)
	{
		carptr++;
	}
	estimatedPrice = (*carptr).price * days;
	cout << "  Estimated Price: $" << estimatedPrice << endl << endl;
}

//finds the most expensive car
void mostExpensive(rentalCar *carptr, rentalAgency *agencyptr)
{
	int mostExpensiveNumber;
	int mostExpensiveAgency;
	float highestPrice = 0.0;
	int j = 0;
	int i = 0;
	rentalAgency *originalptr = agencyptr;

	//finds location of most expensive car
	for(int k = 0; k < 3; k++)
	{	
		carptr = (*agencyptr).cars;
		for(i = 0; i < 5; i++)
		{
			if((*carptr).price > highestPrice)
			{
				mostExpensiveNumber = i;
				mostExpensiveAgency = k;
				highestPrice = (*carptr).price;
			}
			carptr++;
		}
		agencyptr++;
	}
	
	//resets agencyptr to original position	
	agencyptr = originalptr;
	
	while(j < mostExpensiveAgency)
	{
		j++;
		agencyptr++;
	}

	j = 0;
	carptr = (*agencyptr).cars;

	while(j < mostExpensiveNumber)
	{
		j++;
		carptr++;
	}
	
	//prints most expensive car data
	cout << "  Most Expensive Car: ";
	cout << (*agencyptr).name << ": ";
	cout << (*carptr).year <<" ";		
	cout << (*carptr).make <<" ";
	cout << (*carptr).model <<" ";
	cout << "$" << (*carptr).price <<" per day ";
	cout << "Available: " << boolalpha << (*carptr).available <<" ";
	cout << endl << endl;
}

//prints only available cars
void available(rentalCar *carptr, rentalAgency *agencyptr)
{
	int *zipptr = (*agencyptr).zip;
	for(int j = 0; j < 3; j++)
	{	
		//prints agencies
		cout << (*agencyptr).name << " ";
		carptr = (*agencyptr).cars;
		zipptr = (*agencyptr).zip;
		for(int i = 0; i < 5; i++)
		{
			cout << *zipptr;	
			zipptr++;
		}
		cout << endl;
		for(int i = 0; i < 5; i++)
		{
			//determines and prints available cars
			if((*carptr).available == true)
			{
				cout << (*carptr).year <<" ";		
				cout << (*carptr).make <<" ";
				cout << (*carptr).model <<" ";
				cout << "$" << (*carptr).price <<" per day ";
				cout << "Available: " << boolalpha << (*carptr).available <<" ";
				cout << endl;
			}
			carptr++;
		}
		agencyptr++;
		cout << endl;
	}
	cout << endl;
}

//finds which agency was input by the user
int findAgency(rentalCar *carptr, rentalAgency *agencyptr, char *targetptr, int agencyNumber)
{
	cout << "  Please enter the agency name: ";
	cin >> targetptr;
	agencyNumber = 0;
	bool same;
	char *agencyName = (*agencyptr).name;
	char *targetOriginal = targetptr;
	
	//runs through the agencies
	for(int j = 0; j < 3 && same == false; j++)
	{
		//runs until reaches null character
		while(*agencyName != '\0')
		{
			same = true;
			//checks if letters match
			if(*agencyName != *targetptr)
			{
				same = false;
			}
			agencyName++;
			targetptr++;
		}
		//resets targetptr to original position
		targetptr = targetOriginal;
		if(same == false)
		{
			agencyptr++;
			agencyName = (*agencyptr).name;
			agencyNumber++;
		}
	}
	//returns the number of the agency
	return agencyNumber;
}
