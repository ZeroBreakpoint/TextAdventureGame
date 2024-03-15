#include "Lamp.h"
#include "Item.h"
#include <iostream>
using namespace std;

Lamp::Lamp() {} /*: Item(), switchedOn(false) { }*/



void Lamp::Description() const {
    cout << "An old stained glass lamp." << endl;

}

void Lamp::Use() {
    if (switchedOn) {
        cout << "You switched the lamp off." << endl;
        switchedOn = false;
    }
    else {
        cout << "You turned the lamp on." << endl;
        switchedOn = true;
    }
}

Lamp::Lamp(const string& description, bool switchedOn)
    : Item(description), switchedOn(switchedOn) {
    
}
