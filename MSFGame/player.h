#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include "worldplayer.h"


class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    WorldPlayer *player;


public:

    Player(QGraphicsItem * parent=0);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    //Accesors
    WorldPlayer* getPlayer(){return player;}
    QTimer* getTimer(){return timer;}

    //Mutators
    void setPlayer(WorldPlayer* newPlayer){player = newPlayer;}

    void updatePos(){this->setPos(player->getX(),player->getY());}

private slots:

    void timerHitUp();
    void timerHitDown();
    void timerHitLeft();
    void timerHitRight();
    void timerAnimUp();
    void timerAnimDown();
    void timerAnimLeft();
    void timerAnimRight();

private:
    QTimer* timer;
    QTimer* timertwo;
    int animation = 1;

};

#endif // PLAYER_H
