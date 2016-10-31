#ifndef WORLDSCORE_H
#define WORLDSCORE_H

class WorldScore
{
    int score;
public:
    WorldScore();
    void increase(int amount);
    int getScore();
};

#endif // WORLDSCORE_H
