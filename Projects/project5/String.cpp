#include<iostream>
#include "String.h"

using namespace std;

void String::initialize(char * string) 
{
	char * stringOriginal = string;
	wordLength = 0;
	buffer = string;

	//gets length needed for word
	wordLength = length();

	//allocates memory for buffer
	buffer = new char [wordLength+1];
	char * original = buffer;

	//copies word into buffer
	while(*string != '\0')
	{
		*buffer = *string;
		buffer++;
		string++;
	}
	*buffer = '\0';
	string = stringOriginal;
	buffer = original; 
}

void String::deallocate() 
{
	//deallocates memory for buffer
	delete[] buffer;
	buffer = NULL;
}

void String::copy(const String& string) 
{
	char * stringptr = string.buffer;
	char * original = buffer;

	//sets wordLength if needed
	if(String().wordLength != wordLength)
	{
		delete[] buffer;
		wordLength = string.wordLength;
		buffer = new char [wordLength+1];
		original = buffer;
	}

	//copies word into buffer
	while(*stringptr != '\0')
	{
		*buffer = *stringptr;
		stringptr++;
		buffer++;
	}

	buffer = original;
}

int String::length() 
{
	char * original = buffer;
	int theLength = 0;

	//counts length of word
	while(*buffer != '\0')
	{
		theLength++;
		buffer++;
	}
	buffer = original;

	return theLength;
}

void String::concat(const String& string)
{
	char * stringptr = string.buffer;
	char * stringOriginal = string.buffer;
	char * temp = buffer;

	char * tempOriginal = temp;

	//sets wordLength to new length
	wordLength = wordLength + string.wordLength;

	//allocates memory for buffer
	buffer = new char[wordLength+1];
	char * original = buffer;

	//copies temp into buffer
	while(*temp != '\0')
	{
		*buffer = *temp;
		buffer++;
		temp++;
	}
	*buffer = '\0';

	temp = tempOriginal;

	delete[] temp;

	//adds new string to buffer
	while(*stringptr != '\0')
	{
		*buffer = *stringptr;
		buffer++;
		stringptr++;
	}
	stringptr = stringOriginal;
	*buffer = '\0';
	buffer = original;
}

int String::compare(const String& string) 
{
	char * original = buffer;
	char * ptr = new char [string.wordLength + 1];
	char * ptrOriginal = ptr;
	ptr = string.buffer;
	int comparision = 0;
	int s1 = 0;
	int s2 = 0;

	//gets size of buffer
	while(*buffer != '\0')
	{
		s1 += *buffer;
		buffer++;
	}

	//gets size of other string
	while(*ptr != '\0')
	{
		s2 += *ptr;
		ptr++;
	}

	//compares sizes
	if(s1 > s2)
	{
		comparision = -1;
	}else if(s1 < s2)
	{
		comparision = 1;
	}else if(s1 == s2)
	{
		comparision = 0;
	}

	ptr = ptrOriginal;
	
	delete[] ptr;
	ptr = NULL;

	buffer = original;

	return comparision;
}

void String::print() 
{
	//prints string
	cout << buffer << endl;
}
