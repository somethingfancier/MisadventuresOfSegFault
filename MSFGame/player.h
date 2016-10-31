#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include "worldplayer.h"
#include "world.h"
#include "score.h"

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    WorldPlayer *player;
    World   *world;
    Score* score;


public:

    Player(QGraphicsItem * parent=0);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    //Accesors
    WorldPlayer* getPlayer(){return player;}
    QTimer* getTimer(){return timer;}
    Score* getScore(){return score;}

    //Mutators
    void setPlayer(WorldPlayer* newPlayer){player = newPlayer;}
    void setWorld(World* newWorld){world = newWorld;}
    void setScore(Score* newScore){score = newScore;}

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
    void newWorld();

private:
    QTimer* timer;
    QTimer* timertwo;
    QTimer* timerthree;
    int animation = 1;

};

#endif // PLAYER_H
