#include <iostream>
#include <fstream>
#include "String.h"

using namespace std;

void copy (String &, String &, String *);
void print (String &, String &, String *, int compareNumber);
void concat (String &, String &, String *);
void compare (String &, String &, int & compareNumber);
void deallocate (String &, String &, String *);

int main()
{
	char * temp = new char [50];
	int selection = 0;
	String string1;
	String string2;
	String * strings = new String [10];
	String * originalString = strings;
	int compareNumber = 0;

	//reads in file
	cout << "Please enter the file name: ";
	cin >> temp;

	ifstream fin;

	fin.open(temp);

	fin >> temp;
	
	string1.initialize(temp);
	fin >> temp;
	string2.initialize(temp);
	for(int i = 0; i < 10; i++)
	{
		fin >> temp;
		(*strings).initialize(temp);
		strings++;
	}

	strings = originalString;

	fin.close();

	//display menu
	do {
        	cout << "  String Menu" << endl;
        	cout << "  ============================== " << endl;
       		cout << "  1.  Copy strings"<< endl;
       		cout << "  2.  Concat strings"<< endl;
		cout << "  3.  compare strings"<< endl;
		cout << "  4.  print strings"<< endl;
		cout << "  5.  deallocate and exit"<< endl;
        	cout << "  Enter your selection: ";
        	cin >> selection;
		cout << endl;

		//Menu selection
        	switch (selection)
        	{
            		case 1:
               			copy(string1, string2, strings);
                		break;			
           		case 2:
				concat(string1, string2, strings);
                		break;
			case 3:
				compare(string1, string2, compareNumber);
                		break;
			case 4:
				print(string1, string2, strings, compareNumber);
                		break;
			case 5:
                		break;
            		default:
               	 		cout << "Input not recognized" << endl;
                		break;
        	}
    	}while (selection != 5 );

	//deallocates all strings before exit
	deallocate(string1, string2, strings);

	delete[] temp;
	temp = NULL;

	delete[] strings;
	strings = NULL;

	return 0;
}

void copy (String & string1, String & string2, String * strings)
{
	//copies third element of string array into 4th element
	String * stringOriginal = strings;
	String * strings1;
	for(int i = 0; i < 3; i++)
	{
		strings++;
	}
	strings1 = strings;
	strings++;
	(*strings1).copy(*strings);
	strings = stringOriginal;

	//copies string2 into string1
	string1.copy(string2);
}

void concat (String & string1, String & string2, String * strings)
{
	//concats string2 into string1
	string1.concat(string2);

	//copies 7th element of string array into 8th element
	String * stringOriginal = strings;
	String * strings1;
	for(int i = 0; i < 7; i++)
	{
		strings++;
	}
	strings1 = strings;
	strings++;
	(*strings1).concat(*strings);
	strings = stringOriginal;
}

void compare (String & string1, String & string2, int & compareNumber)
{
	//compares string1 to string2
	compareNumber = string1.compare(string2);
}

void print (String & string1, String & string2, String * strings, int compareNumber)
{
	String * stringptr = strings;

	//prints string1 and string2
	string1.print();
	string2.print();

	//prints array of strings
	for(int i = 0; i < 10; i++)
	{
		(*strings).print();
		strings++;
	}
	strings = stringptr;

	//prints number returned by compare
	cout << "Compare: " << compareNumber << endl;
}

void deallocate (String & string1, String & string2, String * strings)
{
	String * stringptr = strings;

	//deallocates string1 and string2
	string1.deallocate();
	string2.deallocate();

	//deallocates array of strings
	for(int i = 0; i < 10; i++)
	{
		(*strings).deallocate();
		strings++;
	}
	strings = stringptr;
}
