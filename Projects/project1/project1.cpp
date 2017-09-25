#include <iostream>
#include <fstream>

using namespace std;

#define numberNames 10
#define maxLetters 20

void compare(char nameArray[][maxLetters]);
void copy(char nameArray[][maxLetters], int wordNumber);

int main()
{
	char inputFile[maxLetters];
	char outputFile[maxLetters];
	char nameArray[numberNames][maxLetters];
		
	ifstream fin;
	ofstream fout;

	cout << "Please enter the input file name: ";
	cin >> inputFile;

	cout << "Please enter the output file name: ";
	cin >> outputFile;

	//opens files specified by user
	fin.open(inputFile);
	fout.open(outputFile);

	cout << "\nUnsorted names: " << endl;

	for(int i = 0; i < numberNames; i++)
	{
		fin >> nameArray[i];
		cout << nameArray[i] <<endl;
	}
	
	//passes nameArray to the function compare to sort the list of names
	compare(nameArray);

	cout << "\nSorted names: " << endl;
	
	//prints sorted list of names to terminal and file
	for(int i = 0; i < numberNames; i++)
	{
		cout << nameArray[i] <<endl;
		fout << nameArray[i] <<endl;
	}

	//closes files
	fin.close();
	fout.close();

	return 0;
}

void compare(char nameArray[][maxLetters])
{
	bool sort = true;
	int j = 0;
	//sort = true when the loop has had to sort during the last loop meaning it needs to run again
	while(sort == true) 
	{
		sort = false;
		for(int i = 0; i < (numberNames-1); i++)
		{
			j = 0;
			//checks if next word's letter at 'j' is equivalent to the current word's letter at 'j'
			while(nameArray[i+1][j] == nameArray[i][j])
			{
				j++;
			}
			//checks if next word belongs above current in the sorted list
			if(nameArray[i+1][j] < nameArray[i][j])
			{
				copy(nameArray, i);
				sort = true;
			}
		}
	}

}

void copy(char nameArray[][maxLetters], int wordNumber)
{
	char temp[maxLetters];
	//switches next word with current word
	for(int i = 0; i < maxLetters; i++)
	{
		temp[i] = nameArray[wordNumber][i];
		nameArray[wordNumber][i] = nameArray[wordNumber+1][i];
		nameArray[wordNumber+1][i] = temp[i];
	}

}
