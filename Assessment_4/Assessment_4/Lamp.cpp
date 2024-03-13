#include "Lamp.h"
#include <iostream>
using namespace std;

Lamp::Lamp() : turnedOn(false) {}

void Lamp::Description() const {
    std::cout << "This is a lamp." << std::endl;
}

void Lamp::Use() {
    turnedOn = !turnedOn;
    cout << "The lamp is now " << (turnedOn ? "on." : "off.") << endl;
}
