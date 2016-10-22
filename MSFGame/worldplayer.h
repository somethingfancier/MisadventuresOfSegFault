#ifndef WORLDPLAYER_H
#define WORLDPLAYER_H

#endif // WORLDPLAYER_H

#include <QString>
#include"worlditem.h"
#include "worldchar.h"

class WorldPlayer: public WorldCharacter {

private:
    int lives;
    WorldItem* item;
    vector<WorldItem*> items;

public:
    void Move();
    void LongAttack(int, int);
    QString Speak();
};
