#include "Item.h"
#include "Room.h"
#include "Game.h"
#include "Player.h"

void Item::Description() const {
}

void Item::setDescription(const string& descript) {
    description = descript;
}

Item::Item()
{
}

Item::~Item()
{
}

Item::Item(const string& desc)
{
}

void Item::Use() {
    
}
