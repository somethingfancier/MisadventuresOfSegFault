#ifndef WORLDHEALTH_H
#define WORLDHEALTH_H

class WorldHealth
{
    int health;
public:
    WorldHealth();
    void increase(int amount);
    void decrease(int amount);
    int getHealth();
    void setHealth(int healthAmount);
};

#endif // WORLDHEALTH_H
