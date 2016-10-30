#include "player.h"
#include <QKeyEvent>
#include <QTimer>
#include <string>
#include "worldplayer.h"


QSet<Qt::Key> keysPressed;

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    timer = new QTimer(this);
    timer->setInterval(13);

    timertwo = new QTimer(this);
    timertwo->setInterval(100);

}



void Player::keyPressEvent(QKeyEvent *event) {


    if (event->key() == Qt::Key_Left) {
        if (!timer->isActive() && !event->isAutoRepeat()){
            setPixmap(QPixmap(":/images/images/WalkLeft1.png").scaled(60,60));
            player->setOrientation(4);
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
            timer->start();
            connect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimLeft()));
            timertwo->start();
        }

    }
    else if (event->key() == Qt::Key_Right) {
        if (!timer->isActive() && !event->isAutoRepeat()){
            setPixmap(QPixmap(":/images/images/WalkRight1.png").scaled(60,60));
            player->setOrientation(2);
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitRight()));
            timer->start();
            connect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimRight()));
            timertwo->start();
        }
    }

    else if (event->key() == Qt::Key_Up) {
        if (!timer->isActive() && !event->isAutoRepeat()){
            setPixmap(QPixmap(":/images/images/WalkUp1.png").scaled(60,60));
            player->setOrientation(1);
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitUp()));
            timer->start();
            connect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimUp()));
            timertwo->start();
        }
    }

    else if (event->key() == Qt::Key_Down) {
        if (!timer->isActive() && !event->isAutoRepeat()){
            setPixmap(QPixmap(":/images/images/WalkDown1.png").scaled(60,60));
            player->setOrientation(3);
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitDown()));
            timer->start();
            connect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimDown()));
            timertwo->start();
        }
    }

    else if (event->key() == Qt::Key_Space) {
        if (player->getOrientation() == 1) {

        }
        else if (player->getOrientation() == 2) {

        }
        else if (player->getOrientation() == 3) {

        }
        else if (player->getOrientation() == 4) {

        }
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Left) {
        if (event->isAutoRepeat() == false){
            timer->stop();
            disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
            timertwo->stop();
            disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimLeft()));
            setPixmap(QPixmap(":/images/images/WalkLeft1.png").scaled(60,60));
            animation = 1;
        }


    }
    else if (event->key() == Qt::Key_Right) {
        if (event->isAutoRepeat() == false){
            timer->stop();
            disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitRight()));
            timertwo->stop();
            disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimRight()));
            setPixmap(QPixmap(":/images/images/WalkRight1.png").scaled(60,60));
            animation = 1;
        }

    }

    else if (event->key() == Qt::Key_Up) {
        if (event->isAutoRepeat() == false){
            timer->stop();
            disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitUp()));
            timertwo->stop();
            disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimUp()));
            setPixmap(QPixmap(":/images/images/WalkUp1.png").scaled(60,60));
            animation = 1;
        }

    }

    else if (event->key() == Qt::Key_Down) {
        if (event->isAutoRepeat() == false){
            timer->stop();
            disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitDown()));
            timertwo->stop();
            disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimDown()));
            setPixmap(QPixmap(":/images/images/WalkDown1.png").scaled(60,60));
            animation = 1;
         }


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

    string str = string(":/images/images/WalkUp") + to_string(animation) + ".png";
    const char * c = str.c_str();
    setPixmap(QPixmap(c).scaled(60,60));
    if (animation == 9) {
        animation = 1;
    } else {
        animation++;
    }
}

void Player::timerAnimDown()
{
    string str = string(":/images/images/WalkDown") + to_string(animation) + ".png";
    const char * c = str.c_str();
    setPixmap(QPixmap(c).scaled(60,60));
    if (animation == 9) {
        animation = 1;
    } else {
        animation++;
    }
}

void Player::timerAnimLeft()
{
    string str = string(":/images/images/WalkLeft") + to_string(animation) + ".png";
    const char * c = str.c_str();
    setPixmap(QPixmap(c).scaled(60,60));
    if (animation == 9) {
        animation = 1;
    } else {
        animation++;
    }
}

void Player::timerAnimRight()
{
    string str = string(":/images/images/WalkRight") + to_string(animation) + ".png";
    const char * c = str.c_str();
    setPixmap(QPixmap(c).scaled(60,60));
    if (animation == 9) {
        animation = 1;
    } else {
        animation++;
    }
}

