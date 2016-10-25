#include "mainwindow.h"
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

using namespace std;

static void runUnitTest()
{

}

int main(int argc, char *argv[])
{
    Universe::instance().createFirstWorld(); //Creates the Universe and the First World in the Game
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(800,600);
    w.show();

    return a.exec();
}

