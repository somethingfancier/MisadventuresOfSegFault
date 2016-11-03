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
    string property;


public:


    Item(QGraphicsItem * parent=0);

    void setProperty(string newProp) {property = newProp;}


};


#endif // ITEM_H
