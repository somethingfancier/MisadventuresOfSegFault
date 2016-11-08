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
    bool gotAdvice;


public:


    NPC(QGraphicsItem * parent=0);
    WorldNPC* getNPC(){return npc;}
    void setNPC(WorldNPC* newNPC){npc = newNPC;}
    void setGotAdvice(bool newGot){gotAdvice = newGot;}

    string getAdvice(){return advice;}
    bool getGotAdvice(){return gotAdvice;}

    void setAdvice(string newAdv) {advice = newAdv;}


};


#endif // NPC_H
