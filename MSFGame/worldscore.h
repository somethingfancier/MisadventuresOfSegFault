#ifndef WORLDSCORE_H
#define WORLDSCORE_H

#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

class WorldScore
{
    int score;
public:
    WorldScore();
    void increase(int amount);
    int getScore();

    void Save();
    void Load();
};


#endif // WORLDSCORE_H
