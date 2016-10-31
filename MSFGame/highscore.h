#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "score.h"
#include <vector>

class highscore
{
private:
    // vector<Score*> highScores;

public:
    highscore();
    // vector<Score*>& getScores() { return highScores; }

    void addScore(Score*);
};

#endif // HIGHSCORE_H
