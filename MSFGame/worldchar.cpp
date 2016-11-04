#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"
#include "score.h"
#include <cmath>
#include <iostream>

void WorldCharacter::knockBack(WorldCharacter* character)
{
    if(orientation == 1)
    {
        character->setY(this->getY() - 5);
    }
    if(orientation == 2)
    {
        character->setX(this->getX() + 5);
    }
    if(orientation == 3)
    {
        character->setY(this->getY() + 5);
    }
    if(orientation == 4)
    {
        character->setX(this->getX() - 5);
    }
}

void WorldCharacter::hit(int attackDamage)
{
    if(attackDamage > defense && health > 0){
        health = health - attackDamage + defense;
        if (health == 0) {
            this->setDead(true);
        }
    }
}

bool WorldCharacter::isFacing(WorldCharacter* chosenChar)
{
    int result = abs(this->getOrientation()- chosenChar->getOrientation());
    if(result == 2)
    {
        return true;
    }
    return false;
}


