#include "npc.h"

NPC::NPC(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/images/images/npc1.png").scaled(34, 40));
    npc = new WorldNPC();
}
