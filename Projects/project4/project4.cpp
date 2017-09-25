#include <iostream>
#include <fstream>

using namespace std;

struct Pieces
{
	char * word;
	int jump;
};

int strLength(char * temp);
void strCopy(char * temp, char * string);
int decode(Pieces * piecesptr, int * keys, int keyNumber, int wordNumber, bool decoded, char * message, char * messageOr);
void strConcat(char * temp, int keyNumber, char * message, char * messageOr);

int main()
{
	//number of words
	int wordNumber;
	//number of keys
	int keyNumber;
	ifstream fin;
	int fileLength;
	//temporary array
	char * temp = new char [20];
	//length of word
	int wordLength;
	//length of total message
	int messageLength;
	//true if decode() has been run and a length is found
	bool decoded = false;

	cout << "Please enter the file name: ";
	cin >> temp;

	//length of file entered by user
	fileLength = strLength(temp);
	char * file = new char [fileLength];
	
	strCopy(temp, file);

	//opens file
	fin.open(file);

	fin >> wordNumber;
	fin >> keyNumber;

	//dynamically allocates piecesptr and keys along with setting home pointer
	Pieces * piecesptr = new Pieces [wordNumber];
	int * keys = new int [keyNumber];
	Pieces * originalPieces = piecesptr;
	int * originalKey = keys;

	//reads in words
	for(int i = 0; i < wordNumber; i++)
	{
		fin >> temp;
		wordLength = strLength(temp);
		(*piecesptr).word = new char [wordLength];	
		strCopy(temp, (*piecesptr).word);
		fin >> (*piecesptr).jump;
		piecesptr++;
	}

	//reads in keys
	for(int i = 0; i < keyNumber; i++)
	{
		fin >> *keys;
		keys++;
	}
	fin.close();

	keys = originalKey;
	piecesptr = originalPieces;
	
	char * message = NULL;
	char * messageOr = message;

	//gets length of total message
	messageLength = decode(piecesptr, keys, keyNumber, wordNumber, decoded, message, messageOr);

	decoded = true;
	message = new char [messageLength];
	messageOr = message;

	//decodes the message
	decode(piecesptr, keys, keyNumber, wordNumber, decoded, message, messageOr);

	cout << message << endl;

	//deallocates words
	for(int i = 0; i < wordNumber; i++)
	{
		delete[] (*piecesptr).word;
		(*piecesptr).word = NULL;
		piecesptr++;
	}

	piecesptr = originalPieces;
	keys = originalKey;

	//deallocates pointers
	delete[] piecesptr;
	piecesptr = NULL;

	delete[] keys;
	keys = NULL;

	delete[] temp;
	temp = NULL;

	delete[] file;
	file = NULL;

	delete[] message;
	message = NULL;

	return 0;
}

//length of string
int strLength(char * temp)
{
	int length = 0;

	while(*temp != '\0')
	{
		length++;
		temp++;
	}

	return length;
}

//copies string
void strCopy(char * temp, char * string)
{
	char * tempOr = temp;
	temp = tempOr;
	
	while(*temp != '\0')
	{
		*string = *temp;
		string++;
		temp++;
	}
	temp = tempOr;
}

//combines string into message
void strConcat(char * temp, int keyNumber, char * message, char * messageOr)
{
	while(*temp != '\0')
	{
		*message = *temp;
		temp++;
		message++;
	}
	*message = ' ';
	message = messageOr;
}

int decode(Pieces * piecesptr, int * keys, int keyNumber, int wordNumber, bool decoded, char * message, char * messageOr)
{
	int i = 0;
	int moveLength = 0;
	Pieces * piecesOriginal = piecesptr;
	int length = 0;
	int lastLength = 0;

	//runs until reaches end of keys
	while(i < keyNumber)
	{
		for(int j = 0; j < *keys; j++)
		{
			piecesptr++;
		}
		moveLength = *keys;
		//checks if should stop moving
		while(moveLength != 0)
		{
			moveLength = (((*piecesptr).jump)+(*keys));
			//checks if it should wrap
			if(moveLength > (wordNumber-1))
			{
				moveLength -= (wordNumber);
				piecesptr = piecesOriginal;
				for(int k = 0; k < moveLength; k++);
				{
					piecesptr++;
				}
			}else
			{
				moveLength -= (*keys);
			}
			for(int l = 0; l < moveLength; l++)
			{
				piecesptr++;
			}
			moveLength = (*piecesptr).jump;
		}
		length += strLength((*piecesptr).word);
		//if message length is known it adds the word to the message
		if(decoded == true)
		{
			for(int i = 0; i < lastLength; i++)
			{
				message++;
			}
			strConcat((*piecesptr).word, keyNumber, message, messageOr);
		}
		length++;
		keys++;
		piecesptr = piecesOriginal;
		i++;
		moveLength = 0;
		lastLength = length;
		message = messageOr;
	}
	length++;
	//returns the length of the total message
	if(decoded == false)
	{
		return length;
	}else
	{
		//ensures that null character is at end of message
		for(int i = 0; i < (length); i++)
		{
			message++;
		}	
		*message = '\0';
		return 0;
	}
}
