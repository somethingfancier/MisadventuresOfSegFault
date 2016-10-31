#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"
#include "score.h"

extern Score * score;

void WorldCharacter::hit(int attackDamage)
{
    if(attackDamage > defense){
        health = health - attackDamage + defense;
        if (health <= 0) {
            score->increase(50);
        }
    }
}
