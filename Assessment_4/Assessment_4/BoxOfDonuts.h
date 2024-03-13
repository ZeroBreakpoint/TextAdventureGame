#pragma once
#include "Item.h"

class BoxOfDonuts : public Item {
private:
    int count;

public:
    BoxOfDonuts();
    void Description() const override;
    void Use() override;
    BoxOfDonuts(const string& description, int initialCount);
};
