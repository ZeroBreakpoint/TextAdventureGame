#pragma once
#include "Item.h"

class BoxOfDonuts : public Item {
private:
    int count;

public:
    BoxOfDonuts();
    BoxOfDonuts(const string& description, int initialCount);
    virtual void Description() const override;
    virtual void Use() override;
};
