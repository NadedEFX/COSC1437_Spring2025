#ifndef FOODLIST_H
#define FOODLIST_H

#include "FoodNode.h"
#include <string>

class FoodList{
    private:
    //pointer to the first food node
    FoodNode* head;
    public:
    //constructor to initialize the food list
    FoodList();
    ~FoodList();

    void addFood(string name, float p, float c, float f);
    void removeFood(const string& name);
    void displayFoods() const;
    void displayTotals() const;
    void searchFood(const string& name) const;
    void sortFoods();
    void saveToFile(const string& name) const;
    void loadFromFile(const string& filename);
    void clear();
    void autosave(const string& filename) const;
};

#endif