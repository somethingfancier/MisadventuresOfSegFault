#include "world.h"


//Adders for characters, items, and obstacles in the world

void World::addCharacter(WorldCharacter* newCharacter)
{
    characters.push_back(newCharacter);
}

void World::addItem(WorldItem* newItem)
{
    items.push_back(newItem);
}

void World::addObstacle(WorldObstacle* newObstacle)
{
    obstacles.push_back(newObstacle);
}
