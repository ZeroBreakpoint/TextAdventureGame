#include "BoxOfDonuts.h"
#include <iostream>
using namespace std;

BoxOfDonuts::BoxOfDonuts() : count(12) {}

void BoxOfDonuts::Description() const {
    cout << "This is a box of donuts." << endl;
}

void BoxOfDonuts::Use() {
    cout << "You eat one donut from the box!" << endl;
    count--;
}