#include "game.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>
#include <obstacle.h>
#include <iostream>
#include <QCloseEvent>

Game::Game(QWidget *parent)
{
    Universe::instance().createFirstWorld();
    Universe::instance().createSecondWorld();
    Universe::instance().createThirdWorld();
    Universe::instance().createFourthWorld();
    Universe::instance().createFifthWorld();
    Universe::instance().createSixthWorld();
    Universe::instance().createEighthWorld();
    Universe::instance().createNinthWorld();
    Universe::instance().createTenthWorld();
    Universe::instance().createEleventhWorld();
    Universe::instance().createTwelthWorld();
    Universe::instance().createThirteenthWorld();
    Universe::instance().createFourteenthWorld();
    Universe::instance().getPlayer()->setCoordinates(100,200);

    player = new Player();
    player->setPlayer(Universe::instance().getPlayer());
    player->updatePos();
    player->setPixmap(QPixmap(":/images/images/WalkDown1.png").scaled(60,60));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setWorld(Universe::instance().getWorld(1));

    // create score
    Score* score = new Score();
    player->setScore(score);
    player->getPlayer()->setScore(score->getScore());

    // create lives
    Lives* lives = new Lives();
    player->setLives(lives);
    player->getPlayer()->setLives(lives->getLives());

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);

    this->initialize(1);

    timer = new QTimer(this);
    timer->setInterval(500);
    connect(timer, SIGNAL(timeout()), this, SLOT(newWorld()));
    timer->start();

    show();
}

void Game::initialize(int id)
{
    this->player->getPlayer()->setCurrentWorld(id);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage()));
    scene->addItem(this->getPlayer()->getScore());
    scene->addItem(this->getPlayer()->getLives());
    scene->addItem(this->getPlayer()->getHealth());

    setScene(scene);

    World* world = Universe::instance().getWorld(id);

    //set the world ids that are connected
    currentWUp = world->getUpWId();
    currentWDown = world->getDownWId();
    currentWLeft = world->getLeftWId();
    currentWRight = world->getRightId();
    setBackgroundBrush(QBrush(QImage(world->getName())));

    if (id == 9) {
        for (unsigned i=0; i<world->getCharacters().size(); i++) {
            Boss* newBoss = new Boss();
            WorldEnemy* disEnemy = new WorldEnemy();
            disEnemy = dynamic_cast<WorldEnemy*>(world->getCharacters().at(i));
            if (disEnemy != nullptr) {
                disEnemy->randDir();
                newBoss->setEnemy(disEnemy);
                //newEnemy->setTimer(player->getTimer());
                newBoss->updatePos();
                newBoss->getEnemy()->setAwareness(3);
                scene->addItem(newBoss);
            }
        }
    } else {
        for (unsigned i=0; i<world->getCharacters().size(); i++) {
            Enemy* newEnemy = new Enemy();
            WorldEnemy* disEnemy = new WorldEnemy();
            disEnemy = dynamic_cast<WorldEnemy*>(world->getCharacters().at(i));
            if (disEnemy != nullptr) {
                disEnemy->randDir();
                newEnemy->setEnemy(disEnemy);
                //newEnemy->setTimer(player->getTimer());
                newEnemy->updatePos();
                newEnemy->getEnemy()->setAwareness(3);
                string img = disEnemy->getName() + ".png";
                if(disEnemy->isDead()){
                    newEnemy->setDead();
                    img = ":/images/images/SlimeBurst3.png";
                }
                const char* cImg = img.c_str();
                newEnemy->setPixmap(QPixmap(cImg).scaled(60,60));
                scene->addItem(newEnemy);
            }
        }
    }

        for (unsigned i=0; i<world->getCharacters().size(); i++) {
            NPC* newNPC = new NPC();
            WorldNPC* disNPC = new WorldNPC();
            disNPC = dynamic_cast<WorldNPC*>(world->getCharacters().at(i));
            if (disNPC != nullptr) {
                newNPC->setAdvice(disNPC->getAdvice());
                newNPC->setName(disNPC->getTitle());
                newNPC->setPos(disNPC->getX(),disNPC->getY());
                newNPC->setNPC(disNPC);
                disNPC->setHeight(40);
                disNPC->setWidth(34);
                string str = string(":/images/images/") + disNPC->getName() + ".png";
                const char * c = str.c_str();
                newNPC->setPixmap(QPixmap(c).scaled(34, 40));
                scene->addItem(newNPC);
            }
        }


        //Add Obstacles
        for (unsigned i=0; i<world->getObstacles().size(); i++) {
            if (player->getPlayer()->getKey() == true && player->getPlayer()->getKey2() == true && player->getPlayer()->getKey3() == true && i == 0 && id == 4) {
                //Do nothing
            } else {
                WorldObstacle* obstacle = new WorldObstacle;
                obstacle = world->getObstacles().at(i);
                Obstacle* obj = new Obstacle();
                obj->setRect(obstacle->getX(),obstacle->getY(),obstacle->getWidth(),obstacle->getHeight());
                obj->setObstacle(obstacle);
                obj->setPen(Qt::NoPen);
                scene->addItem(obj);
           }
        }

        //Add Items
        for (unsigned i=0; i<world->getItems().size(); i++) {
            WorldItem* item = world->getItems().at(i);
            Item* newItem = new Item();
            newItem->setPos(item->getX(), item->getY());
            newItem->setItem(item);

            string str = string(":/images/images/") + item->getProperty() + ".png";
            const char * c = str.c_str();
            newItem->setPixmap(QPixmap(c).scaled(30, 30));

            scene->addItem(newItem);
        }
    //}

    Universe::instance().getWorld(id)->setInit();
    scene->addItem(player);

}

void Game::newWorld()
{
    if (player->getPlayer()->getY() < 0){
        delete player;
        Universe::instance().getPlayer()->setCoordinates(player->getPlayer()->getX(),680);
        player = new Player(); //
        player->setPlayer(Universe::instance().getPlayer());
        player->updatePos();
        player->setPixmap(QPixmap(":/images/images/WalkUp1.png").scaled(60,60));
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();
        player->setWorld(Universe::instance().getWorld(currentWUp));
        scene->deleteLater();
        this->initialize(currentWUp);

    } else if (player->getPlayer()->getY() > 720) {
        delete player;
        Universe::instance().getPlayer()->setCoordinates(player->getPlayer()->getX(),40);
        player = new Player(); //
        player->setPlayer(Universe::instance().getPlayer());
        player->updatePos();
        player->setPixmap(QPixmap(":/images/images/WalkDown1.png").scaled(60,60));
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();
        player->setWorld(Universe::instance().getWorld(currentWDown));
        scene->deleteLater();
        this->initialize(currentWDown);

    } else if (player->getPlayer()->getX() < 0) {
        delete player;
        Universe::instance().getPlayer()->setCoordinates(1240,player->getPlayer()->getY());
        player = new Player(); //
        player->setPlayer(Universe::instance().getPlayer());
        player->updatePos();
        player->setPixmap(QPixmap(":/images/images/WalkLeft1.png").scaled(60,60));
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();
        player->setWorld(Universe::instance().getWorld(currentWLeft));
        scene->deleteLater();
        this->initialize(currentWLeft);

    }else if (player->getPlayer()->getX() > 1280) {
        delete player;
        Universe::instance().getPlayer()->setCoordinates(40,player->getPlayer()->getY());
        player = new Player(); //
        player->setPlayer(Universe::instance().getPlayer());
        player->updatePos();
        player->setPixmap(QPixmap(":/images/images/WalkRight1.png").scaled(60,60));
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();
        player->setWorld(Universe::instance().getWorld(currentWRight));
        scene->deleteLater();
        this->initialize(currentWRight);
    }
}
