#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"
#include "universe.h"
#include "score.h"

class Game: public QGraphicsView
{
public:
    Game (QWidget *parent=0);

    QGraphicsView *view;
    QGraphicsScene *scene;
    Player *player;
    Enemy *enemy;
    Universe *universe;

    //Accesors
    Player* getPlayer(){return player;}

    //Mutators
    void setPlayer(Player* newPlayer){
        if (newPlayer != NULL) {
            player = newPlayer;
        }
    }

    void initialize(int id);

};

#endif // GAME_H
