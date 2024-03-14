#include "BoxOfDonuts.h"
#include "Item.h"
#include <iostream>



BoxOfDonuts::BoxOfDonuts()
{
}

BoxOfDonuts::BoxOfDonuts(const string& description, int initialCount)
    : Item(description), count(initialCount) {
    // Additional initialization code, if needed
}

BoxOfDonuts::~BoxOfDonuts()
{
}


void BoxOfDonuts::Description() const {
    cout << "This is a box of donuts with " << count << " donuts." << endl;
}

void BoxOfDonuts::Use() {
    if (count > 0) {
        cout << "You eat one donut from the box!" << endl;
        count--;
        cout << "There are now " << count << " donuts in the box " << endl;
    }
    else {
        cout << "The box is empty." << endl;
    }
}