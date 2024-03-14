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
        cout << "You switched the lamp on." << endl;
    }
    else {
        cout << "You turned the lamp off." << endl;
        
    }
}

Lamp::Lamp(const string& description, bool switchedOn)
    : Item(description), switchedOn(switchedOn) {
}
