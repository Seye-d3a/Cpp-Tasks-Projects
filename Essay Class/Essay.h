// Specification file for the Essay class
#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"

class Essay : public GradedActivity
{
private:
	double grammerPoints;			// To hold grammer points
	double spellingPoints;			// To hold spelling points
	double lengthPoints;			// To hold length points
	double contentPoints;			// To hold content points

public:
	// Default constructor
	Essay()
	{
		grammerPoints = 0.0; spellingPoints = 0.0;
		lengthPoints = 0.0; contentPoints = 0.0;
	}

	// Mutators
	void setGrammerPoints(double);
	void setSpellingPoints(double);
	void setLengthPoints(double);
	void setContentPoints(double);

	// Accessors
	double getGrammerPoints() const
	{
		return grammerPoints;
	}

	double getSpellingPoints() const
	{
		return spellingPoints;
	}

	double getLengthPoints() const
	{
		return lengthPoints;
	}

	double getContentPoints() const
	{
		return contentPoints;
	}

	virtual double getScore();
	virtual char getLetterGrade();
};

#endif