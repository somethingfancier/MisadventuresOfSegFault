#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include "enemy.h"
#include "universe.h"
#include "score.h"
#include "item.h"

class Game: public QGraphicsView
{
    Q_OBJECT
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

private slots:
    void newWorld();
private:
    QTimer *timer;
    int currentWUp;
    int currentWDown;
    int currentWLeft;
    int currentWRight;
};

#endif // GAME_H
