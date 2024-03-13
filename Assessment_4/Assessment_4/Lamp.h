#pragma once
#include "Item.h"

class Lamp : public Item {
private:
    bool switchedOn;

public:
    Lamp();
    void Description() const override;
    void Use() override;
    Lamp(const string& description, bool switchedOn);
};
