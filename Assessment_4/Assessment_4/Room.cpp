#include "Room.h"
#include "Item.h" // Assuming Item class is declared in Item.h
#include <iostream>
using namespace std;

Room::Room(string descript, Item* item) : description(descript), item(item) {}

Room::~Room() {
    delete item; // Assuming ownership of the item is in the Room class
}

void Room::Description() const {
    cout << description << endl;
}
