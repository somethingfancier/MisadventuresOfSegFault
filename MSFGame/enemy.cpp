#include "enemy.h"
#include "worldenemy.h"
#include <QTimer>
#include "obstacle.h"
#include <typeinfo>
#include "universe.h"
#include "player.h"


Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    collided = false;
    enemy = new WorldEnemy();
    player = Universe::instance().getPlayer();
    this->setPixmap(QPixmap(":/images/images/Slime1.png").scaled(60, 60));
    numMoves = 0;
    animation = 1;

    timer = new QTimer(this);
    timer->setInterval(30);

    timertwo = new QTimer(this);
    timertwo->setInterval(250);

    timerthree = new QTimer(this);
    timerthree->setInterval(100);

    attacktimer = new QTimer(this);
    attacktimer->setInterval(1000);
    connect(attacktimer, SIGNAL(timeout()),this,SLOT(setAttack()));
    attacktimer->start();

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
    QList<QGraphicsItem *> colliding_items = collidingItems();

    if(player != NULL && enemy != NULL)
    {
        if(enemy->isDead())
        {
            animation = 1;
            disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));
            timer->stop();
            connect(timerthree, SIGNAL(timeout()), this, SLOT(deathAnimation()));
            timerthree->start();
        }

        else if (numMoves == 20)
        {
            if(!enemy->isAlerted()){
                enemy->randDir();
            }
            numMoves = 0;

            disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));
            connect(timertwo, SIGNAL(timeout()), this, SLOT(bounceAnimation()));

            timer->stop();
            timertwo->start();
        }

        if(colliding_items.size() >= 1)
        {
            for (int i = 0, n = colliding_items.size(); i<n; ++i) {

                if (colliding_items[i]) {
                    Obstacle* obj = dynamic_cast<Obstacle*>(colliding_items[i]);
                    Player* myPlayer = dynamic_cast<Player*>(colliding_items[i]);

                    if(obj != nullptr){
                        enemy->setCanOrientate(false);
                        enemy->moveAround(player);
                        if(enemy->isBoardering(obj->getObstacle())){
                            enemy->setFollow(false);
                        }
                    }
                    if(myPlayer != nullptr)
                    {
                        collided = true;
                    }
                }
            }
        }

        if(enemy->trackingOn())
            enemy->move(player);


        enemy->setFollow(true);
        enemy->setCanOrientate(true);


        this->updatePos();
        numMoves++;

    }
}

void Enemy::bounceAnimation()
{
    if(this->getEnemy()->isDead())
    {
        animation = 1;
        disconnect(timertwo, SIGNAL(timeout()), this, SLOT(bounceAnimation()));
        timertwo->stop();
        connect(timerthree, SIGNAL(timeout()), this, SLOT(deathAnimation()));
        timerthree->start();
    }

    if(this->getEnemy()->distance(this->getPlayer()) <= 15){
        numMoves--;
    }

    if(numMoves == 7){
        numMoves = 0;
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        disconnect(timertwo, SIGNAL(timeout()), this, SLOT(bounceAnimation()));
        timer->start();
        timertwo->stop();
    }
    else
    {
        if(animation == 2)
        {

            string img = this->getEnemy()->getName() + to_string(animation) + ".png";

            const char* cImg = img.c_str();
            this->setPixmap(QPixmap(cImg).scaled(60,60));
            animation--;
        }
        else
        {
            string img = this->getEnemy()->getName() + to_string(animation) + ".png";
            const char* cImg = img.c_str();
            this->setPixmap(QPixmap(cImg).scaled(60,60));
            animation++;
        }
        numMoves++;
    }

}

void Enemy::deathAnimation()
{
    if(animation >= 4)
    {
        disconnect(timertwo, SIGNAL(timeout()), this, SLOT(deathAnimation()));
        timertwo->stop();
    }
    else
    {
        string img = ":/images/images/SlimeBurst" + to_string(animation) + ".png";
        const char* cImg = img.c_str();
        this->setPixmap(QPixmap(cImg).scaled(60,60));
        animation++;
    }
}

void Enemy::setAttack()
{
    enemy->setAttack(true);
}
