//Program execution begins and ends there.
//Completed by Ayomide Ogunseye May 6, 2025


//Declare Headers
#include <iostream>
#include <string>
#include <iomanip>
#include "Windows.h"
#include <cstdlib>
#include <time.h> 
#include <cstring>
#include <cctype>
//Inherit the SimpleVector class
#include "SimpleVector.h"
using namespace std;

//Random number generator function to get a random number.
int generateRandomNum(int lowerLimit, int upperLimit)
{

	int number = 0;
	do
	{
		number = rand() % upperLimit + 1;
	} while (number < lowerLimit);
	return number;
}

//Main function
int main()
{
	cout << "\nThe Project demonstrated push_back function should accept"
		 << "\nan argument and insert its value at the end of the array"
		 << "\nthat has been created. the pop_back function should accept"
		 << "\nno argument and remove the last element from the array.\n\n";


	int index = 0;  //Used to loop through vector
	int usersize = 0; //Holds user entered vector size
	int actualsize = 0; //Holds the size of the vector after modification
	int intNum; //Integer number to hold to push_back
	double doubleNum; //Double number to hold to push_back
	char userResponse = 'Y';
	srand(time(NULL));
	while (toupper(userResponse) == 'Y')
	{
		//Prompt user for size of vector
		cout << "Enter number of elements to put in a vector(between 2 and 20): ";
		cin >> usersize;
		cout << "A vector of integers will be created first\n";
		SimpleVector<int> intTable(usersize);  //Declare an object that will create the vector
		//Fill the vector with values.
		for (index = 0; index < usersize; index++)
		{
			intTable[index] = index * generateRandomNum(1, 20);
		}
		cout << "\nVector created: ";
		cout << "The contents of the array are: \n";
		//get the size of the vector
		actualsize = intTable.size();
		//Print the vector
		for (index = 0; index < actualsize; index++)
		{
			cout << intTable[index] << " ";
		}
		cout << "\n";
		//User will be prompted to enter a value to put in the vector
		cout << "Enter a whole number to insert at the end of the vector(decimal values will be rounded down): ";
		cin >> intNum;
		cin.ignore(80, '\n');
		intNum = static_cast<int>(intNum);
		cout << "\nCalling push_back function to insert the value\n";
		intTable.push_back(intNum);
		cout << "The new vector values are: \n";
		actualsize = intTable.size();
		for (index = 0; index < actualsize; index++)
		{
			cout << intTable[index] << " ";
		}
		cout << "\n\nNow calling pop_back function to remove the last added value";
		try
		{
			intTable.pop_back();
		}
		catch (char* exceptionString)
		{
			cout << exceptionString;
		}
		cout << "\nThe new vector values are: \n";
		actualsize = intTable.size();
		for (index = 0; index < actualsize; index++)
		{
			cout << intTable[index] << " ";
		}

		cout << "\n\nExercise will be repeated with decimal values now\n";
		//Prompt user for size of vector
		cout << "Enter number of elements to put in a vector(between 2 and 20): ";
		cin >> usersize;
		cout << "\nA vector of decimals will be created first\n";
		SimpleVector<double> doubleTable(usersize);
		//Fill the vector with values.
		for (index = 0; index < usersize; index++)
		{
			doubleTable[index] = index * generateRandomNum(1, 20) * 0.2;
		}
		cout << "Vector created: ";
		cout << "The contents of the array are: \n";
		actualsize = doubleTable.size();
		for (index = 0; index < actualsize; index++)
		{
			cout << doubleTable[index] << " ";
		}
		cout << "\n";
		//User will be prompted to enter a value to put in the vector
		cout << "Enter a decimal number to insert at the end of the vector: ";
		cin >> doubleNum;
		cin.ignore(80, '\n');
		doubleNum = static_cast<double>(doubleNum);
		cout << "Calling push_back function to insert the value\n";
		doubleTable.push_back(doubleNum);
		cout << "\nThe new vector values are: \n";
		actualsize = doubleTable.size();
		for (index = 0; index < actualsize; index++)
		{
			cout << doubleTable[index] << " ";
		}
		cout << "\n\nNow calling pop_back function to remove the last added value\n";
		try
		{
			doubleTable.pop_back();
		}
		catch (char* exceptionString)
		{
			cout << exceptionString;
		}
		cout << "\nThe new vector values are: \n";
		actualsize = doubleTable.size();
		for (index = 0; index < actualsize; index++)
		{
			cout << doubleTable[index] << " ";
		}

		cout << "\nWould you like to repeat (y/n)? :";
		cin >> userResponse;
	}

	return 0;

}

