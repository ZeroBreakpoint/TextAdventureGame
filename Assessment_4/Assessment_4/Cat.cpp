#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat() : Item(), purring(false) {}


void Cat::Description() const {
    cout << "This is a cat." << endl;
}

void Cat::Use() {
    if (purring) {
        cout << "The cat is already purring." << endl;
    }
    else {
        cout << "You pat the cat, and it starts purring." << endl;
        purring = true;
    }
}

Cat::Cat(const string& description, bool purring)
{
}
