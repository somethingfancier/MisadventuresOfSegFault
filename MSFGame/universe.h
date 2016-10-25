#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "world.h"
#include "worldplayer.h"
#include "score.h"

class Universe{

private:
    int numWorlds;
    WorldPlayer* player;
    static Universe* instance_;
    vector<World*> worlds;
    //Score* score;
    //Score* highscore;

public:
    static Universe& instance();

    //Accesors
    WorldPlayer* getPlayer(){return player;}

    //Mutators
    void setPlayer(WorldPlayer* newPlayer){player = newPlayer;}

    //Adders for Vector
    void addWorld(World*);
    //void Save();
    //void Load();
    //void Reset();
    void createFirstWorld();

}; 

#endif // UNIVERSE_H
