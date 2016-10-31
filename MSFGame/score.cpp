#include "score.h"
#include <QFont>

Score * score;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    // initialize score to 0
    score = 0;

    // draw the text
    setPlainText(QString("SCORE: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::black);
    setFont(QFont("utopia", 25, 75));
}

void Score::increase(int amount){
    score = score + amount;
}

int Score::getScore() {
    return score;
}
