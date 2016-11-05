#include "worldlives.h"

WorldLives::WorldLives(){
    lives = 3;
}

void WorldLives::increase(int amount){
    lives = lives + amount;
}

void WorldLives::decrease(int amount){
    lives = lives - amount;
}

int WorldLives::getLives() {
    return lives;
}

void WorldLives::setLives(int numLives) {
    lives = numLives;
}
