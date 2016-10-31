#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"
<<<<<<< HEAD
#include "score.h"

extern Score * score;
=======
#include <cmath>
#include <iostream>
>>>>>>> 35bd33bb1280f6dbeeb33e71bd465e64560732c1

void WorldCharacter::hit(int attackDamage)
{
    if(attackDamage > defense){
        health = health - attackDamage + defense;
<<<<<<< HEAD
        if (health <= 0) {
            score->increase(50);
        }
=======
        cout << health;
>>>>>>> 35bd33bb1280f6dbeeb33e71bd465e64560732c1
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
