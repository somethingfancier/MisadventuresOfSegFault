#include "worldenemy.h"
#include "worldplayer.h"

void WorldEnemy::strike(WorldCharacter* chosenChar)
{
    WorldPlayer* chosenPlayer = static_cast<WorldPlayer*>(chosenChar);
    if(chosenPlayer != NULL)
    {
        chosenPlayer->hit(this->getStrength());
    }
}

void WorldEnemy::follow(WorldCharacter* chosenChar)
{
    WorldPlayer* chosenPlayer = static_cast<WorldPlayer*>(chosenChar);
    if(chosenPlayer != NULL)
    {
        int hTravel = this->hDistance(chosenPlayer);
        int vTravel = this->vDistance(chosenPlayer);

        if(this->distance(chosenPlayer) < 100*awareness){
            if (vTravel >= hTravel && vTravel > 10)
            {
                if (this->compareY(chosenPlayer))
                {
                    this->setOrientation(3);
                    this->decY();
                }
                else
                {
                    this->setOrientation(1);
                    this->incY();
                }
            }
            else if(hTravel > vTravel && hTravel > 10)
            {
                if (this->compareX(chosenPlayer))
                {
                    this->setOrientation(4);
                    this->decX();
                }
                else
                {
                    this->setOrientation(2);
                    this->incX();
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

void WorldEnemy::move(WorldCharacter* chosenChar)
{
    WorldPlayer* chosenPlayer = static_cast<WorldPlayer*>(chosenChar);
    if(chosenPlayer != NULL && this->distance(chosenPlayer) <= 100*this->awareness)
    {
        this->follow(chosenChar);
    }
    else
    {
        this->wander();
    }
}
