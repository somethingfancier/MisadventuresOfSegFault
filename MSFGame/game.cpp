#include "game.h"
#include <QGraphicsTextItem>

Game::Game(QWidget *parent) {
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720);


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);


    player = new Player();
    player->setRect(0,0,20,20);
    player->setPos(100,200);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    show();
}
