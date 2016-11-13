#include "item.h"

Item::Item(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/images/fire9.png").scaled(30, 30));


}
