#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"
#include "world.h"
#include <cmath>
#include <iostream>

void WorldPlayer::strike(WorldCharacter* chosenChar)
{
    WorldEnemy* chosenEnemy = dynamic_cast<WorldEnemy*>(chosenChar);
    if(chosenEnemy != NULL)
    {
        chosenEnemy->hit(this->getStrength());

        if(chosenEnemy->isDead())
        {
            score->increase(50);
        }
    }
}

void WorldPlayer::attack(World* world)
{
    for(unsigned int i = 0; i < world->getCharacters().size(); i++)
    {
       WorldEnemy* chosenEnemy = dynamic_cast<WorldEnemy*>(world->getCharacters().at(i));

       if(chosenEnemy != NULL && !(chosenEnemy->isDead()))
       {
           if(this->isBoardering(chosenEnemy) || invincible)
           {
               this->strike(chosenEnemy);
           }
       }
    }
}

void WorldPlayer::applyItem()
{
    if(equippedItem != NULL){
        if(equippedItem->getProperty() == "heart"){
            this->getLives()->increase(1);
        } else if (equippedItem->getProperty() == "health") {
            this->setHealth(getHealth() + 5);
        } else if (equippedItem->getProperty() == "book") {
            this->setBook(true);
        } else if (equippedItem->getProperty() == "key") {
            this->setKey(true);
        } else if (equippedItem->getProperty() == "key2") {
            this->setKey2(true);
        } else if (equippedItem->getProperty() == "key3") {
            this->setKey3(true);
        }
        equippedItem->setEquipped(true);
    }
}
string WorldPlayer::getData() {
    string data = "," + WorldCharacter::getData();
    data += "," + to_string(this->getLives()->getLives());
    data += "," + to_string(currentWorld);
    data += "," + to_string(book);
    data += "," + to_string(key);
    data += "," + to_string(key2);
    data += "," + to_string(key3);
    return data;
}
