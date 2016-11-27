/*
Mo Rahman
10/14/2016 15:57 -- 10/27/16 20:16
Lab# 3 Pointers
Create a program that will take store a number of values from the user,
as well as names along with those values; no matter how great the number may be.
Scores must be integers ranging from 0 to 100; a name must accompany every score.
*/

#include<iostream>
#include<iomanip>		//For staticcast, set precision
//#include<cstring>		//For strcmp
#include<string>

//----------------------PROTOTYPES--------------------------------------------------

//Args:namesPtr, scoresPtr, numOfContestants, scoreOfContestants, 
void collectData(std::string*, float*, short, short);
//Passes numOfContestants, averageOfScores, scoresPtrArray, and total
float average(short, float, float*, float);
void display(short,float,std::string*,float*);

using namespace std;

unsigned short int main()
{
	//To store the number of contestants
	short numberOfContestants = 0;
	float averageOfScores = 0.00, total = 0; short counter = 0;
	
	//Pointer to hold the SCORES of the contestants
	float *scoresPtr;
	
	//Pointer to hold the NAMES of the contestants
	string *namesPtr;
	char tryAgain;
	
	//To hold the user input for "scores"
	short scoreOfContestants = 0;

	//---------------------------------------------------------------------------------------------
	
	//Inform the user about the purpose of the program
	cout << "Contest score simulator: \n";

	cout << "This program will store the names of a number of contestants and their scores. \n";

	cout << "An average will be calculated, \n"
		<< "it will be indicated weather or not contestant's score is above or below average. \n";

	cout << "The scores recorded may be anywhere from 0 to 100." << endl;

	//Ask the user for the number of contestants
	cout << "How many contestants are there to be in the contest? ";

	do
	{
		cin >> numberOfContestants;

		while (!(cin >> numberOfContestants) || numberOfContestants < 2)
		{
			
			if (cin.fail())
			{
				cout << "\nMust be an integer (number) value : ";
				cin.clear();
				cin.ignore(42, '\n');
			}
			else if (numberOfContestants < 2)
			{
				cout << endl << "The number of contestants must be a positive number of at least two (2). \n";
				cout << "How many contestants are there to be in the contest? ";
			}
			
		} 
		
		cout << endl;

		//Create a string pointer array
		scoresPtr = new float[numberOfContestants]; namesPtr = new string[numberOfContestants];
		
		//Function calls
		collectData(namesPtr, scoresPtr, numberOfContestants, scoreOfContestants);
		
		averageOfScores = average( numberOfContestants, averageOfScores, scoresPtr, total);

		display(numberOfContestants, averageOfScores, namesPtr, scoresPtr);

		//Ask the user if they want to try again, and
		cout << "Would you like to try again? \n";
		cout << "Please enter Y or N: \n";
		cin >> tryAgain;
		while (toupper(tryAgain) != 'Y' && toupper(tryAgain) != 'N')
		{
			cout << "Please enter Y or N: \n";
			cin >> tryAgain;
		}

		delete[] namesPtr;
		delete[] scoresPtr;

	} while (toupper(tryAgain) == 'Y');

	//system("pause");/*Not necessary with the do while loop in place*/
	return 1;
}

/****************************************************************************
*  The Functions for the COLLECTOR, AVARAGE, & DIAPLAY for values are below *
*****************************************************************************/

	/*Collects names (strings) and scores (integers) from the users and assigns them to
	their respective arrays*/
void collectData(string *namesPtr, float *scoresPtr, short numberOfContestants,
				short scoreOfContestants)
{
	cin.ignore();//Clear the previous buffer of cin
	//Collect names in the form a string (formally char arrays/c-strings)
	for (short counter = 0; counter != numberOfContestants; counter++)
	{
		cout << "What is the name of the contestant No. " << counter + 1 << "? : ";
		
		getline(cin, namesPtr[counter]);//Must include the element as well

	}cout << endl; //Skips line

	for (short counter = 0; counter != numberOfContestants; counter++)
	{
		cout << "What is the score of contestant No. " << counter + 1 << "? : ";
		cin >> scoreOfContestants;
		while (scoreOfContestants < 0 || scoreOfContestants > 100)
		{
			cout << "Scores must range from 0 to 100." << endl;
			cout << "What is the score of contestant No. " << counter + 1 << "? : ";
			cin >> scoreOfContestants;
		}
		scoresPtr[counter] = scoreOfContestants; cout << endl;
	}
}


float average(short numberOfContestants, float averageOfScores, float *scoresPtr, float total)
{
		for (short counter = 0; counter < numberOfContestants; counter++)
		{
                 //To see what the total is in the loop
			//cout << total <<" Is the current total. \n";
			total += scoresPtr[counter];
		}
		cout << total << " is the total of all scores. \n";
		averageOfScores = (total / numberOfContestants);

		cout << "There are " << numberOfContestants << " number of contestants. \n"
			<< "And " << setprecision(2) << fixed <<showpoint
			<< averageOfScores << " is the average of the scores.\n";

		cout << "-------------------------------------------------------\n";
	
	return averageOfScores;
}

void display(short numberOfContestants, float averageOfScores, string *namesPtr, float *scoresPtr)
{
	for (short counter = 0; counter != numberOfContestants; counter++)
	{
		cout << "No. " << counter + 1 << " " << namesPtr[counter]
			<< " " << scoresPtr[counter] << ". ";

		if (scoresPtr[counter] > averageOfScores)
			cout << "Their score was above average. \n";
		else if (scoresPtr[counter] < averageOfScores)
			cout << "Their score was below average. \n";
		else
			cout << "Their score was average. \n";
	}
	/*namesPtr[19] = "The Quick Brown Fox";
	cout << namesPtr[19] << endl;*/
}

/*******************************************************************
*[Revision One; No Functions, No Pointers]		10/25/16 -- 12:46  *
*[Revision Two; with Functions, with Pointers]	10/27/16 -- 20:16  *
* Logic Debug:									10/27/16 -- 20:22  *
* Input Validation finalization:				11/27/16 -- 03:29  *
********************************************************************/

//-------------------------------CODE-GRAVEYARD--------------------------------
//The size of the character array; can only hold 20 characters
//unsigned short int const CHAR_ARRAY_SIZE = 21;
//char* fltPtr = charArray;/*float scoresArray[CHAR_ARRAY_SIZE] = { NULL };*/
//string namesArray[CHAR_ARRAY_SIZE];
//char charArray[CHAR_ARRAY_SIZE] = { NULL };
//This is from a name collecting loop
//cin.getline(charArray, CHAR_ARRAY_SIZE);
//cout << counter << endl;
//namesPtr[counter] = charArray;