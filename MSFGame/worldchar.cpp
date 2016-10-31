#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"

void WorldCharacter::hit(int attackDamage)
{
    if(attackDamage > defense){
        health = health - attackDamage + defense;
    }
}
