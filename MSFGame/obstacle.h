#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QObject>
#include <QGraphicsItem>
#include <worldobstacle.h>

class Obstacle : public QGraphicsRectItem
{
    WorldObstacle* obstacle;

public:
    Obstacle();

    WorldObstacle* getObstacle(){return obstacle;}

    void setObstacle(WorldObstacle* newObstacle){obstacle = newObstacle;}
};

#endif // OBSTACLE_H
