#include "FoodList.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// display the menu
void displayMenu() {
    cout << "\n===== Food Tracker Menu ===== \n"
    << "1. Add Food\n"
    << "2. Remove Food\n"
    << "3. Display All Foods\n"
    << "4. Display Macro Totals\n"
    << "5. Search for a Food\n"
    << "6. Sort Foods Alphabetically\n"
    << "7. Save to File\n"
    << "8. Load from File\n"
    << "9. Exit\n";
}

// Function to check if the input is a valid float
bool isValidFloat(const string& input, float& value) {
    try{
        value = stof(input);
        return value >=0;
    } catch (...) {
        return false;
    }
}

// main
int main() {
    FoodList tracker;
    tracker.loadFromFile("foods.txt");
    int choice;
    string input, name;
    float p, c, f;
    do{
        displayMenu();
        cout << "Enter choice: ";
        cin >> input;
        if(input.length()== 1 && isdigit(input[0]))
        choice=stoi(input);
        else
        choice = -1;
        cin.ignore();

        switch (choice) {
            // cases for each menu option
            // case 1 adds the food
            case 1:
            cout << "Food name: ";
            getline(cin, name);
            cout << "Protein (g): ";
            getline(cin, input);
            if (!isValidFloat(input, p)) break;
            cout << "Carbs (g): ";
            getline(cin, input);
            if (!isValidFloat(input, c)) break;
            cout << "Fat (g): ";
            getline(cin, input);
            if (!isValidFloat(input, f)) break;
            tracker.addFood(name, p, c, f);
            tracker.autosave("foods.txt");
            break;

            // case 2 removes the food
            case 2:
            cout << "Enter name to remove: ";
            getline(cin, name);
            tracker.removeFood(name);
            tracker.autosave("foods.txt");
            break;

            //case 3 displays all the foods
            case 3:
            tracker.displayFoods();
            break;

            // case 4 displays the macro totals
            case 4:
            tracker.displayTotals();

            // case 5 searches for a food
            case 5:
            cout << "search food name: ";
            getline(cin, name);
            tracker.searchFood(name);
            break;

            // case 6 sorts the foods
            case 6:
            tracker.sortFoods();
            tracker.autosave("foods.txt");
            break;

            // case 7 saves the foods to a file
            case 7:
            tracker.saveToFile("foods.txt");
            cout << "Saved to foods.txt\n";
            break;

            // case 8 loads the foods from a file
            case 8:
            tracker.loadFromFile("foods.txt");
            break;

            // case 9 exits the program
            case 9:
            cout << "Exiting and autosaving...\n";
            tracker.autosave("foods.txt");
            break;

            // default case for invalid input
            default:
            cout << "Invalid choice. \n";
            break;

        }
    } while (choice !=9);
    return 0;
}