#ifndef WORLDCHAR_H
#define WORLDCHAR_H

#include "worldobject.h"

using namespace std;

class WorldCharacter : public WorldObject {

private:
    int health;       //the health of a character in the World
    int strength;     //the strength of a character
    int defense;      //the defense of a character
    int orientation;  //changed this from a double to an int
    int prevOrientation;
    bool dead;
    bool movableL;
    bool movableR;
    bool movableU;
    bool movableD;

public:
    //Constructor
    WorldCharacter():health(10),strength(1),defense(0),orientation(0),prevOrientation(1),dead(false),movableL(true),movableR(true),movableU(true),movableD(true){}

    virtual ~WorldCharacter(){}

    //Accesors
    int getHealth(){return health;}
    int getStrength(){return strength;}
    int getDefense(){return defense;}
    int getOrientation(){return orientation;}
    bool isDead(){return dead;}
    bool isMovableR(){return movableR;}
    bool isMovableL(){return movableL;}
    bool isMovableU(){return movableU;}
    bool isMovableD(){return movableD;}

    //Mutators
    void setStrength(int newStrength){strength = newStrength;}
    void setDefense(int newDefense){defense = newDefense;}
    void setHealth(int newHealth){health = newHealth;}
    void setOrientation(int newOrientation){prevOrientation = orientation; orientation = newOrientation;}
    void setDead(bool lifeState){dead = lifeState;}
    void setMovableR(bool newState){movableR = newState;}
    void setMovableL(bool newState){movableL = newState;}
    void setMovableU(bool newState){movableU = newState;}
    void setMovableD(bool newState){movableD = newState;}

    bool isNewOrientation(){return(orientation == prevOrientation);}
    void setDirections();
    bool isFacing(WorldCharacter*);
    bool isBoardering(WorldObject*);

    void incCX(){if(this->isMovableR()){this->incX();}}
    void incCY(){if(this->isMovableD()){this->incY();}}
    void decCX(){if(this->isMovableL()){this->decX();}}
    void decCY(){if(this->isMovableU()){this->decY();}}

    void hit(int attackDamage);
    void heal(int healPower){health = health + healPower;}
    void knockBack(WorldCharacter*);

    //Methods to Be implemented
    virtual void strike(WorldCharacter*)=0;

    string getData() {

        string data = WorldObject::getData();
        data += ("," + to_string(this->getHealth()) + ","
                + to_string(this->getStrength()) + ","
                + to_string(this->getDefense()) + ","
                + to_string(this->getOrientation()) + ","
                + to_string(this->isDead()));
        return data;
    }
};

#endif // WORLDCHAR_H
