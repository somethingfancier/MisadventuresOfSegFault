#include <iostream>
#include <QDebug>
#include "universe.h"
#include <sstream>

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
    world1->setId(1);
    world1->setName(":/images/images/World1.png");
    world1->setUpWId(2);
    world1->setDownWId(1);
    world1->setLeftWId(6);
    world1->setRightWId(1);

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

    WorldItem* itemOne = new WorldItem();
    itemOne->setProperty("heart");
    itemOne->setCoordinates(1020, 230);



    world1->addItem(itemOne);


    badGuyOne->setX(200);
    badGuyOne->setY(200);

    badGuyTwo->setX(500);
    badGuyTwo->setY(500);

    WorldNPC* goodGuy = new WorldNPC();

    goodGuy->setX(1020);
    goodGuy->setY(180);
    goodGuy->setName("npc1");
    goodGuy->setAdvice("This heart will give you an extra life.\n I also heard there is a book that lets you shoot fireballs");
    goodGuy->setTitle("Sir Blue-a-Lot");
    world1->addCharacter(goodGuy);


    world1->addCharacter(badGuyOne);
    world1->addCharacter(badGuyTwo);

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

    instance().addWorld(world1);
}

void Universe::createSecondWorld() {

    World* world2 = new World();

    world2->setId(2);
    world2->setDownWId(1);
    world2->setLeftWId(5);
    world2->setRightWId(2);
    world2->setUpWId(3);
    world2->setName(":/images/images/World2.png");

    WorldNPC* goodGuy = new WorldNPC();

    goodGuy->setX(100);
    goodGuy->setY(150);
    goodGuy->setName("npc6");
    goodGuy->setAdvice("Praise the Sun!!!");
    goodGuy->setTitle("Homeless Lake Man");
    world2->addCharacter(goodGuy);

    WorldItem* itemOne = new WorldItem();
    itemOne->setProperty("health");
    itemOne->setCoordinates(1020, 230);

    world2->addItem(itemOne);

    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldEnemy* badGuyThree = new WorldEnemy();

    badGuyOne->setX(921);
    badGuyOne->setY(446);

    badGuyTwo->setX(1130);
    badGuyTwo->setY(203);

    badGuyThree->setX(541);
    badGuyThree->setY(150);

    world2->addCharacter(badGuyOne);
    world2->addCharacter(badGuyTwo);
    world2->addCharacter(badGuyThree);

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
    obs22->setY(715);
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

    instance().addWorld(world2);

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

    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();

    badGuyOne->setX(1147);
    badGuyOne->setY(578);

    badGuyTwo->setX(901);
    badGuyTwo->setY(285);

    world3->addCharacter(badGuyOne);
    world3->addCharacter(badGuyTwo);


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

    WorldItem* itemO = new WorldItem();
    itemO->setProperty("book");
    itemO->setCoordinates(180, 180);

    world3->addItem(itemO);

    WorldItem* itemOne = new WorldItem();
    itemOne->setProperty("heart");
    itemOne->setCoordinates(928, 628);

    world3->addItem(itemOne);

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

    instance().addWorld(world3);
}

void Universe::createFourthWorld() {

    World* world4 = new World();

    world4->setId(4);
    world4->setDownWId(5);
    world4->setLeftWId(9);
    world4->setRightWId(3);
    world4->setUpWId(10);
    world4->setName(":/images/images/World4.png");

    WorldItem* itemOne = new WorldItem();
    itemOne->setProperty("health");
    itemOne->setCoordinates(1090, 230);

    world4->addItem(itemOne);

    WorldNPC* goodGuy = new WorldNPC();

    goodGuy->setX(688);
    goodGuy->setY(67);
    goodGuy->setName("npc2");
    goodGuy->setAdvice("There is something evil lurking in the mountain, but the entrance is protected by \nsome kind of invisible door.  I heard this old man say something about \n three keys he had lost.  Maybe you can unlock the door with those?");
    goodGuy->setTitle("Wanderer");
    world4->addCharacter(goodGuy);

    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldEnemy* badGuyThree = new WorldEnemy();
    WorldEnemy* badGuyFour = new WorldEnemy();

    badGuyOne->setX(946);
    badGuyOne->setY(449);

    badGuyTwo->setX(444);
    badGuyTwo->setY(631);

    badGuyThree->setX(200);
    badGuyThree->setY(410);

    badGuyFour->setX(900);
    badGuyFour->setY(625);

    world4->addCharacter(badGuyOne);
    world4->addCharacter(badGuyTwo);
    world4->addCharacter(badGuyThree);
    world4->addCharacter(badGuyFour);

    WorldObstacle* obs1 = new WorldObstacle();
    WorldObstacle* obs2 = new WorldObstacle();
    WorldObstacle* obs3 = new WorldObstacle();

    obs1->setX(500);
    obs1->setY(0);
    obs1->setWidth(180);
    obs1->setHeight(40);

    obs2->setX(680);
    obs2->setY(0);
    obs2->setWidth(600);
    obs2->setHeight(40);

    obs3->setX(0);
    obs3->setY(0);
    obs3->setWidth(500);
    obs3->setHeight(40);

    world4->addObstacle(obs1);
    world4->addObstacle(obs2);
    world4->addObstacle(obs3);

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

    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldEnemy* badGuyThree = new WorldEnemy();
    WorldEnemy* badGuyFour = new WorldEnemy();

    badGuyOne->setX(86);
    badGuyOne->setY(138);

    badGuyTwo->setX(590);
    badGuyTwo->setY(583);

    badGuyThree->setX(611);
    badGuyThree->setY(243);

    badGuyFour->setX(276);
    badGuyFour->setY(461);

    world5->addCharacter(badGuyOne);
    world5->addCharacter(badGuyTwo);
    world5->addCharacter(badGuyThree);
    world5->addCharacter(badGuyFour);

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


    obs1->setX(243);
    obs1->setY(0);
    obs1->setWidth(68);
    obs1->setHeight(17);

    obs2->setX(154);
    obs2->setY(0);
    obs2->setWidth(84);
    obs2->setHeight(47);

    obs3->setX(0);
    obs3->setY(0);
    obs3->setWidth(43);
    obs3->setHeight(31);

    obs4->setX(0);
    obs4->setY(32);
    obs4->setWidth(21);
    obs4->setHeight(554);

    obs5->setX(206);
    obs5->setY(156);
    obs5->setWidth(83);
    obs5->setHeight(107);

    obs6->setX(378);
    obs6->setY(301);
    obs6->setWidth(54);
    obs6->setHeight(44);

    obs7->setX(123);
    obs7->setY(404);
    obs7->setWidth(52);
    obs7->setHeight(45);

    obs8->setX(0);
    obs8->setY(678);
    obs8->setWidth(205);
    obs8->setHeight(42);

    obs9->setX(96);
    obs9->setY(563);
    obs9->setWidth(109);
    obs9->setHeight(113);

    obs10->setX(206);
    obs10->setY(561);
    obs10->setWidth(38);
    obs10->setHeight(73);

    obs11->setX(297);
    obs11->setY(560);
    obs11->setWidth(218);
    obs11->setHeight(75);

    obs12->setX(410);
    obs12->setY(449);
    obs12->setWidth(105);
    obs12->setHeight(108);

    obs13->setX(517);
    obs13->setY(444);
    obs13->setWidth(526);
    obs13->setHeight(75);

    obs14->setX(345);
    obs14->setY(698);
    obs14->setWidth(735);
    obs14->setHeight(22);

    obs15->setX(1084);
    obs15->setY(675);
    obs15->setWidth(54);
    obs15->setHeight(45);

    obs16->setX(1142);
    obs16->setY(554);
    obs16->setWidth(55);
    obs16->setHeight(166);

    obs17->setX(1198);
    obs17->setY(510);
    obs17->setWidth(82);
    obs17->setHeight(210);

    obs18->setX(1093);
    obs18->setY(440);
    obs18->setWidth(187);
    obs18->setHeight(68);

    obs19->setX(1205);
    obs19->setY(294);
    obs19->setWidth(73);
    obs19->setHeight(140);

    obs20->setX(1131);
    obs20->setY(350);
    obs20->setWidth(72);
    obs20->setHeight(84);

    obs21->setX(941);
    obs21->setY(287);
    obs21->setWidth(97);
    obs21->setHeight(151);

    obs22->setX(877);
    obs22->setY(320);
    obs22->setWidth(60);
    obs22->setHeight(71);

    obs23->setX(978);
    obs23->setY(205);
    obs23->setWidth(73);
    obs23->setHeight(74);

    obs24->setX(1054);
    obs24->setY(154);
    obs24->setWidth(65);
    obs24->setHeight(78);

    obs25->setX(1122);
    obs25->setY(106);
    obs25->setWidth(89);
    obs25->setHeight(76);

    obs26->setX(1080);
    obs26->setY(0);
    obs26->setWidth(200);
    obs26->setHeight(101);


    world5->addObstacle(obs1);
    world5->addObstacle(obs2);
    world5->addObstacle(obs3);
    world5->addObstacle(obs4);
    world5->addObstacle(obs5);
    world5->addObstacle(obs6);
    world5->addObstacle(obs7);
    world5->addObstacle(obs8);
    world5->addObstacle(obs9);
    world5->addObstacle(obs10);
    world5->addObstacle(obs11);
    world5->addObstacle(obs12);
    world5->addObstacle(obs13);
    world5->addObstacle(obs14);
    world5->addObstacle(obs15);
    world5->addObstacle(obs16);
    world5->addObstacle(obs17);
    world5->addObstacle(obs18);
    world5->addObstacle(obs19);
    world5->addObstacle(obs20);
    world5->addObstacle(obs21);
    world5->addObstacle(obs22);
    world5->addObstacle(obs23);
    world5->addObstacle(obs24);
    world5->addObstacle(obs25);
    world5->addObstacle(obs26);


    instance().addWorld(world5);

}

void Universe::createSixthWorld() {

    World* world6 = new World();

    world6->setId(6);
    world6->setDownWId(6);
    world6->setLeftWId(6);
    world6->setRightWId(1);
    world6->setUpWId(5);
    world6->setName(":/images/images/World6.png");

    WorldItem* itemOne = new WorldItem();
    itemOne->setProperty("key2");
    itemOne->setCoordinates(1090, 580);

    world6->addItem(itemOne);

    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldEnemy* badGuyThree = new WorldEnemy();
    WorldEnemy* badGuyFour = new WorldEnemy();
    WorldEnemy* badGuyFive = new WorldEnemy();

    badGuyOne->setX(148);
    badGuyOne->setY(329);

    badGuyTwo->setX(278);
    badGuyTwo->setY(493);

    badGuyThree->setX(150);
    badGuyThree->setY(602);

    badGuyFour->setX(538);
    badGuyFour->setY(478);

    badGuyFive->setX(845);
    badGuyFive->setY(611);

    world6->addCharacter(badGuyOne);
    world6->addCharacter(badGuyTwo);
    world6->addCharacter(badGuyThree);
    world6->addCharacter(badGuyFour);
    world6->addCharacter(badGuyFive);

    WorldObstacle* obs1 = new WorldObstacle();
    WorldObstacle* obs2 = new WorldObstacle();
    WorldObstacle* obs3 = new WorldObstacle();
    WorldObstacle* obs4 = new WorldObstacle();
    WorldObstacle* obs5 = new WorldObstacle();
    WorldObstacle* obs6 = new WorldObstacle();
    WorldObstacle* obs7 = new WorldObstacle();

    obs1->setX(0);
    obs1->setY(0);
    obs1->setWidth(194);
    obs1->setHeight(277);

    obs2->setX(0);
    obs2->setY(281);
    obs2->setWidth(86);
    obs2->setHeight(439);

    obs3->setX(89);
    obs3->setY(678);
    obs3->setWidth(1191);
    obs3->setHeight(42);

    obs4->setX(348);
    obs4->setY(0);
    obs4->setWidth(822);
    obs4->setHeight(361);

    obs5->setX(739);
    obs5->setY(365);
    obs5->setWidth(298);
    obs5->setHeight(193);

    obs6->setX(1043);
    obs6->setY(365);
    obs6->setWidth(127);
    obs6->setHeight(85);

    obs7->setX(1176);
    obs7->setY(0);
    obs7->setWidth(104);
    obs7->setHeight(675);

    world6->addObstacle(obs1);
    world6->addObstacle(obs2);
    world6->addObstacle(obs3);
    world6->addObstacle(obs4);
    world6->addObstacle(obs5);
    world6->addObstacle(obs6);
    world6->addObstacle(obs7);

    instance().addWorld(world6);

}

void Universe::createEighthWorld() {

    World* world8 = new World();

    world8->setId(8);
    world8->setDownWId(8);
    world8->setLeftWId(8);
    world8->setRightWId(5);
    world8->setUpWId(8);
    world8->setName(":/images/images/World8.png");

    WorldItem* itemOne = new WorldItem();
    itemOne->setProperty("key");
    itemOne->setCoordinates(147, 520);

    world8->addItem(itemOne);

    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldEnemy* badGuyThree = new WorldEnemy();
    WorldEnemy* badGuyFour = new WorldEnemy();
    WorldEnemy* badGuyFive = new WorldEnemy();
    WorldEnemy* badGuySix = new WorldEnemy();

    badGuyOne->setX(599);
    badGuyOne->setY(428);

    badGuyTwo->setX(736);
    badGuyTwo->setY(494);

    badGuyThree->setX(913);
    badGuyThree->setY(445);

    badGuyFour->setX(598);
    badGuyFour->setY(617);

    badGuyFive->setX(934);
    badGuyFive->setY(609);

    badGuySix->setX(331);
    badGuySix->setY(624);

    world8->addCharacter(badGuyOne);
    world8->addCharacter(badGuyTwo);
    world8->addCharacter(badGuyThree);
    world8->addCharacter(badGuyFour);
    world8->addCharacter(badGuyFive);
    world8->addCharacter(badGuySix);

    WorldObstacle* obs1 = new WorldObstacle();
    WorldObstacle* obs2 = new WorldObstacle();
    WorldObstacle* obs3 = new WorldObstacle();
    WorldObstacle* obs4 = new WorldObstacle();
    WorldObstacle* obs5 = new WorldObstacle();
    WorldObstacle* obs6 = new WorldObstacle();
    WorldObstacle* obs7 = new WorldObstacle();

    obs1->setX(0);
    obs1->setY(0);
    obs1->setWidth(1214);
    obs1->setHeight(360);

    obs2->setX(0);
    obs2->setY(364);
    obs2->setWidth(536);
    obs2->setHeight(89);

    obs3->setX(241);
    obs3->setY(455);
    obs3->setWidth(293);
    obs3->setHeight(113);

    obs4->setX(0);
    obs4->setY(456);
    obs4->setWidth(102);
    obs4->setHeight(264);

    obs5->setX(107);
    obs5->setY(689);
    obs5->setWidth(1173);
    obs5->setHeight(31);

    obs6->setX(1026);
    obs6->setY(365);
    obs6->setWidth(185);
    obs6->setHeight(199);

    obs7->setX(1217);
    obs7->setY(0);
    obs7->setWidth(63);
    obs7->setHeight(567);

    world8->addObstacle(obs1);
    world8->addObstacle(obs2);
    world8->addObstacle(obs3);
    world8->addObstacle(obs4);
    world8->addObstacle(obs5);
    world8->addObstacle(obs6);
    world8->addObstacle(obs7);

    instance().addWorld(world8);

}

void Universe::createNinthWorld()
{
    World* world9 = new World();

    world9->setId(9);
    world9->setDownWId(9);
    world9->setLeftWId(9);
    world9->setRightWId(4);
    world9->setUpWId(11);
    world9->setName(":/images/images/World9.png");

    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldEnemy* badGuyThree = new WorldEnemy();
    WorldEnemy* badGuyFour = new WorldEnemy();
    WorldEnemy* badGuyFive = new WorldEnemy();
    WorldEnemy* badGuySix = new WorldEnemy();

    badGuyOne->setX(1034);
    badGuyOne->setY(416);

    badGuyTwo->setX(1139);
    badGuyTwo->setY(126);

    badGuyThree->setX(708);
    badGuyThree->setY(269);

    badGuyFour->setX(328);
    badGuyFour->setY(275);

    badGuyFive->setX(640);
    badGuyFive->setY(94);

    badGuySix->setX(256);
    badGuySix->setY(131);

    world9->addCharacter(badGuyOne);
    world9->addCharacter(badGuyTwo);
    world9->addCharacter(badGuyThree);
    world9->addCharacter(badGuyFour);
    world9->addCharacter(badGuyFive);
    world9->addCharacter(badGuySix);

    instance().addWorld(world9);

}

void Universe::createTenthWorld()
{
    World* world10 = new World();

    world10->setId(10);
    world10->setDownWId(10);
    world10->setLeftWId(10);
    world10->setRightWId(10);
    world10->setUpWId(10);
    world10->setName(":/images/images/World10.png");

    WorldEnemy* badGuyOne = new WorldEnemy();

    badGuyOne->setX(400);
    badGuyOne->setY(200);

    badGuyOne->setHealth(50);
    world10->addCharacter(badGuyOne);

    instance().addWorld(world10);
}

void Universe::createEleventhWorld()
{
    World* world11 = new World();

    world11->setId(11);
    world11->setDownWId(9);
    world11->setLeftWId(11);
    world11->setRightWId(11);
    world11->setUpWId(12);
    world11->setName(":/images/images/World11.png");

    WorldItem* itemOne = new WorldItem();
    itemOne->setProperty("health");
    itemOne->setCoordinates(1101, 140);

    world11->addItem(itemOne);

    WorldNPC* goodGuy = new WorldNPC();

    goodGuy->setX(324);
    goodGuy->setY(209);
    goodGuy->setName("npc3");
    goodGuy->setAdvice("I used to be a badger farmer, but they kept dying from the \nbone marrow I was feeding them. My fish farm is doing much better!");
    goodGuy->setTitle("Max");
    world11->addCharacter(goodGuy);

    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldEnemy* badGuyThree = new WorldEnemy();
    WorldEnemy* badGuyFour = new WorldEnemy();
    WorldEnemy* badGuyFive = new WorldEnemy();

    badGuyOne->setX(1140);
    badGuyOne->setY(567);

    badGuyTwo->setX(890);
    badGuyTwo->setY(520);

    badGuyThree->setX(315);
    badGuyThree->setY(642);

    badGuyFour->setX(628);
    badGuyFour->setY(568);

    badGuyFive->setX(742);
    badGuyFive->setY(206);


    world11->addCharacter(badGuyOne);
    world11->addCharacter(badGuyTwo);
    world11->addCharacter(badGuyThree);
    world11->addCharacter(badGuyFour);
    world11->addCharacter(badGuyFive);


    instance().addWorld(world11);
}

void Universe::createTwelthWorld()
{
    World* world12 = new World();

    world12->setId(12);
    world12->setDownWId(11);
    world12->setLeftWId(12);
    world12->setRightWId(13);
    world12->setUpWId(12);
    world12->setName(":/images/images/World12.png");

    WorldNPC* goodGuy1 = new WorldNPC();

    goodGuy1->setX(332);
    goodGuy1->setY(174);
    goodGuy1->setName("npc4");
    goodGuy1->setAdvice("I'm sorry, but only the dankest can enter this castle.");
    goodGuy1->setTitle("Sir Dank");
    world12->addCharacter(goodGuy1);

    WorldNPC* goodGuy2 = new WorldNPC();

    goodGuy2->setX(413);
    goodGuy2->setY(174);
    goodGuy2->setName("npc5");
    goodGuy2->setAdvice("I used to be an adventurer like you, but then the castle offered me this post. \nIt's a stable wage, safer, and I have more time to spend with my family.");
    goodGuy2->setTitle("Sir Meme");
    world12->addCharacter(goodGuy2);

    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldEnemy* badGuyThree = new WorldEnemy();
    WorldEnemy* badGuyFour = new WorldEnemy();
    WorldEnemy* badGuyFive = new WorldEnemy();
    WorldEnemy* badGuySix = new WorldEnemy();

    badGuyOne->setX(1055);
    badGuyOne->setY(596);

    badGuyTwo->setX(461);
    badGuyTwo->setY(577);

    badGuyThree->setX(687);
    badGuyThree->setY(393);

    badGuyFour->setX(950);
    badGuyFour->setY(283);

    badGuyFive->setX(834);
    badGuyFive->setY(414);

    badGuySix->setX(1116);
    badGuySix->setY(270);

    world12->addCharacter(badGuyOne);
    world12->addCharacter(badGuyTwo);
    world12->addCharacter(badGuyThree);
    world12->addCharacter(badGuyFour);
    world12->addCharacter(badGuyFive);
    world12->addCharacter(badGuySix);

    instance().addWorld(world12);
}

void Universe::createThirteenthWorld()
{
    World* world13 = new World();

    world13->setId(13);
    world13->setDownWId(13);
    world13->setLeftWId(12);
    world13->setRightWId(14);
    world13->setUpWId(13);
    world13->setName(":/images/images/World13.png");

    WorldItem* itemOne = new WorldItem();
    itemOne->setProperty("health");
    itemOne->setCoordinates(159, 568);

    world13->addItem(itemOne);



    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldEnemy* badGuyThree = new WorldEnemy();


    badGuyOne->setX(612);
    badGuyOne->setY(132);

    badGuyTwo->setX(580);
    badGuyTwo->setY(495);

    badGuyThree->setX(1151);
    badGuyThree->setY(452);



    world13->addCharacter(badGuyOne);
    world13->addCharacter(badGuyTwo);
    world13->addCharacter(badGuyThree);


    instance().addWorld(world13);
}

void Universe::createFourteenthWorld()
{
    World* world14 = new World();

    world14->setId(14);
    world14->setDownWId(14);
    world14->setLeftWId(13);
    world14->setRightWId(14);
    world14->setUpWId(14);
    world14->setName(":/images/images/World14.png");

    WorldItem* itemOne = new WorldItem();
    itemOne->setProperty("heart");
    itemOne->setCoordinates(1011, 197);

    world14->addItem(itemOne);

    WorldItem* itemTwo = new WorldItem();
    itemTwo->setProperty("key3");
    itemTwo->setCoordinates(1085, 552);

    world14->addItem(itemTwo);

    WorldEnemy* badGuyOne = new WorldEnemy();
    WorldEnemy* badGuyTwo = new WorldEnemy();
    WorldEnemy* badGuyThree = new WorldEnemy();
    WorldEnemy* badGuyFour = new WorldEnemy();
    WorldEnemy* badGuyFive = new WorldEnemy();
    WorldEnemy* badGuySix = new WorldEnemy();

    badGuyOne->setX(200);
    badGuyOne->setY(566);

    badGuyTwo->setX(418);
    badGuyTwo->setY(540);

    badGuyThree->setX(617);
    badGuyThree->setY(631);

    badGuyFour->setX(642);
    badGuyFour->setY(509);

    badGuyFive->setX(793);
    badGuyFive->setY(600);

    badGuySix->setX(954);
    badGuySix->setY(578);

    world14->addCharacter(badGuyOne);
    world14->addCharacter(badGuyTwo);
    world14->addCharacter(badGuyThree);
    world14->addCharacter(badGuyFour);
    world14->addCharacter(badGuyFive);
    world14->addCharacter(badGuySix);

    instance().addWorld(world14);
}

void Universe::Save()
{
    player->getScore()->Save();
    player->getScore()->HighscoreSave();
    ofstream outputFile;
    outputFile.open("segfaultSave.txt", ofstream::out | ofstream::trunc);

    outputFile << player->getData();
    cout << player->getData();
    for (int index = 1; index < Universe::instance().getWorlds().size(); index++) {
        //cout << "world" << Universe::instance().getWorld(index)->getId() << "\n";
        //outputFile << "world" << Universe::instance().getWorld(index)->getId() << "\n";

        if(Universe::instance().getWorld(index) != NULL && Universe::instance().getWorld(index)->charsEnabled()){
            for (unsigned int i = 0; i < Universe::instance().getWorld(index)->getCharacters().size(); i++) {
                    WorldCharacter* enemy1 = Universe::instance().getWorld(index)->getCharacters().at(i);
                    cout << enemy1->getData();
                    outputFile << enemy1->getData();
                }
            }

        if(Universe::instance().getWorld(index) != NULL && Universe::instance().getWorld(index)->itemsEnabled()){
            for (unsigned int i = 0; i < Universe::instance().getWorld(index)->getItems().size(); i++) {
                WorldItem* item1 = Universe::instance().getWorld(index)->getItems().at(i);
                cout << item1->getData();
                outputFile << item1->getData();
            }
        }
    }

    outputFile.close();
}

void Universe::Load()
{
    const int maxChars = 5120;
    const int maxTokens = 200;
    const char* const delimiter = ",";

    ifstream fin;
    fin.open("segfaultSave.txt");
    if (!fin.good())
    {
        //TODO: error message
    }
    else {
        while (!fin.eof())
        {
            char buf[maxChars];
            fin.getline(buf, maxChars);

            int i = 0;

            const char* token[maxTokens] = {};

            token[0] = strtok(buf, delimiter);
            if (token[0])
            {
                for (i = 1; i < maxTokens; i++) {
                    token[i] = strtok(0, delimiter);
                    if (!token[i])
                    {
                        break;
                    }
                }
            }

            for (int n = 0; n < i; n++)
            {
                cout << "Token[" << n << "] = " << token[n];
                cout << endl;
            }

            stringstream playerx;
            playerx << token[0];
            int playerIntx;
            playerx >> playerIntx;

            stringstream playery;
            playery << token[1];
            int playerInty;
            playery >> playerInty;

            stringstream playerHealth;
            playerHealth << token[2];
            int playerIntHealth;
            playerHealth >> playerIntHealth;

            stringstream playerStrength;
            playerStrength << token[3];
            int playerIntStrength;
            playerStrength >> playerIntStrength;

            stringstream playerDefense;
            playerDefense << token[4];
            int playerIntDefense;
            playerDefense >> playerIntDefense;

            stringstream playerOrientation;
            playerOrientation << token[5];
            int playerIntOrientation;
            playerOrientation >> playerIntOrientation;

            stringstream playerDead;
            playerDead << token[6];
            int playerIntDead;
            playerDead >> playerIntDead;

            stringstream playerWorld;
            playerWorld << token[7];
            int worldNum;
            playerWorld >> worldNum;

            Universe::instance().player->setCoordinates(playerIntx, playerInty);
            Universe::instance().player->setHealth(playerIntHealth);
            Universe::instance().player->setDefense(playerIntDefense);
            Universe::instance().player->setOrientation(playerIntOrientation);
            Universe::instance().player->setDead(playerIntDead);
            Universe::instance().player->setCurrentWorld(worldNum);


            int tokenPos = 8; // HACKY HACKY HACK
            for (int enemy = 0; enemy < 2; enemy++)
            {
                stringstream enemyx;
                enemyx << token[tokenPos];
                int enemyIntx;
                enemyx >> enemyIntx;
                tokenPos++;

                stringstream enemyy;
                enemyy << token[tokenPos];
                int enemyInty;
                enemyy >> enemyInty;
                tokenPos++;

                stringstream enemyHealth;
                enemyHealth << token[tokenPos];
                int enemyIntHealth;
                enemyHealth >> enemyIntHealth;
                tokenPos++;

                stringstream enemyStrength;
                enemyStrength << token[tokenPos];
                int enemyIntStrength;
                enemyStrength >> enemyIntStrength;
                tokenPos++;

                stringstream enemyDefense;
                enemyDefense << token[tokenPos];
                int enemyIntDefense;
                enemyDefense >> enemyIntDefense;
                tokenPos++;

                stringstream enemyOrientation;
                enemyOrientation << token[tokenPos];
                int enemyIntOrientation;
                enemyOrientation >> enemyIntOrientation;
                tokenPos++;

                stringstream enemyDead;
                enemyDead << token[tokenPos];
                int enemyIntDead;
                enemyDead >> enemyIntDead;
                tokenPos++;

                WorldCharacter* typicalEnemy = Universe::instance().getWorld(1)->getCharacters().at(enemy);
                typicalEnemy->setCoordinates(enemyIntx, enemyInty);
                typicalEnemy->setHealth(enemyIntHealth);
                typicalEnemy->setStrength(enemyIntStrength);
                typicalEnemy->setDefense(enemyIntDefense);
                typicalEnemy->setOrientation(enemyIntOrientation);
                typicalEnemy->setDead(enemyIntDead);
            }


            break;
        }
    }
}


