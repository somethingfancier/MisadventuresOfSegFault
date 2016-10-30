#include "enemy.h"
#include "worldenemy.h"
#include <QTimer>


Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/images/Slime1.png"));
    timer = new QTimer(this);
    timer->setInterval(8);

    timertwo = new QTimer(this);
    timertwo->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start();

}

void Enemy::move()
{
    timer->stop();
    if(player != NULL && enemy != NULL)
    {
        enemy->follow(player);
        this->updatePos();
    }
    timer->start();
}
