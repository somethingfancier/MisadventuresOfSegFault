#ifndef NPC_H
#define NPC_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "worldnpc.h"
#include <string>

class NPC: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    WorldNPC *npc;
    string advice;


public:


    NPC(QGraphicsItem * parent=0);

    void setAdvice(string newAdv) {advice = newAdv;}


};


#endif // NPC_H
