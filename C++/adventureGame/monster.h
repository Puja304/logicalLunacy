#ifndef MONSTER_H
#define MONSTER_H


#include <iostream>
using namespace std;

class monster{
    private:
    string name;
    int level;
    bool defeated = false;
    int health = 100;

    public:

    monster(int monsterLevel);

    string getName();

    int getLevel();

    void displayMonster();

    //returns the amount of damage received. -1 means dead. 
    int fight(int weaponLevel, int userHealth, bool hasBomb);

    bool isDefeated(){
        return defeated;
    }
};

#endif