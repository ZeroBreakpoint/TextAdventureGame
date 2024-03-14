#pragma once
#include <iostream>
using namespace std;

class Item {
public:
    virtual void Description() const;
    virtual void Use();
    void setDescription(const string& descript);
    Item();
    ~Item();
    Item(const string& desc);


private:
    string description;
};


