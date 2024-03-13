#include "Lamp.h"
#include "Item.h"
#include <iostream>
using namespace std;

Lamp::Lamp() : Item(), switchedOn(false) { }



void Lamp::Description() const {
    cout << "This is a lamp." << endl;
}

void Lamp::Use() {
    if (switchedOn) {
        cout << "The lamp is already on." << endl;
    }
    else {
        cout << "You turn on the lamp." << endl;
        switchedOn = true;
    }
}

Lamp::Lamp(const std::string& description, bool switchedOn)
    : Item(description), switchedOn(switchedOn) {
}
