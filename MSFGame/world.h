#ifndef WORLD_H
#define WORLD_H

#include "worldenemy.h"
#include "worldchar.h"
#include "worldobstacle.h"
#include "worlditem.h"
#include "worldnpc.h"
#include <string>

using namespace std;

class World{
private:
    int id;
    string name;
    vector<WorldCharacter*> characters;
    vector<WorldItem*> items;
    vector<WorldObstacle*> obstacles;

public:
    //Constructor
    World(int newId, string imageName):id(newId),name(imageName){}

    //Accessors
    int getId(){return id;}
    string getName(){return name;}

    //Mutators
    void setId(int newId){id = newId;}
    void setName(string newName){name = newName;}

    //Adders for the Vectors
    void addCharacter(WorldCharacter*);
    void addItem(WorldCharacter*);
    void addObstacle(WorldCharacter*);

};

#endif // WORLD_H
