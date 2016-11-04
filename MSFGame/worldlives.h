#ifndef WORLDLIVES_H
#define WORLDLIVES_H


class WorldLives
{
    int lives;
public:
    WorldLives();
    void increase(int amount);
    void decrease(int amount);
    int getLives();
    void setLives(int numLives);
};


#endif // WORLDLIVES_H
