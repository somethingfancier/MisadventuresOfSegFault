#include "player.h"
#include <QKeyEvent>
#include <QTimer>
#include "worldplayer.h"

QSet<Qt::Key> keysPressed;

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    timer = new QTimer(this);
    timer->setInterval(8);

    timertwo = new QTimer(this);
    timertwo->setInterval(100);

}



void Player::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Left) {
        if (timer->isActive() == false){
            setPixmap(QPixmap(":/images/images/left2.PNG"));
            player->setOrientation(4);
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
            timer->start();
        }

    }
    else if (event->key() == Qt::Key_Right) {
        if (timer->isActive() == false){
            setPixmap(QPixmap(":/images/images/right2.PNG"));
            player->setOrientation(2);
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitRight()));
            timer->start();
        }
    }

    else if (event->key() == Qt::Key_Up) {
        if (timer->isActive() == false){
            setPixmap(QPixmap(":/images/images/back2.PNG"));
            player->setOrientation(1);
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitUp()));
            timer->start();
        }
    }

    else if (event->key() == Qt::Key_Down) {
        if (timer->isActive() == false){
            setPixmap(QPixmap(":/images/images/front2.PNG"));
            player->setOrientation(3);
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitDown()));
            timer->start();
        }

    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Left) {
        timer->stop();
        disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
        setPixmap(QPixmap(":/images/images/left2.PNG"));


    }
    else if (event->key() == Qt::Key_Right) {
        timer->stop();
        disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitRight()));
        setPixmap(QPixmap(":/images/images/right2.PNG"));

    }

    else if (event->key() == Qt::Key_Up) {
        timer->stop();
        disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitUp()));
        setPixmap(QPixmap(":/images/images/back2.PNG"));

    }

    else if (event->key() == Qt::Key_Down) {
        timer->stop();
        disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitDown()));
        setPixmap(QPixmap(":/images/images/front2.PNG"));


    }
}



void Player::timerHitUp()
{
    player->decY();
    this->updatePos();
}

void Player::timerHitDown()
{
    player->incY();
    this->updatePos();

}

void Player::timerHitLeft()
{
    player->decX();
    this->updatePos();
}

void Player::timerHitRight()
{
    player->incX();
    this->updatePos();

}

void Player::timerAnimUp()
{

}

void Player::timerAnimDown()
{

}

void Player::timerAnimLeft()
{

}

void Player::timerAnimRight()
{

}

