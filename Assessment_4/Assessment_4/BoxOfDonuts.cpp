#include "BoxOfDonuts.h"
#include <iostream>



BoxOfDonuts::BoxOfDonuts()
{
}

BoxOfDonuts::BoxOfDonuts(const string& description, int initialCount)
    : Item(description), count(initialCount) {

}



void BoxOfDonuts::Description() const {
    cout << "This is a box of donuts with " << count << " donuts." << std::endl;
}

void BoxOfDonuts::Use() {
    if (count > 0) {
        cout << "You eat one donut from the box!" << std::endl;
        count--;
    }
    else {
        cout << "The box is empty." << std::endl;
    }
}