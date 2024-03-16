#pragma once
#include "Item.h"
#include <string>
using namespace std;


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


    void setDescription(const string& desc);
    void setItem(Item* item);
};
