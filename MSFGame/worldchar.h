#ifndef WORLDCHAR_H
#define WORLDCHAR_H

#include "worldobject.h"

class WorldCharacter : public WorldObject {

private:
    int health;
    int strength;
    int defense;
    bool dead;
    double orientation;

public:
    WorldCharacter();

    bool attack(WorldObject*);
};

#endif // WORLDCHAR_H
