#include "weapon.h"

weapon::weapon(){
    level = 0;
    name = "random";
    description = "";
}

weapon::weapon(int wLevel){
        switch (wLevel)
        {
        case 0:
            level = 0;
            name = "Smoke Bomb";
            description = "A bomb that blinds the enemies and give you time to escape";
            break;
        case 1:
            level = 1;
            name = "The Sword of Sorrows";
            description = "A gleaming sword studded with blood red rubies";
            break;

        case 2:
            level = 2;
            name = "Rey's Rifle";
            description = "A lethally stunning rifle whose bullets pierce straight through the bone";

        default:
            level = 3;
            name = "The Hunter's Scythe";
            description = "The weapon that makes it owner the grim reaper for a all things supernatural : a razor sharp scythe coated in a lethal dose of wolfsbane";
            break;
        }
    }   

void weapon::acquisition(){
        acquired = true;
    }
