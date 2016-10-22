#ifndef ITEM_H
#define ITEM_H

class Item : public WorldObject {

public:
    bool equippable;
    int strength;
    int defense;
    int heal;
    string property;

    Item();
}

#endif // ITEM_H
