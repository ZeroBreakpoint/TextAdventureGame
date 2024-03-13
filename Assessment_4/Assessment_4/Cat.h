#pragma once
#include "Item.h"

class Cat : public Item {
private:
    bool purring;

public:
    Cat();
    void Description() const override;
    void Use() override;
    Cat(const string& description, bool purring);
};


