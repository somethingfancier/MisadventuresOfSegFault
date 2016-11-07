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
    bool canAttack;
    bool canFollow;

public:
    //Constructor
    WorldEnemy():property(""), awareness(1), alerted(false), canAttack(true), canFollow(true){this->setWidth(35); this->setHeight(25);this->setHealth(3); this->setName(":/images/images/Slime");}

    //Accessor
    string getProperty() {return property;}
    bool isAlerted(){return alerted;}
    bool engaged(){return canAttack;}
    bool trackingOn(){return canFollow;}

    //Mutator
    void setProperty(string newProperty) {property = newProperty;}
    void setAwareness(double newAwareness) {awareness = newAwareness;}
    void setAlerted(bool newState){alerted = newState;}
    void setAttack(bool newState){canAttack = newState;}
    void setFollow(bool newState){canFollow = newState;}

    //Additional Methods
    void strike(WorldCharacter*);
    void attack(WorldObject*);
    void follow(WorldCharacter*);
    void wander();
    void move(WorldCharacter*);
    void rotateR();
    void rotateL();

    string getData() {
        string data = "enemy," + WorldCharacter::getData();
        data += "," + to_string(this->isAlerted());
        return data;
    }

};

#endif // ENEMY_H
