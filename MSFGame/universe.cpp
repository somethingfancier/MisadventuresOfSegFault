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
    activeWorld->setName(":/images/images/World1.png");
    activeWorld->setUpWId(2);
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


    //Second world information

}

void Universe::createSecondWorld()
{
    World* worldTwo = new World();

    worldTwo->setId(2);
    worldTwo->setDownWId(1);
    worldTwo->setName(":/images/images/World2.png");

    WorldObstacle* obs1 = new WorldObstacle();
    WorldObstacle* obs2 = new WorldObstacle();
    WorldObstacle* obs3 = new WorldObstacle();
    WorldObstacle* obs4 = new WorldObstacle();
    WorldObstacle* obs5 = new WorldObstacle();
    WorldObstacle* obs6 = new WorldObstacle();
    WorldObstacle* obs7 = new WorldObstacle();
    WorldObstacle* obs8 = new WorldObstacle();
    WorldObstacle* obs9 = new WorldObstacle();
    WorldObstacle* obs10 = new WorldObstacle();
    WorldObstacle* obs11 = new WorldObstacle();
    WorldObstacle* obs12 = new WorldObstacle();
    WorldObstacle* obs13 = new WorldObstacle();
    WorldObstacle* obs14 = new WorldObstacle();
    WorldObstacle* obs15 = new WorldObstacle();
    WorldObstacle* obs16 = new WorldObstacle();
    WorldObstacle* obs17 = new WorldObstacle();
    WorldObstacle* obs18 = new WorldObstacle();
    WorldObstacle* obs19 = new WorldObstacle();
    WorldObstacle* obs20 = new WorldObstacle();
    WorldObstacle* obs21 = new WorldObstacle();
    WorldObstacle* obs22 = new WorldObstacle();
    WorldObstacle* obs23 = new WorldObstacle();
    WorldObstacle* obs24 = new WorldObstacle();
    WorldObstacle* obs25 = new WorldObstacle();
    WorldObstacle* obs26 = new WorldObstacle();
    WorldObstacle* obs27 = new WorldObstacle();
    WorldObstacle* obs28 = new WorldObstacle();
    WorldObstacle* obs29 = new WorldObstacle();
    WorldObstacle* obs30 = new WorldObstacle();
    WorldObstacle* obs31 = new WorldObstacle();

    obs1->setX(0);
    obs1->setY(632);
    obs1->setWidth(410);
    obs1->setHeight(88);

    obs2->setX(0);
    obs2->setY(576);
    obs2->setWidth(124);
    obs2->setHeight(52);

    obs3->setX(0);
    obs3->setY(247);
    obs3->setWidth(94);
    obs3->setHeight(321);

    obs4->setX(101);
    obs4->setY(233);
    obs4->setWidth(168);
    obs4->setHeight(147);

    obs5->setX(0);
    obs5->setY(0);
    obs5->setWidth(110);
    obs5->setHeight(210);

    obs6->setX(128);
    obs6->setY(0);
    obs6->setWidth(385);
    obs6->setHeight(106);

    obs7->setX(405);
    obs7->setY(108);
    obs7->setWidth(221);
    obs7->setHeight(56);

    obs8->setX(631);
    obs8->setY(90);
    obs8->setWidth(58);
    obs8->setHeight(54);

    obs9->setX(566);
    obs9->setY(0);
    obs9->setWidth(148);
    obs9->setHeight(86);

    obs10->setX(726);
    obs10->setY(49);
    obs10->setWidth(65);
    obs10->setHeight(21);

    obs11->setX(720);
    obs11->setY(0);
    obs11->setWidth(186);
    obs11->setHeight(43);

    obs12->setX(931);
    obs12->setY(0);
    obs12->setWidth(172);
    obs12->setHeight(39);

    obs13->setX(1118);
    obs13->setY(0);
    obs13->setWidth(72);
    obs13->setHeight(70);

    obs14->setX(1196);
    obs14->setY(0);
    obs14->setWidth(84);
    obs14->setHeight(417);

    obs15->setX(1222);
    obs15->setY(425);
    obs15->setWidth(58);
    obs15->setHeight(295);

    obs16->setX(887);
    obs16->setY(653);
    obs16->setWidth(323);
    obs16->setHeight(67);

    obs17->setX(711);
    obs17->setY(480);
    obs17->setWidth(167);
    obs17->setHeight(240);

    obs18->setX(882);
    obs18->setY(450);
    obs18->setWidth(216);
    obs18->setHeight(135);

    obs19->setX(647);
    obs19->setY(508);
    obs19->setWidth(59);
    obs19->setHeight(58);

    obs20->setX(567);
    obs20->setY(416);
    obs20->setWidth(135);
    obs20->setHeight(90);

    obs21->setX(538);
    obs21->setY(633);
    obs21->setWidth(45);
    obs21->setHeight(87);

    obs22->setX(413);
    obs22->setY(553);
    obs22->setWidth(121);
    obs22->setHeight(167);

    obs23->setX(400);
    obs23->setY(398);
    obs23->setWidth(161);
    obs23->setHeight(90);

    obs24->setX(298);
    obs24->setY(419);
    obs24->setWidth(86);
    obs24->setHeight(91);

    obs25->setX(198);
    obs25->setY(452);
    obs25->setWidth(91);
    obs25->setHeight(96);

    obs26->setX(286);
    obs26->setY(246);
    obs26->setWidth(173);
    obs26->setHeight(101);

    obs27->setX(482);
    obs27->setY(243);
    obs27->setWidth(253);
    obs27->setHeight(81);

    obs28->setX(756);
    obs28->setY(154);
    obs28->setWidth(72);
    obs28->setHeight(155);

    obs29->setX(834);
    obs29->setY(94);
    obs29->setWidth(114);
    obs29->setHeight(121);

    obs30->setX(834);
    obs30->setY(216);
    obs30->setWidth(50);
    obs30->setHeight(44);

    obs31->setX(957);
    obs31->setY(113);
    obs31->setWidth(119);
    obs31->setHeight(194);

    worldTwo->addObstacle(obs1);
    worldTwo->addObstacle(obs2);
    worldTwo->addObstacle(obs3);
    worldTwo->addObstacle(obs4);
    worldTwo->addObstacle(obs5);
    worldTwo->addObstacle(obs6);
    worldTwo->addObstacle(obs7);
    worldTwo->addObstacle(obs8);
    worldTwo->addObstacle(obs9);
    worldTwo->addObstacle(obs10);
    worldTwo->addObstacle(obs11);
    worldTwo->addObstacle(obs12);
    worldTwo->addObstacle(obs13);
    worldTwo->addObstacle(obs14);
    worldTwo->addObstacle(obs15);
    worldTwo->addObstacle(obs16);
    worldTwo->addObstacle(obs17);
    worldTwo->addObstacle(obs18);
    worldTwo->addObstacle(obs19);
    worldTwo->addObstacle(obs20);
    worldTwo->addObstacle(obs21);
    worldTwo->addObstacle(obs22);
    worldTwo->addObstacle(obs23);
    worldTwo->addObstacle(obs24);
    worldTwo->addObstacle(obs25);
    worldTwo->addObstacle(obs26);
    worldTwo->addObstacle(obs27);
    worldTwo->addObstacle(obs28);
    worldTwo->addObstacle(obs29);
    worldTwo->addObstacle(obs30);
    worldTwo->addObstacle(obs31);

    addWorld(worldTwo);
}


