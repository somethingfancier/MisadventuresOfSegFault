#include "enemy.h"
#include "worldenemy.h"
#include <QTimer>


Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/images/Slime1.png").scaled(40, 40));

}
void Enemy::setTimer(QTimer* newTimer)
{
    timer = newTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Enemy::move()
{
    if(player != NULL && enemy != NULL)
    {
        enemy->follow(player);
        this->updatePos();
    }
}
