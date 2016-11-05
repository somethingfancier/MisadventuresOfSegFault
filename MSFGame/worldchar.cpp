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

void WorldCharacter::setDirections()
{
    if(orientation == 1)
    {
        movableD = true;
        movableL = true;
        movableR = true;
    }
    else if(orientation == 2)
    {
        movableU = true;
        movableD = true;
        movableL = true;
    }
    else if(orientation == 3)
    {
        movableU = true;
        movableL = true;
        movableR = true;
    }
    else if(orientation == 4)
    {
        movableD = true;
        movableU = true;
        movableR = true;
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

bool WorldCharacter::isBoardering(WorldObject *obj)
{
    WorldObstacle* obstacle = dynamic_cast<WorldObstacle*>(obj);
    WorldEnemy* enemy = dynamic_cast<WorldEnemy*>(obj);
    WorldPlayer* player = dynamic_cast<WorldPlayer*>(obj);
    if(obstacle != nullptr){
        if(orientation == 1)
        {
            return(this->withinXBound(obstacle) && obstacle->vSDistance(this) <= 10);
        }
        else if(orientation == 2)
        {
            return(this->withinYBound(obstacle) && obstacle->hSDistance(this) > 10);
        }
        else if(orientation == 3)
        {
            return(this->withinXBound(obstacle) && obstacle->vSDistance(this) > 10);
        }
        else if(orientation == 4)
        {
            return(this->withinYBound(obstacle) && obstacle->hSDistance(this) <= 10);
        }
    }
    else if(enemy != nullptr){
        if(orientation == 1)
        {
            return(this->withinXBound(enemy) && enemy->vSDistance(this) > 10 && enemy->isNegativeD());
        }
        else if(orientation == 2)
        {
            return(this->withinYBound(enemy) && enemy->hSDistance(this) > 10 && !(enemy->isNegativeD()));
        }
        else if(orientation == 3)
        {
            return(this->withinXBound(enemy) && enemy->vSDistance(this) > 10 && !(enemy->isNegativeD()));
        }
        else if(orientation == 4)
        {
            cout << enemy->isNegativeD();
            return(this->withinYBound(enemy) && enemy->hSDistance(this) > 10 && enemy->isNegativeD());
        }
    }
    else if(player != nullptr){
            if(orientation == 1)
            {
                return(this->withinXBound(player) && player->vSDistance(this) <= 10);
            }
            else if(orientation == 2)
            {
                return(this->withinYBound(player) && player->hSDistance(this) > 10);
            }
            else if(orientation == 3)
            {
                return(this->withinXBound(player) && player->vSDistance(this) > 10);
            }
            else if(orientation == 4)
            {
                return(this->withinYBound(player) && player->hSDistance(this) <= 10);
            }
        }
    return false;

}


