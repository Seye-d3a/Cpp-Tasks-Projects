//  Completed by Ayomide Ogunseye Apr 23, 2025
#include <iostream>
#include <cctype>
#include "CashRegister.h"
using namespace std;

const int NUM_ITEMS = 5;

int main()
{
    //Creating an object array for the InventoryItem class
    InventoryItem inventory[NUM_ITEMS] = {
              InventoryItem("Adjustable Wrench", 7.0, 10),
              InventoryItem("Screwdriver", 3.5, 20),
              InventoryItem("Pliers", 9.0, 35),
              InventoryItem("Ratchet", 10.0, 10),
              InventoryItem("Socket Wrench", 9.75, 7) };

    CashRegister reg(inventory, NUM_ITEMS);     //constructor
    char again;                                 //take user input to rerun program

    //Intro to program
    cout << "\tCASH REGISTER\n"
         << "\nThis program will keep track of inventory items\n"
         << "The user will be able to select the item adn quantity to purchase\n\n";

    do
    {
        reg.makeSale();
        cout << "Do you want to purchase another item? ";
        cin >> again;

        while (toupper(again) != 'Y' && toupper(again) != 'N')
        {
            cout << "Enter Y or N please: ";
            cin >> again;
        }
        cin.get();
        cin.ignore(0);
        system("cls");
    } while (toupper(again) != 'N');
    return 0;
}