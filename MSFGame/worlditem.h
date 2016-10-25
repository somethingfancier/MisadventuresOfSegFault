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

public:
    //Constructor
    WorldItem(): equippable(false),equipped(false),strength(0),defense(0),healing(0),property(""){}

    //Accessors
    bool getEquippable(){return equippable;}
    bool getEquipped(){return equipped;}

    int getStrength(){return strength;}
    int getDefense(){return defense;}
    int getHealing(){return healing;}

    string getProperty(){return property;}

    //Setters
    void setEquippable(bool newState){equippable = newState;}
    void setEquipped(bool newState){equipped = newState;}

    void setStrength(int newStrength){strength = newStrength;}
    void setDefense(int newDefense){defense = newDefense;}
    void setHealing(int newHealing){healing = newHealing;}

    void setProperty(string newProperty){property = newProperty;}
};

#endif // WORLDITEM_H
