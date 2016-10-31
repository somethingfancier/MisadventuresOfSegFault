#ifndef WORLDNPC_H
#define WORLDNPC_H

#include <string>
#include "worldchar.h"
#include "worlditem.h"

using namespace std;

class WorldNPC: public WorldCharacter {

private:
    string advice;          //Some knowledge that the NPC imparts to a player
    WorldItem* giveableItem;//An item that can be given to the Player
    bool gaveItem;          //Indicates if the NPC gave the item to a player already

public:
    //Constructor
    WorldNPC(): advice("I have no advice for you."),gaveItem(false){giveableItem = NULL;}

    //Accessors
    string getAdvice(){return advice;}
    WorldItem* getItem(){return giveableItem;}

    //Mutators
    void setAdvice(string newAdvice){advice = newAdvice;}
    void setGiveableItem(WorldItem* newItem){giveableItem = newItem;}

    void strike(WorldCharacter*){}
    void attack(WorldObject*){}
};

#endif // NPC_H
