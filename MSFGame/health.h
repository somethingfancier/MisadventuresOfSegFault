#ifndef HEALTH_H
#define HEALTH_H

#include "worldhealth.h"
#include <QGraphicsTextItem>
#include <vector>

class Health: public QGraphicsTextItem {

private:
    WorldHealth* health;

public:
    Health(QGraphicsItem * parent = 0);

    WorldHealth* getHealth(){return health;}
    void updateHealth();
    void setHeath(WorldHealth* newHealth){health = newHealth;}
    void Save();
    void Load();
};

#endif // HEALTH_H
