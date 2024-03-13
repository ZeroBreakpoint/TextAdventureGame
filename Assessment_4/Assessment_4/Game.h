#pragma once
#include "Room.h"
#include "Player.h"
#include "String.h"

class Game {
private:
    Room rooms[3][3];
    Player* player;

public:
    Game();
    ~Game();
    void Run();
};

