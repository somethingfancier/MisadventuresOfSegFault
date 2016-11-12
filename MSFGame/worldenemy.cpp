#include "worldenemy.h"
#include "worldplayer.h"
#include <iostream>
#include "worldhealth.h"
#include "world.h"
#include "worldchar.h"
#include "universe.h"
#include <cmath>

void WorldEnemy::strike(WorldCharacter* chosenChar)
{
    WorldPlayer* chosenPlayer = dynamic_cast<WorldPlayer*>(chosenChar);
    if(chosenPlayer != NULL)
    {
        chosenPlayer->hit(this->getStrength());
    }
}

void WorldEnemy::attack(WorldObject* obj)
{
    WorldPlayer* chosenPlayer = dynamic_cast<WorldPlayer*>(obj);
    if(chosenPlayer != NULL && this->isBoardering(chosenPlayer) && canAttack)
    {
        this->strike(chosenPlayer);
        canAttack = false;
    }
}

void WorldEnemy::follow(WorldCharacter* chosenChar)
{
    WorldPlayer* chosenPlayer = dynamic_cast<WorldPlayer*>(chosenChar);
    if(chosenPlayer != NULL)
    {
        int hTravel = this->hDistance(chosenPlayer);
        int vTravel = this->vDistance(chosenPlayer);

        if(this->distance(chosenPlayer) < 100*awareness && !(this->isBoardering(chosenPlayer))){
            this->setAlerted(true);

            if (vTravel >= hTravel && canOrientate)
            {
                if (this->compareY(chosenPlayer))
                {
                    this->setOrientation(1);
                    if(canFollow){
                        this->decY();
                    }
                }
                else
                {
                    this->setOrientation(3);

                    if(canFollow){
                        this->incY();
                    }
                }
            }
            else if(hTravel > vTravel && canOrientate)
            {
                if (this->compareX(chosenPlayer))
                {
                    this->setOrientation(4);

                    if(canFollow){
                        this->decX();
                    }
                }
                else
                {
                    this->setOrientation(2);

                    if(canFollow){
                        this->incX();
                    }
                }
            }
            else
            {
                if(this->getOrientation() == 1)
                {
                    this->decY();
                }
                else if(this->getOrientation() == 2)
                {
                    this->incX();
                }
                else if(this->getOrientation() == 3)
                {
                    this->incY();
                }
                else if(this->getOrientation() == 4)
                {
                    this->decX();
                }
            }
        }
    }
}

void WorldEnemy::wander()
{
    if (this->getOrientation()  == 1)
    {
        this->decY();
    }
    else if (this->getOrientation()  == 2)
    {
        this->incX();
    }
    else if (this->getOrientation()  == 3)
    {
        this->incY();
    }
    else if (this->getOrientation()  == 4)
    {
        this->decX();
    }
    else
    {
        this->setOrientation(1);
    }
}

void WorldEnemy::rotateR()
{
    if (this->getOrientation() == 4)
    {
        this->setOrientation(1);
    }
    else
    {
        this->setOrientation(getOrientation() + 1);
    }
}

void WorldEnemy::rotateL()
{
    if (this->getOrientation() == 1)
    {
        this->setOrientation(4);
    }
    else
    {
         this->setOrientation(getOrientation() - 1);
    }
}

void WorldEnemy::randDir()
{
    this->setOrientation(rand() % 4 + 1);
}

void WorldEnemy::move(WorldCharacter* chosenChar)
{
    WorldPlayer* chosenPlayer = dynamic_cast<WorldPlayer*>(chosenChar);
    if(chosenPlayer != NULL && this->distance(chosenPlayer) <= 100*this->awareness)
    {
        this->follow(chosenChar);
        if(this->isBoardering(chosenPlayer))
            this->attack(chosenPlayer);
    }
    else
    {
        alerted = false;
        if(canFollow)
        {
            this->wander();
        }
    }
}

void WorldEnemy::moveAround(WorldCharacter* player)
{

    if((this->getOrientation() % 2) == 1)
    {
        if(this->getX() >= player->getX())
        {
            this->setOrientation(4);
        }
        else
        {
            this->setOrientation(2);
        }

    }
    else
    {
        if(this->getY() >= player->getY())
        {
            this->setOrientation(1);
        }
        else
        {
            this->setOrientation(3);
        }
    }
}
