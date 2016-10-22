#ifndef WORLDNPC_H
#define WORLDNPC_H

#include <QString>
#include "worldchar.h"

class WorldNPC: public WorldCharacter {

private:

    WorldItem* item;
    QString advice;

public:

    WorldNPC();
    string Speak();
};

#endif // NPC_H
