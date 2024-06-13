#include "area.h"


area::area(int a, int b){
    x = a;
    y = b;
    locked = false;
}

area::area(int a, int b, bool isLocked, item& i1, item& i2, item& i3){
    x = a;
    y = b;
    locked = isLocked;
    room = true;
    objects[0] = i1;
    objects[1] = i2;
    objects[2] = i3;
}

area::area(int a, int b, bool isLocked, int level, item& i1, item& i2, item& i3){
    room = true;
    x =a;
    y = b;
    locked = false;
    has_monster = true;
    aMonster = new monster(level);
    objects[0] = i1;
    objects[1] = i2;
    objects[2] = i3;
}

bool area::isLocked(){
    return locked;
}

void area::key_Found (){
    locked = false;
}

void area::addDescription(string added){
    description = added;
}

string area::getDescription(){
    return description;
}

int area::getX(){
    return x;
}

int area::gety(){
    return y;
}


bool area::isRoom(){
    return room;
}

bool area::hasMonster(){
    return has_monster;
}

area::~area(){
    if (aMonster){
        delete aMonster;
    }
}

monster* area::getMonster(){
        return aMonster;
    }