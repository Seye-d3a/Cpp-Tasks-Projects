//Completed by AYOMIDE OGUNSEYE Mar 16, 2025.
#include <iostream>
#include <string>       //to utilize string
#include <iomanip>      //to utilize setprecision()
using namespace std;

// Function prototypes
string toMorse(char);

// Global data. Each valid character and its equivalent
// morse code are stored in the parallel arrays.
const int NUM_CHARS = 40;
char regular[NUM_CHARS] = { ' ', ',', '.', '?', '0', '1', '2', '3', '4', '5',
                            '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
                            'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                            'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

string morse[NUM_CHARS] = { " ", "--..--" , ".-.-.-" , "..--.." ,
                            "-----", ".----", "..---", "...--",
                            "....-", ".....", "-....", "--...",
                            "---..", "----.", ".-", "-...",
                            "-.-.", "-..", ".", "..-.",
                            "--.", "....", "..", ".---",
                            "-.-", ".-..", "--", "-.",
                            "---", ".--.", "--.-", ".-.",
                            "...", "-", "..-", "...-",
                            ".--", "-..-", "-.--", "--.."
};

int main()
{
    string input;        // To hold the user's input
    char choice;       // TO hold the user's choice to continue
    /*
    // Get a word from the user.
    cout << "Enter a word and I will translate it to Morse code.\n";
    cout << "-> ";
    getline(cin, str);

    // Translate each character and display it.
    int index = 0;
    int size = str.size();

    while (index < size)
    {
        cout << toMorse(toupper(str[index])) << endl;
        index++;
    }
    */

    do
    {
        cout << "Morse Code Converter\n"
            << "This program will convert a word or \n"
            << "phrase entered by the user into its \n"
            << "corresponding Morse code.\n"
            << "After entering the text, the program\n"
            << "will display each letter alongside\n"
            << "its Morse code equivalent\n\n";

        cout << "Enter a word and I will translate it to Morse code.\n";
        getline(cin, input);                    //Gets user input from buffer

        //Translate each character and dsiplay it
        int index = 0;
        int size = input.size();

        cout << "\n";

        for (char ch : input)
        {
            if (ch != ' ')
                cout << left << setw(7) << ch << " "; //show the original character
        }

        for (char ch : input)
        {
            if (ch != ' ')
                cout << left << setw(7) << toMorse(toupper(ch)) << " "; //Translate to morse code
        }

        //Ask if the user wants to run the program again
        cout << "\nWould you like to run program again (Y/N)? ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');         //clears the buffer
        cout << "\n\n";
        system("cls");
    } while (tolower(choice) == 'y');

    return 0;
}

// ****************************************************
// The toMorse function accepts a char argument and   *
// returns a string containing the morse code         *
// for that character.                                *
// ****************************************************
string toMorse(char ch)
{
    // Find the character in the array.
    int index = 0;
    while (index < NUM_CHARS && ch != regular[index])
    {
        index++;
    }

    string morseValue;  // To hold the morse code

    if (index >= NUM_CHARS)
        morseValue = "UNDEFINED";  // ch was not found
    else
        morseValue = morse[index]; // Get the morse code

    return morseValue;
}