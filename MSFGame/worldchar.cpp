#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"
#include <cmath>
#include <iostream>

void WorldCharacter::hit(int attackDamage)
{
    if(attackDamage > defense){
        health = health - attackDamage + defense;
        cout << health;
    }
}

bool WorldCharacter::isFacing(WorldCharacter* chosenChar)
{
    int result = abs(this->getOrientation()-chosenChar->getOrientation());

    if(result == 2)
    {
        return true;
    }
    return false;
}
