#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "world.h"
#include "score.h"

class Universe{

private:
    WorldPlayer* player;
    Universe* instance;
    vector<World*> worlds;
    Score* score;
    Score* highscore;

public:
    void Save();
    void Load();
    void Reset();
};

#endif // UNIVERSE_H
