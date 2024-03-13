#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {}

Player::~Player() {}

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