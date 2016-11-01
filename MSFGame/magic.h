#ifndef MAGIC_H
#define MAGIC_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Magic: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT

    int direction;

public:

    Magic();

    //Accesors
    int getDirection(){return direction;}

    //Mutators
    void setDirection(int newDirection){direction = newDirection;}

public slots:

    void move();

private:
    int anim = 1;

};

#endif // MAGIC_H
