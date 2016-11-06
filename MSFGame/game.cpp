#include "game.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>
#include <obstacle.h>
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

    // create health
    Health* health = new Health();
    player->setHealth(health);
    player->getPlayer()->setHealth(health->getHealth());

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
    for (unsigned i=0; i<world->getCharacters().size(); i++) {
        WorldCharacter* enemyData = world->getCharacters().at(i);
        Enemy* newEnemy = new Enemy();
        WorldEnemy* disEnemy = new WorldEnemy();
        disEnemy = static_cast<WorldEnemy*>(enemyData);
        if (disEnemy) {
            newEnemy->setEnemy(disEnemy);
            newEnemy->setPlayer(player->getPlayer());
            //newEnemy->setTimer(player->getTimer());
            newEnemy->updatePos();
            newEnemy->getEnemy()->setAwareness(3);
        }
        scene->addItem(newEnemy);
    }

    for (unsigned i=0; i<world->getCharacters().size(); i++) {
        WorldCharacter* npcData = world->getCharacters().at(i);
        NPC* newNPC = new NPC();
        WorldNPC* disNPC = new WorldNPC();
        disNPC = static_cast<WorldNPC*>(npcData);
        if (disNPC) {
            newNPC->setPos(npcData->getX(),npcData->getY());
            string str = string(":/images/images/") + npcData->getName() + ".png";
            const char * c = str.c_str();
            newNPC->setPixmap(QPixmap(c).scaled(34, 40));
        }
        scene->addItem(newNPC);
    }


    //Add Obstacles
    for (unsigned i=0; i<world->getObstacles().size(); i++) {
        WorldObstacle* obstacle = new WorldObstacle;
        obstacle = world->getObstacles().at(i);
        Obstacle* obj = new Obstacle();
        obj->setRect(obstacle->getX(),obstacle->getY(),obstacle->getWidth(),obstacle->getHeight());
        obj->setObstacle(obstacle);
        obj->setPen(Qt::NoPen);
        scene->addItem(obj);
    }

    //Add Items
    for (unsigned i=0; i<world->getItems().size(); i++) {
        WorldItem* item = world->getItems().at(i);
        Item* newItem = new Item();
        newItem->setPos(item->getX(), item->getY());
        newItem->setProperty(item->getProperty());
        string str = string(":/images/images/") + item->getProperty() + ".png";
        const char * c = str.c_str();
        newItem->setPixmap(QPixmap(c).scaled(30, 30));

        scene->addItem(newItem);
    }

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
        this->initialize(currentWRight);
    }
}


void closeEvent(QCloseEvent *event) {
    if (event->Close) {
        Universe::instance().Save();
    }

}
