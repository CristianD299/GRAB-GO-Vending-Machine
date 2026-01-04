#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Vending machine items
    string itemNames[5] = {"Cola", "Water", "Chocolate Bar", "Crisps", "Coffee"};
    string itemCodes[5] = {"01", "02", "03", "04", "05"};
    double itemPrices[5] = {1.20, 1.00, 0.85, 0.90, 1.50};

    // Stock for each item
    int itemStock[5] = {3, 3, 3, 3, 3};

    double moneyInserted = 0.0;
    string choice;
    bool keepBuying = true;

    cout << "=============================\n";
    cout << "          GRAB & GO          \n";
    cout << "=============================\n\n";

    // Ask user for money once
    cout << "Insert money (£): ";
    cin >> moneyInserted;

    if (cin.fail() || moneyInserted <= 0) {
        cout << "Invalid amount. Please restart the machine.\n";
        return 0;
    }

    while (keepBuying && moneyInserted > 0) {
        cout << "\nAvailable Items:\n";

        // Display menu with stock
        for (int i = 0; i < 5; i++) {
            cout << itemCodes[i] << " - " << itemNames[i]
                 << " (£" << fixed << setprecision(2) << itemPrices[i]
                 << ")  Stock: " << itemStock[i] << "\n";
        }

        cout << "\nEnter item code: ";
        cin >> choice;

        int selectedIndex = -1;

        // Find item by code
        for (int i = 0; i < 5; i++) {
            if (choice == itemCodes[i]) {
                selectedIndex = i;
                break;
            }
        }

        if (selectedIndex == -1) {
            cout << "Invalid code. Try again.\n";
            continue;
        }

        // Check stock
        if (itemStock[selectedIndex] == 0) {
            cout << "Sorry, " << itemNames[selectedIndex] << " is OUT OF STOCK.\n";
            continue;
        }

        double price = itemPrices[selectedIndex];

        // Check money
        if (moneyInserted < price) {
            cout << "Not enough money. Item costs £" << price << ".\n";
            break;
        }

        // Dispense item
        cout << "\nDispensing " << itemNames[selectedIndex] << "...\n";

        // Reduce stock
        itemStock[selectedIndex]--;

        // Deduct price
        moneyInserted -= price;

        cout << "Remaining balance: £" << fixed << setprecision(2) << moneyInserted << "\n";

        // Ask user if they want another item
        char answer;
        cout << "Would you like to buy another item? (y/n): ";
        cin >> answer;

        if (answer == 'n' || answer == 'N') {
            keepBuying = false;
        }
    }

    // Return change
    cout << "\nReturning change: £" << fixed << setprecision(2) << moneyInserted << "\n";
    cout << "Thank you for using GRAB & GO!\n";

    return 0;
}