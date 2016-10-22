#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class Player: public QGraphicsRectItem{
public:

    int lives;
    WorldItem item;
    vector<*WorldItem> items;

    void Move();
    void LongAttack(int, int);
    string Speak() {
        return string;
    }

    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
