#include "worldobject.h"
#include <string>
#include <cmath>

using namespace std;

//Add Save and Load Methods -to be overwritten by inherited classes

 void WorldObject::setCoordinates(int newX, int newY)
 {
     xPos = newX;
     yPos = newY;
 }


 int WorldObject::distance(WorldObject* otherObj)
 {
    return sqrt(((this->getX()-otherObj->getX())^2) + ((this->getY()-otherObj->getY())^2));
 }

 int WorldObject::vDistance(WorldObject* otherObj)
 {
    return sqrt(((this->getX()-otherObj->getX())^2));
 }

 int WorldObject::hDistance(WorldObject* otherObj)
 {
    return sqrt(((this->getY()-otherObj->getY())^2));
 }
