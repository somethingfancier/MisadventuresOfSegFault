#include "lives.h"
#include <QFont>
#include "worldlives.h"
#include <iostream>

Lives * lives;

Lives::Lives(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    // initialize score to 0
    lives = new WorldLives();

    // draw the text

    setPos(1000, 0);
    setPlainText(QString("LIVES: ") + QString::number(lives->getLives())); // Lives: 0
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("utopia", 25, 75));

}

void Lives::updateLives()
{
    setPlainText(QString("LIVES: ") + QString::number(lives->getLives()));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("utopia", 25, 75));
}
