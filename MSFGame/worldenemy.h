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
    bool canOrientate;

public:
    //Constructor
    WorldEnemy():property(""), awareness(1), alerted(false), canAttack(true), canFollow(true), canOrientate(true){this->setWidth(30); this->setHeight(25);this->setHealth(3); this->setName(":/images/images/Slime1");}

    //Accessor
    string getProperty() {return property;}
    bool isAlerted(){return alerted;}
    bool getOState(){return canOrientate;}
    bool engaged(){return canAttack;}
    bool trackingOn(){return canFollow;}

    //Mutator
    void setProperty(string newProperty) {property = newProperty;}
    void setAwareness(double newAwareness) {awareness = newAwareness;}
    void setAlerted(bool newState){alerted = newState;}
    void setAttack(bool newState){canAttack = newState;}
    void setFollow(bool newState){canFollow = newState;}
    void setCanOrientate(bool state){canOrientate = state;}

    //Additional Methods
    void strike(WorldCharacter*);
    void attack(WorldObject*);
    void follow(WorldCharacter*);
    void wander();
    void move(WorldCharacter*);
    void rotateR();
    void rotateL();
    void randDir();
    void moveAround(WorldCharacter*);

    /*string getData() {
        string data = "," + WorldCharacter::getData();
        data += "," + to_string(this->isAlerted());
        return data;
    }*/

};

#endif // ENEMY_H
