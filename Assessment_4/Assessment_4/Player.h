#pragma once
#include <list>
#include <string>
using namespace std;

class Player {
private:
    list<string> spells;

public:
    Player();
    ~Player();
    bool FindSpell(string spell);
};
