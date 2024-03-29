#include <iostream>
#include <fstream>
#include "Agency.h"

using namespace std;

//constructor
Car::Car()
{
	make = new char[20];
	model = new char[20];
	year = 0;
	price = 0.00;
	available = false;
}

//constructor with parameters
Car::Car(char * newMake, char * newModel, int newYear, float newPrice, bool availability)
{
	//Make
	make = new char[20];
	setMake(newMake);

	//Model
	model = new char[20];
	setModel(newModel);

	setYear(newYear);
	setPrice(newPrice);
	setAvailable(availability);
}

//constructor with constant car
Car::Car(const Car& car)
{
	char * newMake = car.getMake();
	char * newModel = car.getModel();

	//Make
	make = new char[20];
	setMake(newMake);

	//Model
	model = new char[20];
	setModel(newModel);

	setYear(car.getYear());
	setPrice(car.getPrice());
	setAvailable(car.getAvailable());
}

//deallocates memory
Car::~Car()
{
	delete[] make;
	delete[] model;

	make = NULL;
	model = NULL;
}

//copies car
void Car::copy(Car car)
{
	char * makeptr = car.getMake();
	char * modelptr = car.getModel();

	//Make
	setMake(makeptr);

	//Model
	setModel(modelptr);

	setYear(car.getYear());
	setPrice(car.getPrice());
	setAvailable(car.getAvailable());
}

//prints out all values in car
void Car::print() const
{
	cout << make << " ";
	cout << model << " ";
	cout << year << " ";
	cout << "$" << price << " per day ";
	cout << "Available: " << boolalpha << available << " ";
}

char * Car::getMake() const
{
	return make;
}

char * Car::getModel() const
{
	return model;
}

int Car::getYear() const
{
	return year;
}

float Car::getPrice() const
{
	return price;
}

bool Car::getAvailable() const
{
	return available;
}

void Car::setMake(char * newMake)
{
	char * makeO = make;
	while(*newMake != '\0')
	{
		*make = *newMake;
		make++;
		newMake++;
	}
	*make = '\0';
	make = makeO;
}

void Car::setModel(char * newModel)
{
	char * modelO = model;
	while(*newModel != '\0')
	{
		*model = *newModel;
		model++;
		newModel++;
	}
	*model = '\0';
	model = modelO;
}

void Car::setYear(int newYear)
{
	year = newYear;
}

void Car::setPrice(float newPrice)
{
	price = newPrice;
}

void Car::setAvailable(bool newAvailable)
{
	available = newAvailable;
}

//default constructor
Agency::Agency() 
{
	name = new char [20];
	zipcode = new int [5];
	inventory = new Car[15];
}

//constructor with constant agency
Agency::Agency(const Agency& agency)
{
	name = new char [20];
	zipcode = new int [5];
	inventory = new Car[15];

	char * nameptr = agency.name;
	int * zipptr = agency.zipcode;
	Car * inventoryptr = agency.inventory;

	char * nameO = name;
	int * zipO = zipcode;
	Car * inventoryO = inventory;

	while(*nameptr != '\0')
	{
		*name = *nameptr;
		name++;
		nameptr++;
	}

	for(int i = 0; i < 5; i++)
	{
		*zipcode = *zipptr;
		zipcode++;
		zipptr++;
	}

	for(int i = 0; i < 15; i++)
	{
		*inventory = *inventoryptr;
		inventory++;
		inventoryptr++;
	}

	name = nameO;
	zipcode = zipO;
	inventory = inventoryO;
}

//destructor - deallocates memory
Agency::~Agency()
{
	delete[] name;
	delete[] zipcode;
	delete[] inventory;

	name = NULL;
	zipcode = NULL;
	inventory = NULL;
}

void Agency::readInData(char * filename)
{
	ifstream fin;
	fin.open(filename);
	char zipchar;
	int zipint;
	int * zipO = zipcode;
	char * temp = new char[20];
	float newPrice;
	int newYear;
	bool availability;
	Car * cars = inventory;
	Car * carO = cars;

	fin >> name;
	
	//reads in zipcode
	for(int i = 0; i < 5; i++)
	{
		fin >> zipchar;
		zipint = (zipchar - 48);
		*zipcode = zipint;
		zipcode++;
	}
	zipcode = zipO;

	//loops through cars and sets values
	for(int i = 0; i < 15; i++)
	{
		fin >> newYear;
		(*cars).setYear(newYear);
		fin >> temp;
		(*cars).setMake(temp);
		fin >> temp;
		(*cars).setModel(temp);
		fin >> newPrice;
		(*cars).setPrice(newPrice);
		fin >> availability;
		(*cars).setAvailable(availability);

		cars++;
	}
	cars = carO;

	delete[] temp;
	temp = NULL;
}

//prints agency
void Agency::print() const
{
	cout << name << " ";

	Car * carptr = inventory;
	int * zipptr = zipcode;

	for(int i = 0; i < 5; i++)
	{
		cout << *zipptr;
		zipptr++;
	}
	zipptr = zipcode;

	cout << endl;

	//prints each car
	for(int i = 0; i < 15; i++)
	{
		(*carptr).print();
		cout << endl;
		carptr++;
	}
	carptr = inventory;
}

//only prints available cars
void Agency::printAvailableCars() const
{
	Car * cars = inventory;
	Car * carsO = cars;
	for(int i = 0; i < 15; i++)
	{
		if((*cars).getAvailable())
		{
			(*cars).print();
			cout << endl;
		}
		cars++;
	}
	cars = carsO;
}

void Agency::findMostExpensive() const
{
	Car * cars = inventory;
	Car * carO = cars;
	int mostExpensiveNumber;
	float highestPrice = 0.0;
	
	//loops through all cars to find position of most expensive
	for(int i = 0; i < 15; i++)
	{
		if((*cars).getPrice() > highestPrice)
		{
			mostExpensiveNumber = i;
			highestPrice = (*cars).getPrice();
		}
	}
	cars = carO;

	//moves pointer to most expensive
	for(int i = 0; i < mostExpensiveNumber; i++)
	{
		cars++;
	}
	cout << "Most Expensive Car: ";
	(*cars).print();
	cout << endl;
	cars = carO;
}

float Agency::estimateCost(int carN, int days) const
{
	Car * car = inventory;
	Car * carO = car;
	float cost;

	//loops to car desired to print
	for(int i = 0; i < (carN-1); i++)
	{
		car++;
	}
	//calculates cost
	cost = ((*car).getPrice()) * days;
	car = carO;
	return cost;
}

void Agency::sortByMake()    // alphabetical
{
	Car temp;
	Car car1;
	Car * cars = inventory;
	Car * carsOriginal = cars;
	char * car1Make;
	char * car2Make;
	bool swap = true;

	//true if there was a swap during the last pass
	while(swap)
	{
		swap = false;
		//loops through all cars except the last
		for(int i = 0; i < 14; i++)
		{
			car1Make = (*cars).getMake();
			car1.copy(*cars);		
			cars++;
			car2Make = (*cars).getMake();
			//compares next letters if first letters are the same
			while(*car1Make == *car2Make && (*car1Make != '\0' || *car2Make != '\0'))
			{
				car1Make++;
				car2Make++;
			}
			//checks if a swap is necessary and swaps them
			if(*car2Make < *car1Make)
			{
				temp.copy(*cars);
				(*cars).copy(car1);
				cars--;
				(*cars).copy(temp);
				cars++;
				swap = true;
			}
		}
		cars = carsOriginal;
	}
}

void Agency::sortByPrice()   // highest to lowest
{
	Car * cars = inventory;
	float currPrice;
	float highPrice;
	int highCar;
	Car temp;
	Car * sortCars;

	//loops through all cars except last
	for(int i = 0; i < 14; i++)
	{
		sortCars = cars;
		currPrice = (*cars).getPrice();
		highPrice = (*cars).getPrice();
		//loops through all cars
		for(int j = i; j < 15; j++)
		{
			//checks if a car has a higher price
			if((*sortCars).getPrice() > highPrice)
			{
				highPrice = (*sortCars).getPrice();
				highCar = j;
			}
			sortCars++;
		}
		sortCars = cars;
		//checks if a car has a higher price than the current car
		if(highPrice > currPrice)
		{
			//puts pointer to highest car
			for(int j = i; j < highCar; j++)
			{
				sortCars++;
			}
			//switches cars
			temp.copy(*sortCars);
			(*sortCars).copy(*cars);
			(*cars).copy(temp);
		}
		cars++;
	}
	cars = inventory;
	sortCars = cars;
}

void Agency::searchByMake(char * makeName) const
{
	char * makeOriginal = makeName;
	Car * car = inventory;

	char * carMake;

	bool same;

	//loops through all cars
	for(int i = 0; i < 15; i++)
	{
		same = true;
		carMake = (*car).getMake();
			
		//checks if name is the same
		while(*makeName != '\0')
		{
			if(*makeName != *carMake)
			{
				same = false;
			}
			makeName++;
			carMake++;
		}
		//prints if car has same make as search
		if(same)
		{
			(*car).print();
			cout << endl;
		}
		makeName = makeOriginal;
		car++;
	}
	car = inventory;
}
