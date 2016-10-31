#ifndef WORLDOBSTACLE_H
#define WORLDOBSTACLE_H

#include <string>
#include "worldobject.h"

class WorldObstacle: public WorldObject{

private:
    bool destroyable;
    int health;
    string property;
    int x;
    int y;
    int width;
    int height;

public:
    //Constructor
    WorldObstacle():destroyable(false),health(0),property(""){}

    //Accessors
    bool getDestroyable(){return destroyable;}
    int gethealth(){return health;}
    string getProperty(){return property;}
    int getX(){return x;}
    int getY(){return y;}
    int getWidth(){return width;}
    int getHeight(){return height;}

    //Mutators
    void setDestroyable(bool newState){destroyable = newState;}
    void setHealth(int newHealth){health = newHealth;}
    void setProperty(string newProperty){property = newProperty;}
    void setX(int newX){x = newX;}
    void setY(int newY){y = newY;}
    void setWidth(int newWidth){width = newWidth;}
    void setHeight(int newHeight){height = newHeight;}

};

#endif // WORLDOBSTACLE_H
