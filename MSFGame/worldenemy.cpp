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

        //if (this->distance(chosenPlayer) < 25){
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
        //}
    }
}
