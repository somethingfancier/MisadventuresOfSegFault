#ifndef WORLDCHAR_H
#define WORLDCHAR_H

class Character : public WorldObject {

public:
    int health;
    int strength;
    int defense;
    bool dead;
    double orientation;

    character();

bool attack(WorldObject*) {
    return WorldObject;
}

#endif // WORLDCHAR_H
