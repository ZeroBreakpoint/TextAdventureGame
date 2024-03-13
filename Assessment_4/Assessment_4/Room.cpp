#include "Room.h"
#include "Item.h" // Assuming Item class is declared in Item.h
#include <iostream>
using namespace std;

Room::Room() : description("Default Description"), item(nullptr) {
}

Room::Room(string descript, Item* item) : description(descript), item(item) {}

Room::~Room() {
    delete item; // Assuming ownership of the item is in the Room class
}

void Room::Description() const {
    cout << description << endl;
}


string Room::getDescription() const {
    return description;
}


Item* Room::getItem() const {
    return item;
}


void Room::setDescription(const string& descript) {
    description = descript;
}

void Room::setItem(Item* item) {
    this->item = item;
}