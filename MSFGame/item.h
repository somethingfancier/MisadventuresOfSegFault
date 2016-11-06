#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "worlditem.h"
#include <string>

class Item: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    WorldItem *item;

public:

    Item(QGraphicsItem * parent=0);
    WorldItem* getItem(){return item;}
    void setItem(WorldItem* newItem){item = newItem;}


};


#endif // ITEM_H
