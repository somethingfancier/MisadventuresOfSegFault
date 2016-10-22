#ifndef WORLDOBSTACLE_H
#define WORLDOBSTACLE_H

#include <QString>
#include "worldobject.h"

class WorldObstacle: public WorldObject{

private:
    bool destroyable;
    int health;
    QString property;

};

#endif // WORLDOBSTACLE_H
