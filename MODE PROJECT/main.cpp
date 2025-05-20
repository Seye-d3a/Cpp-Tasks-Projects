//This program finds the mode of an array of numbers
#include <iostream>
#include <algorithm>        //Enables us to use sort function
using namespace std;

//function prototypes
void sortArray(int *arr, int);
int getmode(int [], int);
int StartOver();

int main()
{
    int *numbers = nullptr;  //to dynamically allocate an array. 
    int nums;               //number of values entered by user
    int index;             //counter
    int mode;             //variable to store most frequently occuring number
    bool run = true;     //the start of our loop
    cout << "This programm allows you to input a set of up to\n"
         << "20 integer values, which are stored in an array.\n"
         << "It then calculates the mode of the set of values\n"
         << "which is the value that occurs the most often or\n"
         << "with the greatest frequency.\n\n";
    
    while (run == true)                                     //As long my run boolean is true, this block will continue to run
    {
        cout << "\n\nHow many values do you want to store?" << endl;
        cout << "The number should be between 1 and 20: ";
        cin >> nums;                                        //Accepts user input for number of values

        //Another while loop to repromt user to enter valid nums
        while (nums < 1 || nums > 20)                          
        {
            cout << "It has to be a number between 1 and 20. " << nums 
                 << " is outside of that range.\n"
                 << "Try again\n"
                 << "The number should be between 1 and 20: ";
            cin >> nums;                                //Takes suer input
        }   

        //Fill array with user input of numbers
        if (nums >= 1 || nums <= 20)                    //condition checking validity of nums                   
        {
            //Dynamically allocate memory large enough to hold the int numbers
            numbers = new int[nums];

            //Take user input
            cout << "You can enter " << nums << " integers now: " << endl;

            for (index = 0; index < nums; index++)
            {
                cout << "Value " << (index+1) << ": ";
                cin >>  numbers[index];
            }

            //Display the numbers
            cout << "The values you entered are: ";
            for (index = 0; index < nums; index++)
                cout << numbers[index] << " "; 
            cout << endl;
            // CALL THE SORT ARRAY FUNTION
            sortArray(numbers, nums);
            cout << endl;
            //CALL THE GET MODE FUNCTION
            mode = getmode(numbers,nums);
        }

        //Calling StartOver to check if User wants to rerun the program
        int rerun = StartOver();            //Variable for user choice
        if (rerun == 0)
        {
            cout << "Thank you for using this Program";
            run = false;                    //This breaks the run loop in my while loop
        }
        else
            continue;
    }
    
    delete [] numbers;          //This deletes the dynamically allocated memory
    numbers = nullptr;          //sets it to zero to avoid future errors
    return 0;
}
/*
This function StartOver promts user to choose between ending the program or 
running from the start.
*/
int StartOver()
{   
    int check;                  //variable to retrun user choice                          
    char choice;
    cout << "\nDo you want to run the Program again? Y or N: ";
    cin >> choice;
    if (toupper(choice) == 'Y')             //toupper() function ensures char input is capitalized    
        check = 1;
    else if (toupper(choice) == 'N')
        check = 0;

    return check;              
}
/*
This function get mode takes an array as an argument and 
returns the most frequently occuring number
*/
int getmode(int a[], int size)
{
    //Variables intitialized to track mode as function runs
    int mode = -1;
    int count = 1;
    int maxCount = 1;

    //iterating throught the array to find mode
    for (int i = 1; i < size; ++i)
    {
        if (a[i] == a[i-1])
        {
            ++count;
        }
        else
        {
            //Check if current count is greater than max count found so far
            if(count > maxCount)
            {
                maxCount = count;
                mode = a[i-1];      //updates the mode
            }
            count = 1;              //resets count to starting value to avoid error moving to next element
        }
        if (count > maxCount)       
            mode = a[i-1];          //stores the number with highest frequency
    }
    if(maxCount != 1)
        cout << "\n\nMode is: " << mode << endl;
    else if (maxCount == 1)
    {
        cout << "There is no mode of these values\n";
        return -1;
    }
    return mode;
}
/*
This function Sort Array, takes an array as argument and sorts it
*/
void sortArray(int *arr, int size)
{
    sort(arr, arr + size);
    cout << "The values in numerical order are: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}