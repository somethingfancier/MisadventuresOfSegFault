#ifndef WORLDOBSTACLE_H
#define WORLDOBSTACLE_H

#include <string>
#include "worldobject.h"

class WorldObstacle: public WorldObject{

private:
    bool destroyable;
    int health;
    string property;

public:
    //Constructor
    WorldObstacle():destroyable(false),health(0),property(""){}

    //Accessors
    bool getDestroyable(){return destroyable;}
    int gethealth(){return health;}
    string getProperty(){return property;}

    //Mutators
    void setDestroyable(bool newState){destroyable = newState;}
    void setHealth(int newHealth){health = newHealth;}
    void setProperty(string newProperty){property = newProperty;}

};

#endif // WORLDOBSTACLE_H
