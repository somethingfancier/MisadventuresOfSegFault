#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "world.h"
#include "worldplayer.h"
#include "worldscore.h"

class Universe{

private:
    int numWorlds;
    WorldPlayer* player;
    static Universe* instance_;
    vector<World*> worlds;
    World* activeWorld;
    //Score* highscore;

public:
    static Universe& instance();

    //Constructor
    Universe():numWorlds(0){player = NULL;}

    //Accesors
    WorldPlayer* getPlayer(){return player;}

    //Mutators
    void setPlayer(WorldPlayer* newPlayer){player = newPlayer;}
    //Get Specific World from Vector
    World* getWorld(int id);

    //Adders for Vector
    void addWorld(World*);
    //void Save();
    //void Load();
    //void Reset();
    void createFirstWorld();
    void createSecondWorld();

}; 

#endif // UNIVERSE_H
