//MAIN FILE
//Completed by Ayomide Ogunseye Apr 30, 2025
#include <iostream>
#include "Essay.h"
using namespace std;

int main()
{
	char choice;		//Take user input to rerun do-while loop

	cout << "\t\t\t***********\n"
		 << "\t\t\t* Essay Class *\n"
		 << "\t\t\t***********\n";
	do{
		cout << "\tThe Essay class should determine the grade a student\n"
			 << "\treceives on an essay. The student's essay score can be\n"
			 << "\tup to 100, and it's determined in the following manner.\n\n"
			 << "\t >- Grammar : 30 points\n"
			 << "\t >- Spelling : 20 points\n"
			 << "\t >- Correct length : 20 points\n"
			 << "\t >- Content : 30 points\n\n";
		Essay report;
		double points;

		// Assign grammer points.
		cout << "How many grammer points did the student earn? (0 - 30): ";
		cin >> points;
		while (points < 0 || points > 30)
		{
			cout << "Enter a number from 0 through 30: ";
			cin >> points;
		}
		report.setGrammerPoints(points);

		// Assign spelling points.
		cout << "How many spelling points did the student earn?  (0 - 20): ";
		cin >> points;
		while (points < 0 || points > 20)
		{
			cout << "Enter a number from 0 through 20: ";
			cin >> points;
		}
		report.setSpellingPoints(points);

		// Assign length points.
		cout << "How many points for length did the student earn?  (0 - 20): ";
		cin >> points;
		while (points < 0 || points > 20)
		{
			cout << "Enter a number from 0 through 20: ";
			cin >> points;
		}
		report.setLengthPoints(points);

		// Assign content points.
		cout << "How many points for content did the student earn?  (0 - 30): ";
		cin >> points;
		while (points < 0 || points > 30)
		{
			cout << "Enter a number from 0 through 30: ";
			cin >> points;
		}
		report.setContentPoints(points);

		// Display the scores and grade.
		cout << "Grammer points: " << report.getGrammerPoints() << endl;
		cout << "Spelling points: " << report.getSpellingPoints() << endl;
		cout << "Length points: " << report.getLengthPoints() << endl;
		cout << "content points: " << report.getContentPoints() << endl;
		cout << "Overall score: " << report.getScore() << endl;
		cout << "Grade: " << report.getLetterGrade() << endl;

		//Ask the user if they want to run the program again
		cout << "Would you like to run the program again (Y/N)?";
		cin >> choice;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');	//Clear Buffer
		cout << "\n\n";
		system("cls");
	} while (tolower(choice) == 'y');

	return 0;
}