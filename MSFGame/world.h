#ifndef WORLD_H
#define WORLD_H

#include "worldenemy.h"
#include "worldplayer.h"
#include "worldobstacle.h"
#include "worlditem.h"
#include "worldnpc.h"

class World{
private:
    int id;
    WorldPlayer* player;
    vector<WorldNPC*> npcs;
    vector<WorldItem*> items;
    vector<WorldEnemy*> enemies;
    obstacles<WorldObstacle*> obstacles;
};

#endif // WORLD_H
