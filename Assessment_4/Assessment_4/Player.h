#pragma once
#include <list>
#include <algorithm>
#include <string>
using namespace std;

class Player {
private:
    list<string> spells;
    list<string> playerSpells;
    int currentRoomRow;
    int currentRoomCol;
    void populateSpellbook();

public:
    Player();
    ~Player();
    bool FindSpell(string spell);
    void Move(const string& direction);
    pair<int, int> getCurrentRoomPosition() const;
    int getCurrentRoomRow() const; // Getter for current room row
    int getCurrentRoomCol() const;
    void OpenSpellBook() const;
    void ShowSpells() const;
    void selectPlayerSpells();
    void FindPlayerSpell(const std::string& spell) const;
    
};
