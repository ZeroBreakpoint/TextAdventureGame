#include <iostream>
#include "Game.h"
#include "Room.h"
#include "Player.h"
#include "String.h"
using namespace std;


Game::Game() {
    static const string defaultDescription = "Default Description";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            rooms[i][j].setDescription(defaultDescription);
            rooms[i][j].setItem(nullptr);
        }
    }
    player = new Player();
}

Game::~Game() {
 
    delete player;
}

void Game::Run() {
    // Game loop
    cout << R"(
                                    /@
                     __        __   /\/
                    /==\      /  \_/\/   
                  /======\    \/\__ \__
                /==/\  /\==\    /\_|__ \
             /==/    ||    \=\ / / / /_/
           /=/    /\ || /\   \=\/ /     
        /===/   /   \||/   \   \===\
      /===/   /_________________ \===\
   /====/   / |                /  \====\
 /====/   /   |  _________    /  \   \===\    THE LEGEND OF 
 /==/   /     | /   /  \ / / /  __________\_____      ______       ___
|===| /       |/   /____/ / /   \   _____ |\   /      \   _ \      \  \
 \==\             /\   / / /     | |  /= \| | |        | | \ \     / _ \
 \===\__    \    /  \ / / /   /  | | /===/  | |        | |  \ \   / / \ \
   \==\ \    \\ /____/   /_\ //  | |_____/| | |        | |   | | / /___\ \
   \===\ \   \\\\\\\/   /////// /|  _____ | | |        | |   | | |  ___  |
     \==\/     \\\\/ / //////   \| |/==/ \| | |        | |   | | | /   \ |
     \==\     _ \\/ / /////    _ | |==/     | |        | |  / /  | |   | |
       \==\  / \ / / ///      /|\| |_____/| | |_____/| | |_/ /   | |   | |
       \==\ /   / / /________/ |/_________|/_________|/_____/   /___\ /___\
         \==\  /               | /==/
         \=\  /________________|/=/    TEXT ADVENTURE GAME
           \==\     _____     /==/ 
          / \===\   \   /   /===/
         / / /\===\  \_/  /===/
        / / /   \====\ /====/
       / / /      \===|===/
       |/_/         \===/
                      =)" << endl;
    while (true) {
        // Print current room description
        cout << "Current Room Description: ";
        rooms[player->getCurrentRoomRow()][player->getCurrentRoomCol()].Description();
        cout << endl;

        // Prompt user for input
        cout << "Enter a direction to move (North, South, East, West): ";
        string direction;
        cin >> direction;

        // Move the player based on input
        player->Move(direction);
    }
}
