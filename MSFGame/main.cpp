#include "mainwindow.h"
#include <cassert>
#include <QApplication>
#include "universe.h"
#include "world.h"
#include "worldobject.h"
#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"
#include "worldnpc.h"
#include "worlditem.h"
#include "worldobstacle.h"
#include <iostream>

using namespace std;

static void runUnitTest()
{
    Universe* galaxy = new Universe;
    World* aWholeNewWorld = new World;
    WorldPlayer* playerOne = new WorldPlayer;
    WorldNPC* oldWazerd = new WorldNPC;
    WorldEnemy* badDude = new WorldEnemy;
    WorldItem* myItem = new WorldItem;
    galaxy->addWorld(aWholeNewWorld);
    galaxy->setPlayer(playerOne);
    assert(galaxy->getWorld(0)->getId()== 0);
    assert(oldWazerd->getAdvice() == "I have no advice for you.");
    assert(badDude->getHealth() == 10);
    assert(myItem->getName() == "");
    assert(playerOne->getX() == 0);
    assert(playerOne->getY() == 0);

    playerOne->setX(283);
    playerOne->setY(556);
    assert(playerOne->getX() == 283);
    assert(playerOne->getY() == 556);
    myItem->setEquipped(true);
    assert(myItem->getEquipped() == true);

    playerOne->setX(50);
    playerOne->setY(0);
    badDude->setCoordinates(0,0);
    assert(badDude->distance(playerOne)== 50.0);

    playerOne->strike(badDude);
    assert(badDude->getHealth()==9);

    delete galaxy;
    delete aWholeNewWorld;
    delete playerOne;
    delete badDude;
    delete myItem;
    delete oldWazerd;

}

int main(int argc, char *argv[])
{
    vector<string> args(&argv[0],&argv[argc]);

    //if (args.size() > 1 && args.at(1) == "-test")
    //{
        runUnitTest();
    //}

    Universe::instance().createFirstWorld(); //Creates the Universe and the First World in the Game
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(800,600);
    w.show();

    return a.exec();
}

