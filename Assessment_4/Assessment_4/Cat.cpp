#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat() : purring(false) {}

void Cat::Description() const {
    cout << "This is a cat." << std::endl;
}

void Cat::Use() {
    purring = !purring;
    cout << "The cat is now " << (purring ? "purring." : "not purring.") << endl;
}