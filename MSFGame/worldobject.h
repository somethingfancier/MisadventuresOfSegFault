#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <string>

using namespace std;

class WorldObject{
private:
    int xPos;          //x coordinate of object
    int yPos;          //y coordinate of object
    string name;       //represents the image associated with the object

public:

    //Constructors
    WorldObject(): xPos(0),yPos(0),name(""){}
    WorldObject(int newX, int newY, string newName): xPos(newX),yPos(newY), name(newName){}

    //Accessors
    int getX(){return xPos;}
    int getY(){return yPos;}
    string getName(){return name;}

    //Mutators
    void setX(int newX) {xPos = newX;}
    void setY(int newY) {yPos = newY;}
    void setName(string newName){name = newName;}
    void setCoordinates(int, int);

    //
    int distance(WorldObject*);
    int vDistance(WorldObject*);
    int hDistance(WorldObject*);
};

#endif // WORLDOBJECT_H
