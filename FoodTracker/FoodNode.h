#ifndef FOODNODE_H
#define FOODNODE_H

#include <string>
using namespace std;

// FoodNode class to represent each food item
// represents one food item in the list
struct FoodNode {
    string foodName;
    float protein;
    float carbs;
    float fat;

    //constructor to initialize the food node
    FoodNode* next;
    FoodNode(string name, float p, float c, float f) : foodName(name), protein(p), carbs(c), fat(f), next(nullptr){}
};

#endif