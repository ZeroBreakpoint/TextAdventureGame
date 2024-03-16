#include "Lamp.h"
#include "Item.h"
#include <iostream>
using namespace std;

Lamp::Lamp() : turnedOn(false) {
}



void Lamp::Description() const {
    cout << "An old stained glass lamp." << endl;

}

void Lamp::Use() {
    if (turnedOn) {
        cout << "You switched the lamp off." << endl;
        turnedOn = false;
    }
    else {
        cout << "You turned the lamp on." << endl;
        turnedOn = true;
    }
}

Lamp::Lamp(const string& description, bool turnedOn)
    : Item(description), turnedOn(turnedOn) {
    
}
