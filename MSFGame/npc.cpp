#include "npc.h"

NPC::NPC(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/images/fire9.png").scaled(34, 40));

}
