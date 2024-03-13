#pragma once
#include <list>
#include <string>
using namespace std;

class Player {
private:
    list<string> spells;
    int currentRoomRow;
    int currentRoomCol;

public:
    Player();
    ~Player();
    bool FindSpell(string spell);
    void Move(const string& direction);
    pair<int, int> getCurrentRoomPosition() const;
    int getCurrentRoomRow() const; // Getter for current room row
    int getCurrentRoomCol() const;

};
