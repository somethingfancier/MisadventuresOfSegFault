#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"
#include "world.h"
#include <cmath>

void WorldPlayer::strike(WorldCharacter* chosenChar)
{
    WorldEnemy* chosenEnemy = static_cast<WorldEnemy*>(chosenChar);
    if(chosenEnemy != NULL)
    {
        chosenEnemy->hit(this->getStrength());
    }
}

void WorldPlayer::attack(World* world)
{
    for(unsigned int i = 0; i < world->getCharacters().size(); i++)
    {
       WorldEnemy* chosenEnemy = static_cast<WorldEnemy*>(world->getCharacters().at(i));

       if(chosenEnemy)
       {
           if(this->distance(chosenEnemy) < 20 && this->isFacing(chosenEnemy))
           {
                this->strike(chosenEnemy);
           }
       }
    }
}
