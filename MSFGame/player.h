#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>


class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT



public:

    Player(QGraphicsItem * parent=0);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:

    void timerHitUp();
    void timerHitDown();
    void timerHitLeft();
    void timerHitRight();
    void timerAnimUp();
    void timerAnimDown();
    void timerAnimLeft();
    void timerAnimRight();

private:
    QTimer* timer;
    QTimer* timertwo;

};

#endif // PLAYER_H
