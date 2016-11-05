#ifndef WORLDPLAYER_H
#define WORLDPLAYER_H

#include <worldchar.h>
#include "worlditem.h"
#include "world.h"
#include <vector>
#include <string>
#include <worldscore.h>
#include <worldlives.h>
#include <worldhealth.h>

class WorldPlayer : public WorldCharacter
{
private:
    WorldLives* lives;                      //Total lives of a player
    WorldItem* equippedItem;        //Item that the player is using
    vector<WorldItem*> playerItems; //All of the items that a player has collected
    string username;                //Entered name of a Player
    WorldScore* score;
    WorldHealth* health;
public:
    //Constructor
    WorldPlayer(): username("<Segfault>"){equippedItem = NULL;} //Lives of a player intially set to 3
    ~WorldPlayer(){}

    //Accessors
    string getUserName(){return username;}

    //Mutators
    void setLives(WorldLives* newLives){lives = newLives;}
    void setScore(WorldScore* newScore){score = newScore;}
    void setHealth(WorldHealth* newHealth){health = newHealth;}
    void setUsername(){username = "<SegFault>";}      //Indiscriminately set the player's name to SegFault
                                                      //(Thus the madness begins)
    void strike(WorldCharacter*);
    bool longAttack();
    void attack(World*);
};

#endif // WORLDPLAYER_H
