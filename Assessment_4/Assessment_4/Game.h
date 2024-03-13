#pragma once
#include "Room.h"
#include "Player.h"
#include <vector> // Include for std::vector

class Game {
private:
    Room** rooms;
    Player* player;
    int rows;
    int cols;

public:
    Game(int rows, int cols);
    ~Game();
    void Run();
};

