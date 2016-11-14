
#include "boss.h"
#include "worldenemy.h"
#include <QTimer>
#include "obstacle.h"
#include <typeinfo>
#include "universe.h"
#include <QMessageBox>

int onlyOneMessagePlease = 0;

Boss::Boss(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    enemy = new WorldEnemy();
    player = Universe::instance().getPlayer();
    this->setPixmap(QPixmap(":/images/images/boss1.png").scaled(60, 60));
    numMoves = 0;
    animation = 1;

    timer = new QTimer(this);
    timer->setInterval(20);

    timertwo = new QTimer(this);
    timertwo->setInterval(100);

    timerthree = new QTimer(this);
    timerthree->setInterval(50);

    attacktimer = new QTimer(this);
    attacktimer->setInterval(1000);
    connect(attacktimer, SIGNAL(timeout()),this,SLOT(setAttack()));
    attacktimer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start();

}

void Boss::setTimer(QTimer* newTimer)
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer = newTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Boss::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(Qt::IntersectsItemShape);

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

        else if (numMoves == 20 && !(enemy->isAlerted()))
        {
            enemy->rotateL();
            numMoves = 0;

            disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));
            connect(timertwo, SIGNAL(timeout()), this, SLOT(bounceAnimation()));

            timer->stop();
            timertwo->start();
        }

        for (int i = 0, n = colliding_items.size(); i<n; ++i) {

            if (colliding_items[i]) {

                Obstacle* obj = dynamic_cast<Obstacle*>(colliding_items[i]);

                if(obj != nullptr){
                    if(!(enemy->isBoardering(obj->getObstacle()))){
                        enemy->move(player);
                    }
                }
            }
        }
        enemy->move(player);

        this->updatePos();
        numMoves++;
    }
}

void Boss::bounceAnimation()
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
        if(animation >= 9)
        {
            animation = 1;
            string img = ":/images/images/boss" + to_string(animation) + ".png";
            const char* cImg = img.c_str();
            this->setPixmap(QPixmap(cImg).scaled(60,60));
            animation++;
        }
        else
        {
            string img = ":/images/images/boss" + to_string(animation) + ".png";
            const char* cImg = img.c_str();
            this->setPixmap(QPixmap(cImg).scaled(60,60));
            animation++;
        }
        numMoves++;
    }

}

void Boss::deathAnimation()
{
    Universe::instance().getWorld(9)->setDownWId(4);
    if(animation >= 4)
    {
        disconnect(timertwo, SIGNAL(timeout()), this, SLOT(deathAnimation()));
        timertwo->stop();
        QMessageBox msgg;
        msgg.setWindowTitle("CONGRATULATIONS!");
        msgg.setText("Congratulations!\n\n You have succesfully defeated the Dark Wizard\n and purged evil from the realm.\n\n If your score is higher than before,\n it has been saved as a new highscore!\n\n Feel free to leave through the bottom\n and go explore the world some more!");
        if (onlyOneMessagePlease < 1)
        {
            Universe::instance().getPlayer()->getScore()->HighscoreSave();
            msgg.exec();
            onlyOneMessagePlease++;
        }
    }
    else
    {
        string img = ":/images/images/SlimeBurst" + to_string(animation) + ".png";
        const char* cImg = img.c_str();
        this->setPixmap(QPixmap(cImg).scaled(60,60));
        animation++;
    }
}

void Boss::setAttack()
{
    enemy->setAttack(true);
}
