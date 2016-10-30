#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"

void WorldPlayer::strike(WorldCharacter* chosenChar)
{
    WorldEnemy* chosenEnemy = static_cast<WorldEnemy*>(chosenChar);
    if(chosenEnemy != NULL)
    {
        chosenEnemy->hit(this->getStrength());
    }
}

