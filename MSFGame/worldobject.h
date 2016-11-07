#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <string>

using namespace std;

class WorldObject{
private:
    int xPos;          //x coordinate of object
    int yPos;          //y coordinate of object
    int width;         //accounts for the size of an image being scaled by 60,60 for instance
    int height;
    string name;       //represents the image associated with the object
    bool negativeD;


public:

    //Constructors
    WorldObject(): xPos(0),yPos(0),width(35),height(45),name(""), negativeD(false){}
    WorldObject(int newX, int newY, string newName): xPos(newX),yPos(newY), name(newName){}

    //Accessors
    virtual int getX(){return xPos;}
    virtual int getY(){return yPos;}
    int getXScaled(){return (xPos + width);}
    int getYScaled(){return (yPos + height);}
    int getWidth(){return width;}
    int getHeight(){return height;}
    string getName(){return name;}
    bool isNegativeD(){return negativeD;}

    //Mutators
    void setX(int newX) {xPos = newX;}
    void setY(int newY) {yPos = newY;}
    void setName(string newName){name = newName;}
    void setCoordinates(int, int);
    void setWidth(int newWidth){width = newWidth;}
    void setHeight(int newHeight){height = newHeight;}

    //Increment and Decrement x and y pos
    void incX(){xPos++;}
    void incXX(){xPos = xPos+6;}
    void decX(){xPos--;}
    void decXX(){xPos = xPos-6;}
    void incY(){yPos++;}
    void incYY(){yPos = yPos+6;}
    void decY(){yPos--;}
    void decYY(){yPos = yPos-6;}

    //Distance Methods
    double distance(WorldObject*);
    int vDistance(WorldObject*);
    int hDistance(WorldObject*);

    int hSDistance(WorldObject*);
    int vSDistance(WorldObject*);

    int hSSDistance(WorldObject*);
    int vSSDistance(WorldObject*);

    bool withinXBound(WorldObject*);
    bool withinYBound(WorldObject *);

    bool withinXSBound(WorldObject*);
    bool withinYSBound(WorldObject *);

    //Compares the Positions of two worldObjects, returns true if the caller's X or Y is greater than or equal to the WorldObject's
    bool compareX(WorldObject*);
    bool compareY(WorldObject*);

    virtual string getData() {
        string data;
        data = data + (to_string(this->getX()) + "," + to_string(this->getY()));
        return data;
    }

};

#endif // WORLDOBJECT_H
