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
    void openSpellBook() const;
    void showSpells() const;
    void selectPlayerSpells();
    void findPlayerSpell(const string& spell) const;
    
};
