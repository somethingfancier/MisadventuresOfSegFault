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
    string name;
    bool gotAdvice;



public:


    NPC(QGraphicsItem * parent=0);
    WorldNPC* getNPC(){return npc;}
    void setNPC(WorldNPC* newNPC){npc = newNPC;}
    void setAdvice(string newAdv) {advice = newAdv;}
    void setName(string newName) {name = newName;}
    void setGotAdvice(bool newGot){gotAdvice = newGot;}


    string getAdvice(){return advice;}
    string getName(){return name;}
    bool getGotAdvice(){return gotAdvice;}




};


#endif // NPC_H
