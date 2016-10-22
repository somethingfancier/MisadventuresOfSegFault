#ifndef WORLDITEM_H
#define WORLDITEM_H

#include "worldobject.h"
#include <QString>

class WorldItem : public WorldObject {

private:
    bool equippable;
    int strength;
    int defense;
    int heal;
    QString property;

public:

    WorldItem();
};

#endif // WORLDITEM_H
