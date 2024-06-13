#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
//#include <cstring>
using namespace std;


class weapon{
    public:
    string name;
    int level;
    bool acquired = false;
    string description;

    weapon();

    weapon(int wLevel);

    void acquisition();

};

#endif