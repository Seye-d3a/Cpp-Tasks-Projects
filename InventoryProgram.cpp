//Completed by Ayomide Ogunseye Apr 06, 2025
#include <iostream>
#include <fstream>
using namespace std;

// Constant for array sizes
const int DESC_SIZE = 31;
const int DATE_SIZE = 11;

// Declaration of Inventory structure
struct Inventory
{
    char desc[DESC_SIZE];  // Description
    int qty;               // Quantity
    double wholeSale;      // Wholesale cost
    double retail;         // Retail price
    char date[DATE_SIZE];  // Date added to inventory
};

// Function prototypes
void addRecord(fstream&);
void viewRecord(fstream&);
void changeRecord(fstream&);

int main()
{
    cout << "\n\n\t\t\t\tInventory Program"                             //header
        << "\n\ttan inventory. It will track the following "            //beginning of text
        << "\n\tinformation: "                                          //more text
        << "\n\tItem Description"                                       //more text
        << "\n\t\tQuantity on Hand"                                     //more text
        << "\n\t\tWholesale Cost"                                       //more text
        << "\n\tRetail Cost"                                            //more text
        << "\n\t\tDate Added to Inventory"                              //more text
        << "\n\n\t\tUser will be able to view, add, and edit the "      //more text
        << "\n\tinventory";                                             //more text
    cout << "\n\n\t---------------------------------------------\n\n";
    // File stream object
    fstream inventoryFile;

    // User's menu choice
    int choice;

    // Display the menu and process the
    // user's request.
    do
    {
        // Display the menu.
        cout << "\n1. Add a new record\n";
        cout << "2. View an existing record\n";
        cout << "3. Change an existing record\n";
        cout << "4. Exit\n\n";

        // Get the user's menu selection.
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Validate the menu selection.
        while (choice < 1 || choice > 4)
        {
            cout << "ERROR. Enter 1, 2, 3, or 4: ";
            cin >> choice;
        }

        // Process the selection.
        switch (choice)
        {
            // Choice 1 is to add a record.
        case 1:
            addRecord(inventoryFile);
            break;

            // Choice 2 is to view a record.
        case 2:
            viewRecord(inventoryFile);
            break;

            // Choice 3 is to change a record.
        case 3:
            changeRecord(inventoryFile);
        }

    } while (choice != 4);

    return 0;
}

//************************************************
// Function addRecord                            *
// This function gets the data for a record      *
// and writes it to the file.                    *
//************************************************
void addRecord(fstream& invFile)
{
    // An inventory structure to hold an
    // inventory record.
    Inventory record;

    // Open the file.
    invFile.open("invtry.dat", ios::out | ios::app | ios::binary);

    // If an error happened, exit.
    if (invFile.fail())
    {
        cout << "Error opening file.\n";
        exit(EXIT_FAILURE);
    }
    cin.get();
    cout << "\nEnter the following inventory data:\n";

    // Get the description.
    cout << "Description: ";
    cin.getline(record.desc, 31);

    // Get the quantity.
    cout << "Quantity: ";
    cin >> record.qty;
    while (record.qty < 0)
    {
        cout << "Enter a positive value, please: ";
        cin >> record.qty;
    }

    // Get the wholesale cost.
    cout << "Wholesale cost: ";
    cin >> record.wholeSale;
    while (record.wholeSale < 0)
    {
        cout << "Enter a positive value, please: ";
        cin >> record.wholeSale;
    }

    // Get the retail price.
    cout << "Retail price: ";
    cin >> record.retail;
    while (record.retail < 0)
    {
        cout << "Enter a positive value, please: ";
        cin >> record.retail;
    }

    // Get the date added to inventory.
    cout << "Date added to inventory: ";
    cin >> record.date;

    // Write the record.
    invFile.write(reinterpret_cast<char*>(&record), sizeof(record));

    // Make sure we didn't have an error writing.
    if (invFile.fail())
        cout << "Error writing record to file.\n";
    else
        cout << "record written to file.\n\n";

    // Close the file.
    invFile.close();
}

//************************************************
// Function viewRecord                           *
// This function reads a specified record from   *
// the file and displays it on the screen.       *
//************************************************
void viewRecord(fstream& invFile)
{
    Inventory record;

    // Record number
    long recNum;

    // Open the file.
    invFile.open("invtry.dat", ios::in | ios::binary);

    // If we encountered an error, exit.
    if (invFile.fail())
    {
        cout << "Error opening file.\n";
        exit(EXIT_FAILURE);
    }

    // Get the record number from the user.
    cout << "\nEnter the record number of the item: ";
    cin >> recNum;

    // Seek to the record.
    invFile.seekg(recNum * sizeof(record), ios::beg);
    if (invFile.fail())
    {
        cout << "\nError locating record.\n";
        invFile.close();
        return;
    }

    // Read the record.
    invFile.read(reinterpret_cast<char*>(&record), sizeof(record));
    invFile.close();

    // Display the record.
    cout << "Description: ";
    cout << record.desc << endl;
    cout << "Quantity: ";
    cout << record.qty << endl;
    cout << "Wholesale cost: ";
    cout << record.wholeSale << endl;
    cout << "Retail price: ";
    cout << record.retail << endl << endl;
    cout << "Press any key to continue...\n ";
    cin.get();
}

//************************************************
// Function changeRecord                         *
// This function reads a specified record from   *
// the file and allows the user to change it.    *
//************************************************
void changeRecord(fstream& invFile)
{
    Inventory record;

    // Record number.
    long recNum;

    // Open the file.
    invFile.open("invtry.dat", ios::in | ios::out | ios::binary);

    // If we encountered an error, exit.
    if (invFile.fail())
    {
        cout << "Error opening file.\n";
        exit(EXIT_FAILURE);
    }

    // Get the record number from the user.
    cout << "Enter the record number of the item: ";
    cin >> recNum;

    // Seek to the record.
    invFile.seekg(recNum * sizeof(record), ios::beg);
    if (invFile.fail())
    {
        cout << "Error locating record.\n";
        invFile.close();
        return;
    }

    // Read the record.  
    invFile.read(reinterpret_cast<char*>(&record), sizeof(record));

    // Display the record.
    cout << "Current record contents:\n";
    cout << "Description: ";
    cout << record.desc << endl;
    cout << "Quantity: ";
    cout << record.qty << endl;
    cout << "Wholesale cost: ";
    cout << record.wholeSale << endl;
    cout << "Retail price: ";
    cout << record.retail << endl << endl;

    // Get new data.
    cout << "Enter the new data:\n";
    cin.get();
    cout << "Description: ";
    cin.getline(record.desc, 31);
    cout << "Quantity: ";
    cin >> record.qty;
    cout << "Wholesale cost: ";
    cin >> record.wholeSale;
    cout << "Retail price: ";
    cin >> record.retail;
    cout << "Date added to inventory: ";
    cin >> record.date;

    // Seek to the record position again.
    invFile.seekp(recNum * sizeof(record), ios::beg);

    // Write the record with the new data.
    invFile.write(reinterpret_cast<char*>(&record), sizeof(record));

    // Close the file.
    invFile.close();

    cout << "Press any key to continue... ";
    cin.get();
}