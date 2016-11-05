#include "worldobject.h"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

//Add Save and Load Methods -to be overwritten by inherited classes

 void WorldObject::setCoordinates(int newX, int newY)
 {
     xPos = newX;
     yPos = newY;
 }


 double WorldObject::distance(WorldObject* otherObj)
 {
    double answer = sqrt(pow((this->getXScaled()-otherObj->getXScaled()),2)+pow((this->getYScaled()-otherObj->getYScaled()),2));
    return answer;
 }

 int WorldObject::vDistance(WorldObject* otherObj)
 {
    return abs(this->getY()-otherObj->getY());
 }

 int WorldObject::hDistance(WorldObject* otherObj)
 {
     return abs(this->getX()- otherObj->getX());
 }

 int WorldObject::hSDistance(WorldObject *otherObj)
 {
     return abs(this->getXScaled()-otherObj->getX());
 }

 int WorldObject::vSDistance(WorldObject *otherObj)
 {
     return abs(this->getYScaled()- otherObj->getY());
 }

 int WorldObject::hSSDistance(WorldObject *otherObj)
 {
     return abs(this->getXScaled()-otherObj->getXScaled());
 }

 int WorldObject::vSSDistance(WorldObject *otherObj)
 {
     return abs(this->getYScaled()- otherObj->getYScaled());
 }

 bool WorldObject::withinXBound(WorldObject *obj)
 {
     if(this->getWidth() <= obj->getWidth())
     {
         int cmpWidthT = obj->hSDistance(this) + this->hDistance(obj);
         int cmpWidthB = obj->hSSDistance(this) + this->hSDistance(obj);
         return(cmpWidthT == obj->getWidth() || cmpWidthB == obj->getWidth());
     }
     else
     {
        int cmpWidth = this->hSDistance(obj) + obj->hDistance(this);
        return(cmpWidth == this->getWidth());
     }
 }

 bool WorldObject::withinYBound(WorldObject *obj)
 {
     if(this->getHeight() <= obj->getHeight())
     {
         int cmpHeightT = obj->vSDistance(this) + this->vDistance(obj);
         int cmpHeightB = obj->vSSDistance(this) + this->vSDistance(obj);
         return(cmpHeightT == obj->getHeight() || cmpHeightB == obj->getHeight());
     }
     else
     {
        int cmpHeight = obj->vSDistance(this) + obj->vDistance(this);
        return(cmpHeight == this->getHeight());
     }

 }

 bool WorldObject::compareX(WorldObject* obj)
 {
     if(this->getX() >= obj->getX())
     {
         return true;
     }
     return false;
 }


 bool WorldObject::compareY(WorldObject* obj)
 {
     if(this->getY() >= obj->getY())
     {
         return true;
     }
     return false;
 }

