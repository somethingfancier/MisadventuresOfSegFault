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
    WorldLives* lives;              //Total lives of a player
    WorldItem* equippedItem;        //Item that the player is using
    vector<WorldItem*> playerItems; //All of the items that a player has collected
    string username;                //Entered name of a Player
    WorldScore* score;
    int onDeadX;
    int onDeadY;
    bool noLives;
    bool book;
    bool key;

public:
    //Constructor
    WorldPlayer(): username("<Segfault>"),onDeadX(640),onDeadY(660), noLives(false), book(false), key(false){lives = new WorldLives; equippedItem = new WorldItem(); score = new WorldScore();} //Lives of a player intially set to 3
    ~WorldPlayer(){}

    //Accessors
    string getUserName(){return username;}
    WorldLives* getLives(){return lives;}
    WorldItem* getItem(){return equippedItem;}
    int getDeadLocX(){return onDeadX;}
    int getDeadLocy(){return onDeadY;}
    bool getNoLives(){return noLives;}
    bool getBook(){return book;}
    bool getKey(){return key;}
    WorldScore* getScore(){return score;}

    //Mutators
    void setLives(WorldLives* newLives){lives = newLives;}
    void setScore(WorldScore* newScore){score = newScore;}
    void setItem(WorldItem* newItem){equippedItem = newItem;}
    void setUsername(){username = "<SegFault>";}
    void setNoLives(bool lifeState){noLives = lifeState;}
    void setBook(bool newBook){book = newBook;}
    void setKey(bool newKey){key = newKey;}
                                                      //Indiscriminately set the player's name to SegFault
                                                      //(Thus the madness begins)
    void strike(WorldCharacter*);
    bool longAttack();
    void attack(World*);
    void applyItem();
};

#endif // WORLDPLAYER_H
