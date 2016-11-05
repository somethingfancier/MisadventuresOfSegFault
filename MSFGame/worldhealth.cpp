#include "worldhealth.h"

WorldHealth::WorldHealth(){
    health = 10;
}

void WorldHealth::increase(int amount){
    health = health + amount;
}

void WorldHealth::decrease(int amount){
    health = health - amount;
}

int WorldHealth::getHealth() {
    return health;
}

void WorldHealth::setHealth(int healthAmount) {
    health = healthAmount;
}
