#include <iostream>
#include <QDebug>
#include "universe.h"

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

World* Universe::getWorld(int id)
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
    World* world1= new World();
    player = new WorldPlayer();
    world1->setId(1);
    world1->setName(":/images/images/World1.png");
    world1->setUpWId(2);
    world1->setDownWId(1);
    world1->setLeftWId(6);
    world1->setRightWId(1);

    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldNPC* goodGuy = new WorldNPC();

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

    WorldItem* itemOne = new WorldItem();
    itemOne->setProperty("heart");
    itemOne->setCoordinates(1020, 230);

    world1->addItem(itemOne);

    badGuyOne->setX(200);
    badGuyOne->setY(200);

    badGuyTwo->setX(500);
    badGuyTwo->setY(500);

    goodGuy->setX(1020);
    goodGuy->setY(180);
    goodGuy->setName("npc1");

    world1->addCharacter(badGuyOne);
    world1->addCharacter(badGuyTwo);
    world1->addCharacter(goodGuy);

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

    world1->addObstacle(obsOne);
    world1->addObstacle(obsTwo);
    world1->addObstacle(obsThree);
    world1->addObstacle(obsFour);
    world1->addObstacle(obsFive);
    world1->addObstacle(obsSix);
    world1->addObstacle(obsSeven);
    world1->addObstacle(obsEight);
    world1->addObstacle(obsNine);
    world1->addObstacle(obsTen);
    world1->addObstacle(obsEle);
    world1->addObstacle(obsTwe);
    world1->addObstacle(obsThir);
    world1->addObstacle(obsFourt);



    addWorld(world1);


}

void Universe::createSecondWorld() {

    World* world2 = new World();

    world2->setId(2);
    world2->setDownWId(1);
    world2->setLeftWId(5);
    world2->setRightWId(2);
    world2->setUpWId(3);
    world2->setName(":/images/images/World2.png");

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

    obs1->setX(0);
    obs1->setY(0);
    obs1->setWidth(252);
    obs1->setHeight(40);

    obs2->setX(88);
    obs2->setY(44);
    obs2->setWidth(49);
    obs2->setHeight(43);

    obs3->setX(260);
    obs3->setY(0);
    obs3->setWidth(42);
    obs3->setHeight(255);

    obs4->setX(308);
    obs4->setY(0);
    obs4->setWidth(159);
    obs4->setHeight(171);

    obs5->setX(308);
    obs5->setY(174);
    obs5->setWidth(85);
    obs5->setHeight(75);

    obs6->setX(471);
    obs6->setY(0);
    obs6->setWidth(103);
    obs6->setHeight(52);

    obs7->setX(746);
    obs7->setY(0);
    obs7->setWidth(499);
    obs7->setHeight(50);

    obs8->setX(913);
    obs8->setY(53);
    obs8->setWidth(76);
    obs8->setHeight(33);

    obs9->setX(1136);
    obs9->setY(52);
    obs9->setWidth(88);
    obs9->setHeight(43);

    obs10->setX(1252);
    obs10->setY(0);
    obs10->setWidth(28);
    obs10->setHeight(323);

    obs11->setX(878);
    obs11->setY(327);
    obs11->setWidth(402);
    obs11->setHeight(76);

    obs12->setX(761);
    obs12->setY(329);
    obs12->setWidth(115);
    obs12->setHeight(109);

    obs13->setX(450);
    obs13->setY(439);
    obs13->setWidth(426);
    obs13->setHeight(77);

    obs14->setX(0);
    obs14->setY(435);
    obs14->setWidth(396);
    obs14->setHeight(82);

    obs15->setX(0);
    obs15->setY(258);
    obs15->setWidth(347);
    obs15->setHeight(169);

    obs16->setX(0);
    obs16->setY(519);
    obs16->setWidth(87);
    obs16->setHeight(32);

    obs17->setX(0);
    obs17->setY(553);
    obs17->setWidth(145);
    obs17->setHeight(112);

    obs18->setX(0);
    obs18->setY(668);
    obs18->setWidth(184);
    obs18->setHeight(52);

    obs19->setX(254);
    obs19->setY(519);
    obs19->setWidth(105);
    obs19->setHeight(27);

    obs20->setX(200);
    obs20->setY(688);
    obs20->setWidth(198);
    obs20->setHeight(32);

    obs21->setX(402);
    obs21->setY(663);
    obs21->setWidth(99);
    obs21->setHeight(57);

    obs22->setX(507);
    obs22->setY(695);
    obs22->setWidth(95);
    obs22->setHeight(25);

    obs23->setX(727);
    obs23->setY(690);
    obs23->setWidth(128);
    obs23->setHeight(30);

    obs24->setX(858);
    obs24->setY(628);
    obs24->setWidth(90);
    obs24->setHeight(92);

    obs25->setX(952);
    obs25->setY(680);
    obs25->setWidth(108);
    obs25->setHeight(40);

    obs26->setX(1063);
    obs26->setY(617);
    obs26->setWidth(62);
    obs26->setHeight(100);

    obs27->setX(1128);
    obs27->setY(500);
    obs27->setWidth(40);
    obs27->setHeight(217);

    obs28->setX(1170);
    obs28->setY(416);
    obs28->setWidth(110);
    obs28->setHeight(304);

    world2->addObstacle(obs1);
    world2->addObstacle(obs2);
    world2->addObstacle(obs3);
    world2->addObstacle(obs4);
    world2->addObstacle(obs5);
    world2->addObstacle(obs6);
    world2->addObstacle(obs7);
    world2->addObstacle(obs8);
    world2->addObstacle(obs9);
    world2->addObstacle(obs10);
    world2->addObstacle(obs11);
    world2->addObstacle(obs12);
    world2->addObstacle(obs13);
    world2->addObstacle(obs14);
    world2->addObstacle(obs15);
    world2->addObstacle(obs16);
    world2->addObstacle(obs17);
    world2->addObstacle(obs18);
    world2->addObstacle(obs19);
    world2->addObstacle(obs20);
    world2->addObstacle(obs21);
    world2->addObstacle(obs22);
    world2->addObstacle(obs23);
    world2->addObstacle(obs24);
    world2->addObstacle(obs25);
    world2->addObstacle(obs26);
    world2->addObstacle(obs27);
    world2->addObstacle(obs28);

    addWorld(world2);

}


void Universe::createThirdWorld()
{
    World* world3 = new World();

    world3->setId(3);
    world3->setDownWId(2);
    world3->setLeftWId(4);
    world3->setRightWId(3);
    world3->setUpWId(3);
    world3->setName(":/images/images/World3.png");


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
    WorldObstacle* obs32 = new WorldObstacle();

    obs1->setX(0);
    obs1->setY(632);
    obs1->setWidth(410);
    obs1->setHeight(88);

    obs2->setX(0);
    obs2->setY(576);
    obs2->setWidth(124);
    obs2->setHeight(52);

    obs3->setX(0);
    obs3->setY(230);
    obs3->setWidth(91);
    obs3->setHeight(247);

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
    obs22->setY(633);
    obs22->setWidth(121);
    obs22->setHeight(40);

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

    obs32->setX(711);
    obs32->setY(591);
    obs32->setWidth(126);
    obs32->setHeight(84);

    world3->addObstacle(obs1);
    world3->addObstacle(obs2);
    world3->addObstacle(obs3);
    world3->addObstacle(obs4);
    world3->addObstacle(obs5);
    world3->addObstacle(obs6);
    world3->addObstacle(obs7);
    world3->addObstacle(obs8);
    world3->addObstacle(obs9);
    world3->addObstacle(obs10);
    world3->addObstacle(obs11);
    world3->addObstacle(obs12);
    world3->addObstacle(obs13);
    world3->addObstacle(obs14);
    world3->addObstacle(obs15);
    world3->addObstacle(obs16);
    world3->addObstacle(obs17);
    world3->addObstacle(obs18);
    world3->addObstacle(obs19);
    world3->addObstacle(obs20);
    world3->addObstacle(obs21);
    world3->addObstacle(obs22);
    world3->addObstacle(obs23);
    world3->addObstacle(obs24);
    world3->addObstacle(obs25);
    world3->addObstacle(obs26);
    world3->addObstacle(obs27);
    world3->addObstacle(obs28);
    world3->addObstacle(obs29);
    world3->addObstacle(obs30);
    world3->addObstacle(obs31);
    world3->addObstacle(obs32);

    addWorld(world3);
}

void Universe::createFourthWorld() {

    World* world4 = new World();

    world4->setId(4);
    world4->setDownWId(5);
    world4->setLeftWId(9);
    world4->setRightWId(3);
    world4->setUpWId(4);
    //world4->setName(":/images/images/World4.png");

    addWorld(world4);

}

void Universe::createFifthWorld() {

    World* world5 = new World();

    world5->setId(5);
    world5->setDownWId(6);
    world5->setLeftWId(8);
    world5->setRightWId(2);
    world5->setUpWId(4);
    world5->setName(":/images/images/World5.png");

    addWorld(world5);

}

void Universe::createSixthWorld() {

    World* world6 = new World();

    world6->setId(6);
    world6->setDownWId(6);
    world6->setLeftWId(6);
    world6->setRightWId(1);
    world6->setUpWId(5);
    world6->setName(":/images/images/World6.png");

    addWorld(world6);

}

void Universe::createEighthWorld() {

    World* world8 = new World();

    world8->setId(8);
    world8->setDownWId(8);
    world8->setLeftWId(8);
    world8->setRightWId(5);
    world8->setUpWId(8);
    world8->setName(":/images/images/World8.png");

    addWorld(world8);

}

void Universe::Save()
{
    cout << player->getData();
    for (int i = 0; i < Universe::instance().getWorld(1)->getCharacters().size(); i++) {
        WorldCharacter* enemy1 = Universe::instance().getWorld(1)->getCharacters().at(i);
        cout << enemy1->getData();
    }
    for (int i = 0; i < Universe::instance().getWorld(1)->getItems().size(); i++) {
        WorldItem* item1 = Universe::instance().getWorld(1)->getItems().at(i);
        cout << item1->getData();
    }
}


