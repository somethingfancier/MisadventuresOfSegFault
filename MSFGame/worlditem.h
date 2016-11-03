#ifndef WORLDITEM_H
#define WORLDITEM_H

#include "worldobject.h"
#include <string>

using namespace std;

class WorldItem : public WorldObject {

private:
    bool equippable;  //shows if the item can be used by a world character
    bool equipped;    //shows whether a world character has equpped the item
    int strength;     //the effects on the world character
    int defense;      //
    int healing;      //
    string property;  //representing the type of item eg fire, ice, etc
    int x;
    int y;

public:
    //Constructor
    WorldItem(): equippable(false),equipped(false),strength(0),defense(0),healing(0),property(""){}
    WorldItem(string newProp, int newX, int newY): property(newProp), x(newX), y(newY) {}

    //Accessors
    bool getEquippable(){return equippable;}
    bool getEquipped(){return equipped;}

    int getStrength(){return strength;}
    int getDefense(){return defense;}
    int getHealing(){return healing;}

    string getProperty(){return property;}
    int getX(){return x;}
    int getY(){return y;}


    //Setters
    void setEquippable(bool newState){equippable = newState;}
    void setEquipped(bool newState){equipped = newState;}

    void setStrength(int newStrength){strength = newStrength;}
    void setDefense(int newDefense){defense = newDefense;}
    void setHealing(int newHealing){healing = newHealing;}

    void setProperty(string newProperty){property = newProperty;}
    void setX(int newX){x = newX;}
    void setY(int newY){y = newY;}
};

#endif // WORLDITEM_H
