#ifndef WORLDNPC_H
#define WORLDNPC_H

#include <QString>
#include "worldchar.h"
#include "worlditem.h"
#include <QString>

class WorldNPC: public WorldCharacter {

private:

    WorldItem* giveableItem;
    QString advice;

public:

    WorldNPC();
    QString Speak();
};

#endif // NPC_H
