#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <string>
#include <typeinfo>
#include "worldplayer.h"
#include "enemy.h"
#include "magic.h"
#include "item.h"
#include "obstacle.h"
#include <iostream>

QSet<Qt::Key> keysPressed;

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    timer = new QTimer(this);
    timer->setInterval(13);

    timertwo = new QTimer(this);
    timertwo->setInterval(100);

    timerthree = new QTimer(this);
    timerthree->setInterval(80);

    timerCooldown = new QTimer(this);
    timerCooldown->setInterval(1000);

    displayTimer = new QTimer(this);
    displayTimer->setInterval(100);

    connect(displayTimer, SIGNAL(timeout()), this, SLOT(updateDisplay()));
    displayTimer->start();

}



void Player::keyPressEvent(QKeyEvent *event) {


    if (event->key() == Qt::Key_Left) {
        if (!timerthree->isActive() && !timer->isActive() && !event->isAutoRepeat()){
            setPixmap(QPixmap(":/images/images/WalkLeft1.png").scaled(60,60));
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
            connect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimLeft()));

            timertwo->start();
            timer->start();


        }

    }
    else if (event->key() == Qt::Key_Right) {
        if (!timerthree->isActive() && !timer->isActive() && !event->isAutoRepeat()){
            setPixmap(QPixmap(":/images/images/WalkRight1.png").scaled(60,60));
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitRight()));
            connect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimRight()));

            timertwo->start();
            timer->start();
        }
    }

    else if (event->key() == Qt::Key_Up) {
        if (!timerthree->isActive() && !timer->isActive() && !event->isAutoRepeat()){
            setPixmap(QPixmap(":/images/images/WalkUp1.png").scaled(60,60));
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitUp()));
            connect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimUp()));

            timertwo->start();
            timer->start();

        }
    }

    else if (event->key() == Qt::Key_Down) {
        if (!timerthree->isActive() && !timer->isActive() && !event->isAutoRepeat()){
            setPixmap(QPixmap(":/images/images/WalkDown1.png").scaled(60,60));
            connect(timer, SIGNAL(timeout()), this, SLOT(timerHitDown()));
            connect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimDown()));
            timertwo->start();
            timer->start();
        }
    }

    else if (event->key() == Qt::Key_Space) {
        if (!timerthree->isActive() && !timer->isActive() && player->getOrientation() == 1) {        //Up
            connect(timerthree, SIGNAL(timeout()), this, SLOT(timerSwordUp()));
            timerthree->start();
        }
        else if (!timerthree->isActive() && !timer->isActive() && player->getOrientation() == 2) {   //Right
            connect(timerthree, SIGNAL(timeout()), this, SLOT(timerSwordRight()));
            timerthree->start();
        }
        else if (!timerthree->isActive() && !timer->isActive() && player->getOrientation() == 3) {   //Down
            connect(timerthree, SIGNAL(timeout()), this, SLOT(timerSwordDown()));
            timerthree->start();
        }
        else if (!timerthree->isActive() && !timer->isActive() && player->getOrientation() == 4) {   //Left
            connect(timerthree, SIGNAL(timeout()), this, SLOT(timerSwordLeft()));
            timerthree->start();
        }
    }

    else if (event->key() == Qt::Key_Alt) {

        if (!timerCooldown->isActive()) {
            connect(timerCooldown, SIGNAL(timeout()), this, SLOT(timerCool()));
            Magic * magic = new Magic();
            if (player->getOrientation() == 1) {  //Up
             magic->setPos(x()+14,y()-8);
                magic->setDirection(1);
            } else if (player->getOrientation() ==2) {  //Right
                magic->setPos(x()+28,y()+20);
                magic->setDirection(2);
            } else if (player->getOrientation() ==3) {  //Down
                magic->setPos(x()+14,y()+30);
                magic->setDirection(3);
            } else if (player->getOrientation() ==4) {  //Left
                magic->setPos(x(),y()+20);
                magic->setDirection(4);
            }
            scene()->addItem(magic);
            timerCooldown->start();
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
    QList<QGraphicsItem *> colliding_items = collidingItems();
    player->setOrientation(1);
    for (int i = 0, n = colliding_items.size(); i<n; ++i) {

        if (typeid(*(colliding_items[i])) == typeid(Item)) {
            Item* item = dynamic_cast<Item*>(colliding_items[i]);
            if(item != nullptr){
                player->setItem(item->getItem());
                player->applyItem();
                //delete colliding_items[i];
                //scene()->removeItem(colliding_items[i]);
            }
        }

        else if (colliding_items[i] && typeid(*(colliding_items[i]))== typeid(Obstacle) || typeid(*(colliding_items[i]))== typeid(Enemy)) {

            Obstacle* obj = dynamic_cast<Obstacle*>(colliding_items[i]);
            Enemy* enemy = dynamic_cast<Enemy*>(colliding_items[i]);

            if(obj != nullptr){
                if(player->isBoardering(obj->getObstacle())){
                    disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
                    timer->stop();
                    disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimLeft()));
                    timertwo->stop();
                    player->incY();
                }
            }
            else if(enemy != nullptr){
                if(player->isBoardering(enemy->getEnemy())){
                    disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
                    timer->stop();
                    disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimLeft()));
                    timertwo->stop();
                    player->incY();
                }
            }
        }
    }
    player->decY();
    this->updatePos();
}

void Player::timerHitDown()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    player->setOrientation(3);
    for (int i = 0, n = colliding_items.size(); i<n; ++i) {

        if (typeid(*(colliding_items[i])) == typeid(Item)) {
            Item* item = dynamic_cast<Item*>(colliding_items[i]);
            if(item != nullptr){

                player->setItem(item->getItem());
                cout << player->getItem()->getProperty();
                player->applyItem();
                //delete colliding_items[i];
                scene()->removeItem(colliding_items[i]);
            }
        }


        else if (colliding_items[i] && typeid(*(colliding_items[i]))== typeid(Obstacle) || typeid(*(colliding_items[i]))== typeid(Enemy)) {

            Obstacle* obj = dynamic_cast<Obstacle*>(colliding_items[i]);
            Enemy* enemy = dynamic_cast<Enemy*>(colliding_items[i]);
            if(obj != nullptr){
                if(player->isBoardering(obj->getObstacle())){
                    disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
                    timer->stop();
                    disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimLeft()));
                    timertwo->stop();
                    player->decY();
                }
            }
            else if(enemy != nullptr){
                if(player->isBoardering(enemy->getEnemy())){
                    disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
                    timer->stop();
                    disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimLeft()));
                    timertwo->stop();
                    player->decY();
                }
            }
        }
    }
    player->incY();
    this->updatePos();

}

void Player::timerHitLeft()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    player->setOrientation(4);
    for (int i = 0, n = colliding_items.size(); i<n; ++i) {

        if (typeid(*(colliding_items[i])) == typeid(Item)) {
            Item* item = dynamic_cast<Item*>(colliding_items[i]);
            if(item != nullptr){
                player->setItem(item->getItem());
                player->applyItem();
                //delete colliding_items[i];
                //scene()->removeItem(colliding_items[i]);
            }
        }

        else if (colliding_items[i] && typeid(*(colliding_items[i]))== typeid(Obstacle) || typeid(*(colliding_items[i]))== typeid(Enemy)) {

            Obstacle* obj = dynamic_cast<Obstacle*>(colliding_items[i]);
            Enemy* enemy = dynamic_cast<Enemy*>(colliding_items[i]);

            if(obj != nullptr){
                if(player->isBoardering(obj->getObstacle())){
                    disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
                    timer->stop();
                    disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimLeft()));
                    timertwo->stop();
                    player->incX();
                }
            }
            else if(enemy != nullptr){
                if(player->isBoardering(enemy->getEnemy())){
                    disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
                    timer->stop();
                    disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimLeft()));
                    timertwo->stop();
                    player->incX();
                }
            }
        }
    }
    player->decX();
    this->updatePos();
}

void Player::timerHitRight()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    player->setOrientation(2);
    for (int i = 0, n = colliding_items.size(); i<n; ++i) {

        if (typeid(*(colliding_items[i])) == typeid(Item)) {
            Item* item = dynamic_cast<Item*>(colliding_items[i]);
            if(item != nullptr){
                player->setItem(item->getItem());
                player->applyItem();
                //delete colliding_items[i];
                //scene()->removeItem(colliding_items[i]);
            }
        }

        else if (colliding_items[i] && typeid(*(colliding_items[i])) == typeid(Obstacle) || typeid(*(colliding_items[i]))== typeid(Enemy)) {

            Obstacle* obj = dynamic_cast<Obstacle*>(colliding_items[i]);
            Enemy* enemy = dynamic_cast<Enemy*>(colliding_items[i]);

            if(obj != nullptr){
                if(player->isBoardering(obj->getObstacle())){
                    disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
                    timer->stop();
                    disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimLeft()));
                    timertwo->stop();
                    player->decX();
                }
            }
            else if(enemy != nullptr){
                if(player->isBoardering(enemy->getEnemy())){
                    disconnect(timer, SIGNAL(timeout()), this, SLOT(timerHitLeft()));
                    timer->stop();
                    disconnect(timertwo, SIGNAL(timeout()), this, SLOT(timerAnimLeft()));
                    timertwo->stop();
                    player->decX();
                }
            }
        }
    }
    player->incX();
    player->setDirections();
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

void Player::timerSwordUp()
{
    this->getPlayer()->attack(this->world);
    this->getScore()->updateScore();

    string str = string(":/images/images/SwordUp") + to_string(animation) + ".png";
    const char * c = str.c_str();
    setPixmap(QPixmap(c).scaled(60,60));
    if (animation == 6) {
        animation = 1;
        disconnect(timerthree, SIGNAL(timeout()), this, SLOT(timerSwordUp()));
        timerthree->stop();
        setPixmap(QPixmap(":/images/images/WalkUp1.png").scaled(60,60));
    } else {
        animation++;
    }
}

void Player::timerSwordDown()
{
    this->getPlayer()->attack(this->world);
    this->getScore()->updateScore();
    string str = string(":/images/images/SwordDown") + to_string(animation) + ".png";
    const char * c = str.c_str();
    setPixmap(QPixmap(c).scaled(60,60));
    if (animation == 6) {
        animation = 1;
        disconnect(timerthree, SIGNAL(timeout()), this, SLOT(timerSwordDown()));
        timerthree->stop();
        setPixmap(QPixmap(":/images/images/WalkDown1.png").scaled(60,60));
    } else {
        animation++;
    }
}

void Player::timerSwordLeft()
{
    this->getPlayer()->attack(this->world);
    this->getScore()->updateScore();
    string str = string(":/images/images/SwordLeft") + to_string(animation) + ".png";
    const char * c = str.c_str();
    setPixmap(QPixmap(c).scaled(60,60));
    if (animation == 6) {
        animation = 1;
        disconnect(timerthree, SIGNAL(timeout()), this, SLOT(timerSwordLeft()));
        timerthree->stop();
        setPixmap(QPixmap(":/images/images/WalkLeft1.png").scaled(60,60));
    } else {
        animation++;
    }
}

void Player::timerSwordRight()
{
    this->getPlayer()->attack(this->world);
    this->getScore()->updateScore();
    string str = string(":/images/images/SwordRight") + to_string(animation) + ".png";
    const char * c = str.c_str();
    setPixmap(QPixmap(c).scaled(60,60));
    if (animation == 6) {
        animation = 1;
        disconnect(timerthree, SIGNAL(timeout()), this, SLOT(timerSwordRight()));
        timerthree->stop();
        setPixmap(QPixmap(":/images/images/WalkRight1.png").scaled(60,60));
    } else {
        animation++;
    }
}

void Player::timerCool()
{
    if (mag == false) {
        mag = true;
    } else {
        disconnect(timerCooldown, SIGNAL(timeout()), this, SLOT(timerCool()));
        timerCooldown->stop();
        mag = false;
    }
}

void Player::updateDisplay()
{
    health->getHealth()->setHealth(player->getHealth());
    lives->getLives()->setLives(player->getLives()->getLives());
    health->updateHealth();
    lives->updateLives();
}
