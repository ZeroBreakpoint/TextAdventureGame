#include <iostream>
#include "String.h"  // Used to include the header file
#include <cstring>  // Used for correct functionality of the classic "C style" string functions (such as strcmp, strlen etc)
#include <cctype>  // Used for correct functionality of toupper() and tolower() functions
#include <cstddef>  // Used for correct functionality of size_t
using namespace std;  // Used to help keep my code tidier and remove the need to add std:: before various ojects and functions (such as std::cin and std::cout etc)
#include "Game.h"
#include "Item.h"
#include "Player.h"

int main() {

    Game game;

    game.Run();

    system("pause");
}