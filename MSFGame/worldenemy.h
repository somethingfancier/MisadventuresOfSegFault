#ifndef WORLDENEMY_H
#define WORLDENEMY_H

#include <string>
#include "worldchar.h"

using namespace std;

class WorldEnemy: public WorldCharacter{
private:
    string property;

public:
    //Constructor
    WorldEnemy():property(""){}

    //Accessor
    string getProperty() {return property;}

    //Mutator
    void setProperty(string newProperty) {property = newProperty;}

    //Additional Methods
    void strike(WorldCharacter*);
    void follow(WorldCharacter*);

};

#endif // ENEMY_H
