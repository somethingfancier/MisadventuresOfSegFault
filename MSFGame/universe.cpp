#include <iostream>
#include <QDebug>
#include "universe.h"
#include "world.h"
#include "worldobject.h"
#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"
#include "worldnpc.h"
#include "worlditem.h"
#include "worldobstacle.h"

using namespace std;

//Singleton Implementation
Universe* Universe::instance_ = NULL;

Universe& Universe::instance()
{
    if(instance_ == NULL){
        instance_ = new Universe();
        instance_->numWorlds = 0;
        WorldPlayer* newPlayer = new WorldPlayer();
        instance_->setPlayer(newPlayer);
    }
    return *instance_;
}

World *Universe::getWorld(int id)
{
    for (unsigned i=0; i<worlds.size(); i++) {
        if (worlds.at(i)->getId() == id) {
            return worlds.at(i);
        }
    }
    return NULL;
}

//Adder for worlds
void Universe::addWorld(World* newWorld)
{
    worlds.push_back(newWorld);
    numWorlds++;
}

//Set up some objects for the first world
void Universe::createFirstWorld()
{
    activeWorld = new World();
    player = new WorldPlayer();
    activeWorld->setId(1);
    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldObstacle* obsOne = new WorldObstacle();
    WorldObstacle* obsTwo = new WorldObstacle();
    WorldObstacle* obsThree = new WorldObstacle();
    WorldObstacle* obsFour = new WorldObstacle();
    WorldObstacle* obsFive = new WorldObstacle();
    WorldObstacle* obsSix = new WorldObstacle();
    WorldObstacle* obsSeven = new WorldObstacle();
    WorldObstacle* obsEight = new WorldObstacle();
    WorldObstacle* obsNine = new WorldObstacle();
    WorldObstacle* obsTen = new WorldObstacle();
    WorldObstacle* obsEle = new WorldObstacle();
    WorldObstacle* obsTwe = new WorldObstacle();
    WorldObstacle* obsThir = new WorldObstacle();
    WorldObstacle* obsFourt = new WorldObstacle();


    badGuyOne->setX(200);
    badGuyOne->setY(200);

    badGuyTwo->setX(500);
    badGuyTwo->setY(500);

    activeWorld->addCharacter(badGuyOne);
    activeWorld->addCharacter(badGuyTwo);

    obsOne->setX(0);
    obsOne->setY(0);
    obsOne->setWidth(609);
    obsOne->setHeight(136);

    obsTwo->setX(0);
    obsTwo->setY(136);
    obsTwo->setWidth(83);
    obsTwo->setHeight(135);

    obsThree->setX(0);
    obsThree->setY(271);
    obsThree->setWidth(20);
    obsThree->setHeight(449);

    obsFour->setX(0);
    obsFour->setY(690);
    obsFour->setWidth(1280);
    obsFour->setHeight(30);

    obsFive->setX(1250);
    obsFive->setY(210);
    obsFive->setWidth(30);
    obsFive->setHeight(510);

    obsSix->setX(710);
    obsSix->setY(0);
    obsSix->setWidth(570);
    obsSix->setHeight(140);

    obsSeven->setX(750);
    obsSeven->setY(140);
    obsSeven->setWidth(158);
    obsSeven->setHeight(43);

    obsEight->setX(1180);
    obsEight->setY(140);
    obsEight->setWidth(100);
    obsEight->setHeight(113);

    obsNine->setX(859);
    obsNine->setY(221);
    obsNine->setWidth(58);
    obsNine->setHeight(70);

    obsTen->setX(821);
    obsTen->setY(333);
    obsTen->setWidth(73);
    obsTen->setHeight(112);

    obsEle->setX(913);
    obsEle->setY(436);
    obsEle->setWidth(60);
    obsEle->setHeight(107);

    obsTwe->setX(939);
    obsTwe->setY(354);
    obsTwe->setWidth(33);
    obsTwe->setHeight(34);

    obsThir->setX(1141);
    obsThir->setY(569);
    obsThir->setWidth(79);
    obsThir->setHeight(70);

    obsFourt->setX(156);
    obsFourt->setY(364);
    obsFourt->setWidth(84);
    obsFourt->setHeight(108);

    activeWorld->addObstacle(obsOne);
    activeWorld->addObstacle(obsTwo);
    activeWorld->addObstacle(obsThree);
    activeWorld->addObstacle(obsFour);
    activeWorld->addObstacle(obsFive);
    activeWorld->addObstacle(obsSix);
    activeWorld->addObstacle(obsSeven);
    activeWorld->addObstacle(obsEight);
    activeWorld->addObstacle(obsNine);
    activeWorld->addObstacle(obsTen);
    activeWorld->addObstacle(obsEle);
    activeWorld->addObstacle(obsTwe);
    activeWorld->addObstacle(obsThir);
    activeWorld->addObstacle(obsFourt);



    addWorld(activeWorld);

}
