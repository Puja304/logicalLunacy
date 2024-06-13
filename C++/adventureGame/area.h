#ifndef AREA_H
#define AREA_H

#include <iostream>
#include "item.h"
#include "monster.h"
using namespace std;


class area{
    private:
    bool locked = true;
    bool room = false;
    bool has_monster = false;
    monster* aMonster = nullptr;
    int x = 0;
    int y = 0;
    string description;
    
    public:

    ~area();

    item objects[3];

    //
    area(int a, int b);

    area(int a, int b, bool isLocked, item& i1, item& i2, item& i3);

    area(int a, int b, bool isLocked, int level, item& i1, item& i2, item& i3);

    //
    bool isLocked();

    //
    void key_Found();
    //
    void addDescription(string added);

    string getDescription();


    int getX();

    int gety();

    bool isRoom();

    bool hasMonster();

    monster* getMonster();
};

#endif