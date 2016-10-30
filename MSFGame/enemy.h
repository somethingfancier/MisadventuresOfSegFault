#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include "worldenemy.h"


class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    WorldEnemy *enemy;
    //QTimer* timer;
    //QTimer* timertwo;

public:

    Enemy(QGraphicsItem * parent=0){this->setPixmap(QPixmap(":/images/images/Slime1.png").scaled(60, 60));}

    //Accesors
    WorldEnemy* getEnemy(){return enemy;}

    //Mutators
    void setEnemy(WorldEnemy* newEnemy){enemy = newEnemy;}

public slots:
    //void move(){};

};

#endif // ENEMY_H
