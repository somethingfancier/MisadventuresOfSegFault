#include "score.h"
#include <QFont>
#include "worldscore.h"
#include <iostream>

Score * score;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    // initialize score to 0
    score = new WorldScore();

    // draw the text

    setPlainText(QString("SCORE: ") + QString::number(score->getScore())); // Score: 0
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("utopia", 25, 75));
}

void Score::updateScore()
{
    setPlainText(QString("SCORE: ") + QString::number(score->getScore()));
    std::cout << score->getScore();
    setDefaultTextColor(Qt::black);
    setFont(QFont("utopia", 25, 75));
}
