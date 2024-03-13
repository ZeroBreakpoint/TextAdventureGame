#pragma once
#include "Item.h" // Assuming Item class is declared in Item.h
#include <string>
using namespace std;

class Item;

class Room {
private:
    string description;
public:
    Item* item;
    Room();
    Room(string descript, Item* item);
    ~Room();
    void Description() const;
    string getDescription() const;
    Item* getItem() const;

    // Setter methods
    void setDescription(const std::string& desc);
    void setItem(Item* item);
};
