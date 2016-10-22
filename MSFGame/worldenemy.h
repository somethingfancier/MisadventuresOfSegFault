#ifndef WORLDENEMY_H
#define WORLDENEMY_H

#include <QString>
#include "worldchar.h"

class WorldEnemy: public WorldCharacter{
private:
    QString property;

public:
    WorldEnemy();
    void Move();

};

#endif // ENEMY_H
