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

public:
    //Constructor
    WorldCharacter():health(10),strength(1),defense(0),orientation(0),prevOrientation(1),dead(false){}

    virtual ~WorldCharacter(){}

    //Accesors
    int getHealth(){return health;}
    int getStrength(){return strength;}
    int getDefense(){return defense;}
    int getOrientation(){return orientation;}
    bool isDead(){return dead;}

    //Mutators
    void setStrength(int newStrength){strength = newStrength;}
    void setDefense(int newDefense){defense = newDefense;}
    void setHealth(int newHealth){health = newHealth;}
    void setOrientation(int newOrientation){prevOrientation = orientation; orientation = newOrientation;}
    void setDead(bool lifeState){dead = lifeState;}

    bool isNewOrientation(){return(orientation == prevOrientation);}
    void setDirections();
    bool isFacing(WorldCharacter*);
    bool isBoardering(WorldObject*);

    void hit(int attackDamage);
    void heal(int healPower){health = health + healPower;}
    void knockBack(WorldCharacter*);

    //Methods to Be implemented
    virtual void strike(WorldCharacter*){}

    string getData() {

        string data = "," + WorldObject::getData();
        data += ("," + to_string(this->getHealth()) + ","
                + to_string(this->getStrength()) + ","
                + to_string(this->getDefense()) + ","
                + to_string(this->getOrientation()) + ","
                + to_string(this->isDead()));
        return data;
    }
};

#endif // WORLDCHAR_H
