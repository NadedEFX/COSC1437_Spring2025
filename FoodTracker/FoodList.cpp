#include "FoodList.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

// helper function to convert string to lowercase
static string toLower(const string& s) {
    string result;
    for(char c: s) result += tolower(c);
    return result;
}

// constructor and destructor for the food list
FoodList::FoodList():head(nullptr) {}
    FoodList::~FoodList() {
        clear();
        autosave("food.txt");
    }

    //  adds a new food to the end of the list
    void FoodList::addFood(string name, float p, float c, float f) {
        FoodNode* newNode = new FoodNode(name, p, c, f);
        if(!head) head = newNode;
        else{
            FoodNode* temp = head;
            while(temp->next) temp = temp->next;
            temp->next=newNode;
        }
        cout <<"Food added. \n";
    }

    // removes a food from the list
    void FoodList::removeFood(const string& name) {
        if(!head) return;

        if(toLower(head->foodName)== toLower(name)){
            FoodNode* temp = head;
            head = head->next;
            delete temp;
            cout << "Food rmoved. \n";
            return;
        }
        FoodNode* current = head;
        while(current->next && toLower(current->next->foodName) != toLower(name))
        current = current->next;
        if(current->next) {
            FoodNode* temp = current->next;
            current->next= temp->next;
            delete temp;
            cout << "Food removed. \n";
        }else {
            cout << "Food not found. \n";
        }
    }

    // displays all the foods in the list
    void FoodList::displayFoods() const{
        if(!head) {
            cout << "No foods recorded. \n";
            return;
        }
        cout << left << setw(20) << "Food" << setw(10) << "Protein" << setw(10) <<"Carbs" << setw(10) << "Fat" << "\n";
        cout << string(50,'-') << "\n";
        FoodNode* temp = head;
        while(temp){
            cout << left << setw(20) << temp->foodName << setw(10) << temp->protein << setw(10) << temp->carbs << setw(10) << temp->fat << "\n";
            temp = temp->next;
        }
    }

    // displays the total protein, carbs, fat and calories and also calculates the total calories
    void FoodList::displayTotals() const {
        float p = 0, c = 0, f = 0;
        FoodNode* temp = head;
        while (temp) {
            p+= temp->protein;
            c+= temp->carbs;
            f+= temp->fat;
            temp = temp->next;
        }
        cout << fixed << setprecision(1);
        cout << "Total Protein: " << p << "g\n";
        cout << "Total Carbs: " << c << "g\n";
        cout << "Total Fat: " << f << "g\n";
        cout << "Total Calories: " << (p * 4 + c * 4 + f * 9) << " kcal\n";
    }

    // searches for a food in the list
    void FoodList::searchFood(const string& name) const {
        FoodNode* temp = head;
        while (temp) {
            if(toLower(temp->foodName)==toLower(name)){
                cout << "Found: " << temp->foodName << " - protein: " << temp->protein << ", Carbs: " << temp->carbs << ", Fat: " << temp->fat << "\n";
                return;
            }
            temp= temp->next;
        }
        cout << "Food not found. \n";
    }

    // sorts the food list in alphabetical order
    // uses bubble sort algorithm
    void FoodList::sortFoods() {
        if(!head || !head->next) 
        return;

        for(FoodNode* i = head; i; i = i-> next) {
            for(FoodNode* j = i->next; j; j = j->next) {
                if(toLower(i->foodName) > toLower(j->foodName)) {
                    swap(i->foodName, j->foodName);
                    swap(i->protein, j->protein);
                    swap(i->carbs, j->carbs);
                    swap(i->fat, j->fat);
                }
            }
        }
        cout << "Food sorted. \n";
    }

    //saves the food list to a file
    void FoodList::saveToFile(const string& filename) const{
        ofstream file(filename);
        if(!file) {
            cout << "Error opening file. \n";
            return;
        }
        FoodNode* temp = head;
        while(temp) {
            file << temp->foodName << " " <<temp->protein<< " " << temp->carbs << " " << temp->fat << "\n";
            temp = temp->next;
        }
    }

    // loads the food list from a file
    void FoodList::loadFromFile(const string& filename) {
        ifstream file(filename);
        if(!file) {
            cout << "No file found to load.\n";
            return;
        }
        clear();
        string name;
        float p, c, f;
        while(file >> name >> p >> c >> f)
        addFood(name, p, c, f);

        cout <<"Data loaded from " << filename << ".\n";
    }

    // clears the food list
    void FoodList::clear() {
        while(head) {
            FoodNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    // autosaves the food list to a file
    // this function is called when the program exits
    // it saves the food list to a file
    void FoodList::autosave(const string& filename) const {
        saveToFile(filename);
        cout << "[Autosaved to " << filename << "]\n";
    }