#include "worldscore.h"

WorldScore::WorldScore(){
    score = 0;
}

void WorldScore::increase(int amount){
    score = score + amount;
}

int WorldScore::getScore() {
    return score;
}
