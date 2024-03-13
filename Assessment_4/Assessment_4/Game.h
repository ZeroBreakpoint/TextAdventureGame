#pragma once
#include "Room.h"
#include "Player.h"
#include "String.h"

class Game {
private:
    Room rooms[5][5];
    Player* player;
    int playerRow;    // Player's row position in the room array
    int playerCol;    // Player's column position in the room array

public:
    Game();
    ~Game();
    void Run();
    void printMap() const;
    void movePlayer(int rowOffset, int colOffset);
    void printRoomDescription(int row, int col) const;
    void initialiseRooms();
};

