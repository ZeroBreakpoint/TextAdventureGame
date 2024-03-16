#include "Room.h"
#include "Item.h"
#include <iostream>
using namespace std;

Room::Room() : description("Default Description"), item(nullptr) {
}

Room::Room(string descript, Item* item) : description(descript), item(item) {}

Room::~Room() {
    delete item;
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

// Sets the description of the room
void Room::setDescription(const string& descript) {
    description = descript;
}

// Sets the item in the room
void Room::setItem(Item* item) {
    this->item = item;
}

