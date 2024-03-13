#pragma once
#include "Item.h"

class Lamp : public Item {
private:
    bool turnedOn;

public:
    Lamp();
    void Description() const override;
    void Use() override;
};
