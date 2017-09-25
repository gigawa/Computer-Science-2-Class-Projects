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

struct rentalAgency {
	char name[20];
	//int zip;
	rentalCar cars[5];
};

int main()
{
	rentalAgency agency[3];
	rentalAgency *agencyptr;
	rentalCar *carptr;
	agencyptr = &agency[0];
	carptr = (*agencyptr).cars;
	char *nameptr = agency[0].name;
	
	char file[20];
	char zipChar;
	ifstream fin;
	
	fin.open("locationDataT");

	for(int j = 0; j < 3; j++)
	{
		nameptr = agency[j].name;
		carptr = (*agencyptr).cars;
		fin >> agency[j].name;
		cout << agency[j].name;
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
	for(int k = 0; k < 3; k++)
	{
		agencyptr--;
	}
	for(int j = 0; j < 3; j++)
	{
		nameptr = agency[j].name;
		cout << agency[j].name;
	}
	cout << endl;
	fin.close();
}
