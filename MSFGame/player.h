#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "worldplayer.h"
#include "world.h"
#include "score.h"
#include "lives.h"

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    WorldPlayer *player;
    World   *world;
    Score* score;
    Lives* lives;


public:

    Player(QGraphicsItem * parent=0);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    //Accesors
    WorldPlayer* getPlayer(){return player;}
    QTimer* getTimer(){return timer;}
    Score* getScore(){return score;}
    World* getWorld(){return world;}
    Lives* getLives(){return lives;}

    //Mutators
    void setPlayer(WorldPlayer* newPlayer){player = newPlayer;}
    void setWorld(World* newWorld){world = newWorld;}
    void setScore(Score* newScore){score = newScore;}
    void setLives(Lives* newLives){lives = newLives;}

    void updatePos(){this->setPos(player->getX() - 15,player->getY() - 15);}

private slots:

    void timerHitUp();
    void timerHitDown();
    void timerHitLeft();
    void timerHitRight();
    void timerAnimUp();
    void timerAnimDown();
    void timerAnimLeft();
    void timerAnimRight();
    void timerSwordUp();
    void timerSwordDown();
    void timerSwordLeft();
    void timerSwordRight();
    void timerCool();


private:
    QTimer* timer;
    QTimer* timertwo;
    QTimer* timerthree;
    QTimer* timerCooldown;
    int animation = 1;
    bool mag = false;

};

#endif // PLAYER_H
