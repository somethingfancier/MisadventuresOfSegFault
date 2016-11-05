#ifndef LIVES_H
#define LIVES_H

#include "worldlives.h"
#include <QGraphicsTextItem>
#include <vector>

class Lives: public QGraphicsTextItem {

private:
    WorldLives* lives;

public:
    Lives(QGraphicsItem * parent = 0);

    WorldLives* getLives(){return lives;}
    void updateLives();
    void Save();
    void Load();
};

#endif // LIVES_H
