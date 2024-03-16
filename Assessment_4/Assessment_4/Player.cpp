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

    // Populates the spellbook
    populateSpellbook();

    // Selects known spells for the player
    selectPlayerSpells();
}

Player::~Player() {
}

// Searches for a spell in the spellbook (if needed)
bool Player::FindSpell(string spell) {
    return binary_search(spells.begin(), spells.end(), spell);
}

void Player::Move(const string& direction) {
    // Move the player based on the direction
    cout << "Moving " << direction << endl;
    // Updates the player's current room position based on the direction
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

// Returns the current room position of the player (as a pair of numbers)
pair<int, int> Player::getCurrentRoomPosition() const {
    return make_pair(currentRoomRow, currentRoomCol);
}

// Returns the current room row of the player
int Player::getCurrentRoomRow() const {
    return currentRoomRow;
}

// Returns the current room column of the player
int Player::getCurrentRoomCol() const {
    return currentRoomCol;
}

// Display the spell book content to the player
void Player::openSpellBook() const {
    cout << "The Spell Book contains: " << endl;
    showSpells();
}

// Display all spells in the spell list
void Player::showSpells() const {
    for (const string& spell : spells) {
        cout << spell << endl;
    }
}

// Populates the spellbook with spells
void Player::populateSpellbook() {
    spells.push_back("fairy");
    spells.push_back("fire");
    spells.push_back("thunder");
    spells.push_back("water");
    spells.push_back("wind");
    spells.push_back("ascend");
    spells.push_back("recall");
    spells.push_back("ultrahand");
    spells.sort();  // Sorts the spells aphabetically (for the binary search)
}

// Selects knwon spells for the player
void Player::selectPlayerSpells() {
    playerSpells.push_back("fire");
    playerSpells.push_back("water");
    playerSpells.push_back("wind");
    playerSpells.push_back("thunder");
    playerSpells.sort();  // Sorts the player's spells alphabetically (for the binary search)
}

// Checks if the player knows a specific spell
void Player::findPlayerSpell(const string& spell) const
{
    if (binary_search(playerSpells.begin(), playerSpells.end(), spell)) {
        cout << "You know the '" << spell << "' spell." << endl;
    }
    else {
        cout << "You do not know the '" << spell << "' spell." << endl;
    }
}

