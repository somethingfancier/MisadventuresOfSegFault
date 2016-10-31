#ifndef WORLDENEMY_H
#define WORLDENEMY_H

#include <string>
#include "worldchar.h"

using namespace std;

class WorldEnemy: public WorldCharacter{
private:
    string property;
    double awareness;

public:
    //Constructor
    WorldEnemy():property(""), awareness(0.50){}

    //Accessor
    string getProperty() {return property;}

    //Mutator
    void setProperty(string newProperty) {property = newProperty;}
    void setAwareness(double newAwareness) {awareness = newAwareness;}

    //Additional Methods
    void strike(WorldCharacter*);
    void follow(WorldCharacter*);

};

#endif // ENEMY_H
