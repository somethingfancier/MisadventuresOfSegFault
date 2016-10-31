#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem {

private:
    int score;

public:
    Score(QGraphicsItem * parent = 0);
    void increase(int amount);
    int getScore();

    void Save();
    void Load();
};

#endif // SCORE_H
