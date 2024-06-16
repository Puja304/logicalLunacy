#include "character.h"
using namespace std;

    character::character(){
        health = 100;
        lives = 3;
        smoke_bombs = 1;
        weapons = new weapon[4];
    }
    

    character::~character(){
        delete[] weapons;
    }

    int character::gethealth(){
        return health;
    }

    int character::getLives(){
        return lives;
    }

    weapon character::getWeapon(int a){
        return weapons[a];
    }

    int character::getWeaponCount(){
        return weapon_count;
    }


    item* character::getItems(){
        return items;
    }

    int character::getItemCount(){
        return item_count;
    }

    int character::getSmokeBombs(){
        return smoke_bombs;
    }

    bool character::death(){
        lives -= 1;
        if(lives == 0){
            alive = false;
        }
        health = 100;
        return alive;
    }
    
    void character::gain_life(){
        lives += 1;
    }

    bool character::reduced_health(int damage){
        health -= damage;
        if(health > 0){
            return true;
        } else{
            return false;
        }
    }

    void character::gain_bomb(){
        smoke_bombs ++;
    }

    bool character::use_bomb(){
        if(smoke_bombs >= 1){
             smoke_bombs--;
             return true;
        }
        else{
            return false;
        }
       
    }

    void character::add_item(item item){
        items[item_count++] = item;

    }

    void character::add_weapon(weapon& weapon1){
        weapons[weapon_count++] = weapon1;
    }

    bool character::hasSB(){
        return smoke_bombs >= 1;
    }

    void character::gainHealth(int gain){
        health += gain;
    }

