#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "worldscore.h"
#include "world.h"
#include "worldobject.h"
#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"
#include "worldnpc.h"
#include "worlditem.h"
#include "worldobstacle.h"
#include <iostream>
#include <fstream>

using namespace std;

class Universe{

private:
    int numWorlds;
    int currentWorld;
    WorldPlayer* player;
    static Universe* instance_;
    vector<World*> worlds;
    //Score* highscore;

public:
    static Universe& instance();

    //Constructor
    Universe():numWorlds(0){player = NULL;}

    //Accesors
    WorldPlayer* getPlayer(){return player;}
    vector<World*> getWorlds(){return worlds;}

    //Mutators
    void setPlayer(WorldPlayer* newPlayer){player = newPlayer;}
    //Get Specific World from Vector
    World* getWorld(int id);

    //Adders for Vector
    void addWorld(World*);
    void Save();
    void Load();
    //void Reset();
    void createFirstWorld();
    void createSecondWorld();
    void createThirdWorld();
    void createFourthWorld();
    void createFifthWorld();
    void createSixthWorld();
    void createEighthWorld();

}; 

#endif // UNIVERSE_H
