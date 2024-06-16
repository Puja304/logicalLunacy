#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "weapon.h"
#include "item.h"

using namespace std;

class character {
    private:
    int health;
    int lives;
    weapon* weapons = nullptr ;
    int weapon_count = 0;
    item items[4];
    int smoke_bombs;
    int item_count = 0;
    bool alive= true;
    bool hasSmokeBomb;

    public:
    character();

    ~character();

    int gethealth();

    int getLives();

    weapon getWeapon(int a);

    int getWeaponCount();


    item* getItems();

    int getItemCount();

    int getSmokeBombs();

    bool death();
    
    void gain_life();

    bool reduced_health(int damage);

    void gain_bomb();

    bool use_bomb();

    void add_item(item item);

    void add_weapon(weapon& weapon1);

    bool hasSB();

    void gainHealth(int gain);
};


#endif