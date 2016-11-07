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

bool WorldCharacter::isBoardering(WorldObject *obj)
{
    WorldObstacle* obstacle = dynamic_cast<WorldObstacle*>(obj);
    WorldEnemy* enemy = dynamic_cast<WorldEnemy*>(obj);
    WorldPlayer* player = dynamic_cast<WorldPlayer*>(obj);
    WorldNPC* npc = dynamic_cast<WorldNPC*>(obj);
    if(obstacle != nullptr){
        if(orientation == 1)
        {
            return(this->withinXBound(obstacle) && obstacle->vSDistance(this) <= 40);
        }
        else if(orientation == 2)
        {
            return(this->withinYBound(obstacle) && this->hSDistance(obstacle) <= 40);
        }
        else if(orientation == 3)
        {
            return(this->withinXBound(obstacle) && this->vSDistance(obstacle) <= 40);
        }
        else if(orientation == 4)
        {
            return(this->withinYBound(obstacle) && obstacle->hSDistance(this) <= 40);
        }
    }
    else if(enemy != nullptr){
        if(orientation == 1)
        {
            return(this->withinXBound(enemy) && enemy->vSDistance(this) <= 30);
        }
        else if(orientation == 2)
        {
            return(this->withinYBound(enemy) && this->hSDistance(enemy) <= 40);
        }
        else if(orientation == 3)
        {
            return(this->withinXBound(enemy) && this->vSDistance(enemy) <= 40);
        }
        else if(orientation == 4)
        {
            return(this->withinYBound(enemy) && enemy->hSDistance(this) <= 30);
        }
    }
    else if(player != nullptr){
            if(orientation == 1)
            {
                return(player->withinXBound(this) && player->vSDistance(this) <= 40);
            }
            else if(orientation == 2)
            {
                return(player->withinYBound(this) && this->hSDistance(player) < 40);
            }
            else if(orientation == 3)
            {
                return(player->withinXBound(this) && this->vSDistance(player) < 40);
            }
            else if(orientation == 4)
            {
                return(player->withinYBound(this) && player->hSDistance(this) <= 40);
            }
        }

        else if(npc != nullptr){
            if(orientation == 1)
            {
                return(this->withinXBound(npc) && npc->vSDistance(this) <= 30);
            }
            else if(orientation == 2)
            {
                return(this->withinYBound(npc) && this->hSDistance(npc) <= 20);
            }
            else if(orientation == 3)
            {
                return(this->withinXBound(npc) && this->vSDistance(npc) <= 20);
            }
            else if(orientation == 4)
            {
                return(this->withinYBound(npc) && npc->hSDistance(this) <= 30);
            }
        }
    return false;

}


