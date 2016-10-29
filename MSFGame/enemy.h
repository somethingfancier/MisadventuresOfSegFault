#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include "worldenemy.h"

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT

    WorldEnemy *enemy;
    QTimer* timer;
    QTimer* timertwo;

public:

    Enemy(QGraphicsItem * parent=0);

    //Accesors
    WorldEnemy* getEnemy(){return enemy;}

    //Mutators
    void setEnemy(WorldEnemy* newEnemy){enemy = newEnemy;}

public slots:
    void move();

};

#endif // ENEMY_H
