#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
    currentRoomRow = 0;
    currentRoomCol = 0;
}

Player::~Player() {
}

bool Player::FindSpell(string spell) {
    // Logic to find the spell
    // For example:
    for (const auto& s : spells) {
        if (s == spell) {
            cout << "Spell found!" << endl;
            return true;
        }
    }
    cout << "Spell not found!" << endl;
    return false;
}

void Player::Move(const string& direction) {
    // Move the player based on the direction
    cout << "Moving " << direction << endl;
    // Update player's current room position accordingly
    if (direction == "North") {
        if (currentRoomRow > 0)
            --currentRoomRow;
    }
    else if (direction == "South") {
        if (currentRoomRow < 2)
            ++currentRoomRow;
    }
    else if (direction == "East") {
        if (currentRoomCol < 2)
            ++currentRoomCol;
    }
    else if (direction == "West") {
        if (currentRoomCol > 0)
            --currentRoomCol;
    }
}
pair<int, int> Player::getCurrentRoomPosition() const {
    // Return the current room position of the player
    return make_pair(currentRoomRow, currentRoomCol);
}

int Player::getCurrentRoomRow() const {
    // Return the current room row of the player
    return currentRoomRow;
}

int Player::getCurrentRoomCol() const {
    // Return the current room column of the player
    return currentRoomCol;
}