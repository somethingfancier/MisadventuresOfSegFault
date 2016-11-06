#ifndef WORLDENEMY_H
#define WORLDENEMY_H

#include <string>
#include "worldchar.h"

using namespace std;

class WorldEnemy: public WorldCharacter{
private:
    string property;
    double awareness;
    bool alerted;

public:
    //Constructor
    WorldEnemy():property(""), awareness(1), alerted(false){this->setHealth(3); this->setName(":/images/images/Slime");}

    //Accessor
    string getProperty() {return property;}
    bool isAlerted(){return alerted;}

    //Mutator
    void setProperty(string newProperty) {property = newProperty;}
    void setAwareness(double newAwareness) {awareness = newAwareness;}
    void setAlerted(bool newState){alerted = newState;}

    //Additional Methods
    void strike(WorldCharacter*);
    void attack(WorldObject*);
    void follow(WorldCharacter*);
    void wander();
    void move(WorldCharacter*);
    void rotateR();
    void rotateL();

    string getData() {
        string data = WorldCharacter::getData();
        data += "," + to_string(this->isAlerted());
        return data;
    }

};

#endif // ENEMY_H
