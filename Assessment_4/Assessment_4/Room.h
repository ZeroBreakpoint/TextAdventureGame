#pragma once
#include "Item.h" // Assuming Item class is declared in Item.h
#include <string>
using namespace std;

class Room {
private:
    Item* item;
    string description;

public:
    Room(string descript, Item* item);
    ~Room();
    void Description() const;
};
