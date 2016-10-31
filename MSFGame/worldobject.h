#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <string>

using namespace std;

class WorldObject{
private:
    int xPos;          //x coordinate of object
    int yPos;          //y coordinate of object
    int scaling;       //accounts for the size of an image being scaled by 60,60 for instance
    string name;       //represents the image associated with the object

public:

    //Constructors
    WorldObject(): xPos(0),yPos(0),scaling(60),name(""){}
    WorldObject(int newX, int newY, string newName): xPos(newX),yPos(newY), name(newName){}

    //Accessors
    int getX(){return xPos;}
    int getY(){return yPos;}
    int getXScaled(){return (xPos + scaling);}
    int getYScaled(){return (yPos + scaling);}
    string getName(){return name;}

    //Mutators
    void setX(int newX) {xPos = newX;}
    void setY(int newY) {yPos = newY;}
    void setName(string newName){name = newName;}
    void setScaling(int newScaling){scaling = newScaling;}
    void setCoordinates(int, int);

    //Increment and Decrement x and y pos
    void incX(){xPos++;}
    void decX(){xPos--;}
    void incY(){yPos++;}
    void decY(){yPos--;}

    //Distance Methods
    double distance(WorldObject*);
    int vDistance(WorldObject*);
    int hDistance(WorldObject*);

    //Compares the Positions of two worldObjects, returns true if the caller's X or Y is greater than or equal to the WorldObject's
    bool compareX(WorldObject*);
    bool compareY(WorldObject*);

};

#endif // WORLDOBJECT_H
