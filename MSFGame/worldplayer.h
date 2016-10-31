#ifndef WORLDPLAYER_H
#define WORLDPLAYER_H

#include <worldchar.h>
#include "worlditem.h"
#include "world.h"
#include <vector>
#include <string>

class WorldPlayer : public WorldCharacter
{
private:
    int lives;                      //Total lives of a player
    WorldItem* equippedItem;        //Item that the player is using
    vector<WorldItem*> playerItems; //All of the items that a player has collected
    string username;                //Entered name of a Player

public:
    //Constructor
    WorldPlayer(): lives(3), username("<Segfault>"){equippedItem = NULL;} //Lives of a player intially set to 3
    ~WorldPlayer(){}

    //Accessors
    int getLives(){return lives;}
    string getUserName(){return username;}

    //Mutators
    void setLives(int newLives){lives = newLives;}
    void setUsername(){username = "<SegFault>";}      //Indiscriminately set the player's name to SegFault
                                                      //(Thus the madness begins)
    void strike(WorldCharacter*);
    bool longAttack();
    void attack(World*);
};

#endif // WORLDPLAYER_H
