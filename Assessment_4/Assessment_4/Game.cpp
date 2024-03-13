#include <iostream>
#include "Game.h"
#include "Room.h"
#include "Player.h"
using namespace std;


Game::Game(int rows, int cols) : rows(rows), cols(cols) {
    // Initialize rooms
    rooms = new Room * [rows];
    for (int i = 0; i < rows; ++i) {
        rooms[i] = new Room[cols];
    }

    // Initialize player
    player = new Player();
}

Game::~Game() {
    // Deallocate memory for rooms
    for (int i = 0; i < rows; ++i) {
        delete[] rooms[i];
    }
    delete[] rooms;

    // Deallocate memory for player
    delete player;
}

void Game::Run() {
    // Logic to run the game
    cout << "Game is running..." << endl;
}
