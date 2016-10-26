#include "game.h"
#include <QGraphicsTextItem>

Game::Game(QWidget *parent) {
    
    universe = new Universe();
    universe->createFirstWorld();
    
    player = new Player();
    player->setRect(0,0,20,20);
    player->setPos(100,200);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);

    scene->addItem(player);

    World* world = universe->getWorld(1);
    for (unsigned i=0; i<world->getCharacters().size(); i++) {
        WorldCharacter* enemyData = world->getCharacters().at(i);
        Enemy* enemy = new Enemy();
        enemy->setRect(0,0,20,20);
        enemy->setPos(enemyData->getX(), enemyData->getY());
        scene->addItem(enemy);
    }





    show();
}
