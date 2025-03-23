//This program calulates the average test score of 4 students/
#include <iostream>
#include <iomanip>  //enables numerical manipulation
using namespace std;

//function prototypes
void getScores(double[], int);
double TotalScore(const double[], int);
double getLowest(const double[], int);

int main()
{
    const int NumScore = 4;
    double scores[NumScore],
           total,
           lowest,
           average;
    
    cout << fixed << showpoint << setprecision(2);

    //Get the test scores from the user
    getScores(scores, NumScore);        

    //Get the total of the test scores
    total = TotalScore(scores,NumScore);

    //Get the lowest score
    lowest = getLowest(scores, NumScore);

    //Get the adjusted total
    total -= lowest;

    //calculate the average of the scores
    //Bear in mind, we now have 3 scores since we subtracted the lowest from the total
    average = total / (NumScore-1);

    //Display the average
    cout << "The average of your scores after dropping the lowest is " << average << "." << endl;

    return 0;
}

void getScores(double scores[], int size)
{
    //loop counter
    int index;

    //Get each test score
    for (index = 0; index < size; index++)
    {
        cout << "Enter Score for Test " << (index + 1) << ": ";
        cin >> scores[index];    
    }
}

double TotalScore(const double scores[], int size)
{
    double total = 0;
    for (int count = 0; count < size; count++)
    {
        total += scores[count];
    }

    return total;
}

double getLowest(const double scores[], int size)
{
    double lowest = scores[0];

    for (int count = 0; count < size; count++)
    {
        if (scores[count] < lowest)
            lowest = scores[count];
    }

    return lowest;
}
