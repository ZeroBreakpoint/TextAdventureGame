#include "Player.h"
#include "String.h"
#include <iostream>
#include <algorithm> // Used for binary_search
#include <cstdlib> // For rand and srand
#include <ctime>   // For time
#include <string>
using namespace std;

Player::Player() {
    currentRoomRow = 0;
    currentRoomCol = 0;

    populateSpellbook();

    selectPlayerSpells();
}

Player::~Player() {
}


bool Player::FindSpell(string spell) {
    return binary_search(spells.begin(), spells.end(), spell);
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
void Player::OpenSpellBook() const {
    // Display the spell book content to the player
    cout << "The Spell Book contains: " << endl;
    ShowSpells();
}

void Player::ShowSpells() const {
    // Display all spells in the player's spell list
    for (const string& spell : spells) {
        cout << spell << endl;
    }
}


void Player::populateSpellbook() {
    // Add spells to the spellbook
    spells.push_back("fairy");
    spells.push_back("fire");
    spells.push_back("thunder");
    spells.push_back("water");
    spells.push_back("wind");
    spells.push_back("ascend");
    spells.push_back("recall");
    spells.push_back("ultrahand");
    spells.sort();
}

void Player::selectPlayerSpells() {
    playerSpells.push_back("fire");
    playerSpells.push_back("water");
    playerSpells.push_back("wind");
    playerSpells.push_back("thunder");
    playerSpells.sort();
}

void Player::FindPlayerSpell(const string& spell) const
{
    if (binary_search(playerSpells.begin(), playerSpells.end(), spell)) {
        cout << "You know the '" << spell << "' spell." << endl;
    }
    else {
        cout << "You do not know the '" << spell << "' spell." << endl;
    }
}

