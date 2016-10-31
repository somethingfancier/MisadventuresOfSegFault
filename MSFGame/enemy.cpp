#include "enemy.h"
#include "worldenemy.h"
#include <QTimer>


Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/images/Slime1.png").scaled(60, 60));
    numMoves = 0;

    timer = new QTimer(this);
    timer->setInterval(30);

    timertwo = new QTimer(this);
    timertwo->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start();

}
void Enemy::setTimer(QTimer* newTimer)
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer = newTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Enemy::move()
{
    if(player != NULL && enemy != NULL)
    {
        enemy->move(player);
        this->updatePos();
        numMoves++;
    }
    if (numMoves == 20)
    {
        enemy->rotateL();
        numMoves = 0;
    }
}
