#ifndef SCORE_H
#define SCORE_H

#include "worldscore.h"
#include <QGraphicsTextItem>
#include <vector>

class Score: public QGraphicsTextItem {

private:
    WorldScore* score;

public:
    Score(QGraphicsItem * parent = 0);

    WorldScore* getScore(){return score;}
    void updateScore();
    void Save();
    void Load();
};

#endif // SCORE_H
