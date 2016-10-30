#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include "worldenemy.h"
#include "worldplayer.h"


class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    WorldEnemy *enemy;
    WorldPlayer *player;
    QTimer* timer;
    QTimer* timertwo;

public:

    Enemy(QGraphicsItem * parent=0);

    //Accesors
    WorldEnemy* getEnemy(){return enemy;}
    WorldPlayer* getPlayer(){return player;}

    //Mutators
    void setEnemy(WorldEnemy* newEnemy){enemy = newEnemy;}
    void setPlayer(WorldPlayer* newPlayer){player = newPlayer;}
    void setTimer(QTimer* newTimer);


    void updatePos(){this->setPos(enemy->getX(),enemy->getY());}

public slots:
    void move();

};

#endif // ENEMY_H
