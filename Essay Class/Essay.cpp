// Implementation file for the Essay class
#include <iostream>
#include "Essay.h"
using namespace std;

//******************************************
// setGrammerPoints member function        *
//******************************************

void Essay::setGrammerPoints(double p)
{
	// Validate the points.
	if (p < 0 || p > 30)
	{
		// Invalid data
		cout << "Invalid number of grammar points.\n";
		exit(EXIT_FAILURE);
	}

	// Assign the points.
	grammerPoints = p;
}

//******************************************
// setSpellingPoints member function       *
//******************************************

void Essay::setSpellingPoints(double p)
{
	// Validate the points.
	if (p < 0 || p > 20)
	{
		// Invalid data
		cout << "Invalid number of spelling points.\n";
		exit(EXIT_FAILURE);
	}

	// Assign the points.
	spellingPoints = p;
}

//******************************************
// setLengthPoints member function         *
//******************************************

void Essay::setLengthPoints(double p)
{
	// Validate the points
	if (p < 0 || p > 20)
	{
		// Invalid data
		cout << "Invalid number of length points.\n";
		exit(EXIT_FAILURE);
	}

	// Assign the points.
	lengthPoints = p;
}

//******************************************
// setContentPoints member function        *
//******************************************

void Essay::setContentPoints(double p)
{
	// Validate the points.
	if (p < 0 || p > 30)
	{
		// Invalid data
		cout << "Invalid number of content points.\n";
		exit(EXIT_FAILURE);
	}

	// Assign the points.
	contentPoints = p;
}

//*********************************************************
// getScore                                               *
//*********************************************************

double Essay::getScore()
{
	return grammerPoints + spellingPoints +
		lengthPoints + contentPoints;
}

//*********************************************************
// getLetterGrade                                         *
//*********************************************************

char Essay::getLetterGrade()
{
	// Add up all the points.
	score = getScore();

	// Return the letter grade as reported from
	// the base class function.
	return GradedActivity::getLetterGrade();
}