#include <iostream>
#include <algorithm>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time
#include "Game.h"
#include "Room.h"
#include "Player.h"
#include "String.h"
#include "Item.h"
#include "BoxOfDonuts.h"
#include "Lamp.h"
#include "Cat.h"
using namespace std;


Game::Game() {
    static const string defaultDescription = "Room Description";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            rooms[i][j].setDescription(defaultDescription);
            rooms[i][j].setItem(nullptr);
        }
    }
    this->playerRow = 1; // Player Starting location
    this->playerCol = 0;
    player = new Player();

    BoxOfDonuts* boxOfDonuts = new BoxOfDonuts("Box of Donuts description", 3);
    placeItem(rooms, boxOfDonuts);

    Lamp* lamp = new Lamp("Lamp description", false);
    placeItem(rooms, lamp);

    Cat* cat = new Cat("Cat description", false);
    placeItem(rooms, cat);

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

    String direction;
    while (true) {
        printMap();
        cout << "Enter a direction to move to a new room (North, East, South, West) or 'Book' to open spellbook & 'Q' to Quit: ";
        direction.ReadFromConsole();

        // Convert the input direction to lowercase for case-insensitive comparison
        direction.ToLower();

        // Move the player based on the input direction
        if (direction == "north") {
            movePlayer(-1, 0); // Move north
        }
        else if (direction == "east") {
            movePlayer(0, 1); // Move east
        }
        else if (direction == "south") {
            movePlayer(1, 0); // Move south
        }
        else if (direction == "west") {
            movePlayer(0, -1); // Move west
        }
        else if (direction == "book") {
            player->OpenSpellBook(); // Open the player's spell book
            // After opening the spell book, prompt the user to search for a known spell
            cout << "\nEnter the name of the spell you want to search for: ";

            String spell;
            spell.ReadFromConsole();


            // Perform binary search on the player's spell book
            if (player->FindSpell(spell)) {
                cout << "You know the '" << spell << "' spell." << endl;
            }
            else {
                cout << "You do not know the '" << spell << "' spell." << endl;
            }
        }
        else if (direction == "q") {
            cout << "Quitting the game." << endl;
            return;
        }
        else {
            cout << "Invalid direction. Please enter North, East, South, West, or Q to exit." << endl;
        }
    }
}


void Game::printMap() const {
    // Print the ASCII map
    // Print the top part of the rooms
        cout << "-----------------------------------" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << " _____ ";
            }
            cout << endl;

            // Print the middle part of the rooms (including the player's position if applicable)
            for (int j = 0; j < 3; ++j) {
                if (i == this->playerRow && j == this->playerCol) {
                    cout << "|  P  |";
                }
                else {
                    cout << "|     |";
                }
            }
            cout << endl;

            // Print the bottom part of the rooms
            for (int j = 0; j < 3; ++j) {
                cout << "|_____|";
            }
            cout << endl;
        }

    cout << "\n-----------------------------------" << endl;
}


void Game::movePlayer(int rowOffset, int colOffset) {
    // Calculate the new player position after moving
    int newRow = playerRow + rowOffset;
    int newCol = playerCol + colOffset;

    // Check if the new position is within the grid bounds
    if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3) {
        // Move the player to the new room
        // You may need additional logic to handle interactions with the room, if any
        // For simplicity, this example just moves the player without interaction

        playerRow = newRow;
        playerCol = newCol;

        printRoomDescription(playerRow, playerCol);

    }
    else {
        cout << "Cannot move in that direction. Please choose another direction." << endl;
    }
}


void Game::placeItem(Room rooms[3][3], Item* item) {
    srand(time(nullptr));

    // Randomly select a room until an empty one is found
    while (true) {
        // Generate random row and column indices
        int row = rand() % 3;
        int col = rand() % 3;

        // Check if the selected room is empty (and also isn't player starting location)
        if (rooms[row][col].getItem() == nullptr && !(row == 1 && col == 0)) {
            rooms[row][col].setItem(item);
            break;
        }
    }
}



void Game::printRoomDescription(int row, int col){
    // Check if the row and column are within bounds
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {

        playerRow = row;
        playerCol = col;
        printMap();


        // Check if there is an item in the room
        Item* item = rooms[row][col].getItem();
        if (item != nullptr) {
            // Room has an item
            cout << "Room description: There is an item in this room!" << endl;
            cout << "Item Description: ";
            item->Description();
            // Prompt the player to use the item
            cout << "Do you want to use this item? (Yes/No): ";
            String response;
            response.ReadFromConsole();
            response.ToLower();
            if (response == "yes") {
                item->Use();
            }
            if (response == "no")
            {
                cout <<"Item not used." << endl;
            }
        }
        else {
            // Room is empty
            cout << "Room description: Nothing but cobwebs in this room." << endl;
        }
    }
}

void Game::ClearScreen() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

