#include "health.h"
#include <QFont>
#include "worldhealth.h"
#include <iostream>
#include "universe.h"

Health * health;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    // initialize health
    health = new WorldHealth();

    // draw the text

    setPos(1040, 50);
    setPlainText(QString("HEALTH: ") + QString::number(health->getHealth()));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("utopia", 25, 75));

}

void Health::updateHealth()
{
    health->setHealth(Universe::instance().getPlayer()->getHealth());
    setPlainText(QString("HEALTH: ") + QString::number(health->getHealth()));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("utopia", 25, 75));
}
