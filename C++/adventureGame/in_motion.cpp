#include "play.h"
//#include <cstdlib>

int main(void) {
    play firstGame;
    firstGame.lore();
    string response  = "";
    while(true){
        cin >> response;
        if (response == "p"){
            firstGame.map_printer();
            cout << "You are by the front door of the building. You can only exit from the end of the building, the door to which is locked. You must find the exit key before the infected catch up. You can move back and forth in the hallway and "
            "enter and exit rooms. Within rooms, you can interact with objects and collect items such as keys. To see where you are, you have access to a map. You also have an inventory of weapons"
            " which you may use. Here is a list of commands (enter 'help while in the hallway to view these again') : " << endl;
            firstGame.helpCommnads();
            break;
        } else if (response == "exit"){
            exit;
        }
        else{
            cout << "Sorry, I do not understand" << endl;
        }
    }
    while(true){
        if(firstGame.gamer.getLives() == 0){
            break;
        }
        cin >> response;
        area* currentArea = firstGame.getArea();
        if(response == "d"){
            firstGame.move_forward();
        }
        else if (response == "a"){
            firstGame.go_back();
        } else if(response == "w"){
            firstGame.enterRoom();
        }else if (response == "s"){
            firstGame.exitRoom();
        }else if (response == "map" || response == "m"){
            firstGame.map_printer();
        } 
        else if (response == "exit"){
            break;
        }else if(response == "help"){
            firstGame.helpCommnads();
        }else if (currentArea->isRoom()){
            int count = 0;
            for (int i = 0; i < 3; i++){
                if(currentArea->objects[i].getName() == response){
                    count -- ;
                    string potentialAcquisition  = currentArea->objects[i].interact();
                    if(potentialAcquisition == "sb"){
                        firstGame.gamer.gain_bomb();
                    } else if (potentialAcquisition == "sword"){
                        weapon* sword = new weapon(1);
                        firstGame.gamer.add_weapon(*sword);
                    } else if(potentialAcquisition == "rifle"){
                        weapon* rifle = new weapon(2);
                        firstGame.gamer.add_weapon(*rifle);
                    } else if (potentialAcquisition == "scythe"){
                        weapon* scythe = new weapon(3);
                        firstGame.gamer.add_weapon(*scythe);
                    } else if (potentialAcquisition == "key1"){
                        firstGame.unlock(1);
                    } else if (potentialAcquisition == "key4"){
                        firstGame.unlock(4);
                    } else if (potentialAcquisition == "key8"){
                        firstGame.unlock(8);
                    }
                }
                count++;
            }
            if (count == 3) {
                cout << "Cannot interact with: " << response << endl;
            }
        }
        else{
            cout << "I'm sorry, I do not understand. Enter 'help' if to see a list of all valid commands." << endl;
        }
    }
    return 0;
}


//to do:
// 9 room descriptions
// 19 items -- non-key and non-weapon. 4 will be riddles, and 4 clues for it. so 8 done. will have to think about the rest. one is an invisibility cloak

//done:
// 8 items
// 3 monsters
// 1 battle
// 4 weapons
