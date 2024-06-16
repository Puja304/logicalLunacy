#include "monster.h"

monster::monster(int monsterLevel){
    level = monsterLevel;
    switch (level)
    {
    case 1:
        name  = "Pain Collector";
        break;
    case 2:
        name = "God's Wrath";
        break;
    default:
        name = "King Lycaon";
        break;
    }
}

int monster::getLevel(){
    return level;
}

string monster::getName(){
    return name;
}

void monster::displayMonster(){
    cout << "Name: " << name << "                                                      Lvl: " << level << endl;
    switch (level)
    {
    case 1:
        cout << "                                             ------                                                  " << endl;
        cout << "                                             |    |                                                   " << endl;
        cout << "                                         --------------                                              " << endl;
        cout << "                                        |              |                                              " << endl;
        cout << "                                         --------------                                                            " << endl;
        cout << "                                         /             \\                                              " << endl;                                                  
        cout << "                                          ____    ____                                                        " << endl;
        cout << "                                         |_*__|  |__*_|                                              " << endl;                                                           
        cout << "                                         --    --    --                                              " << endl;
        cout << "                                       ----    --    ----                                            " << endl;
        cout << "                                      --|--------------|---                                            " << endl;
        cout << "                                            _________                                                           " << endl;
        cout << "                                     --|--| _________ |--|----                                          " << endl;
        cout << "                                      --|--------------|---                                            " << endl;
        cout << "                                       --  --  --  --  --                                            " << endl;
        cout << "                                       | | | | | | | | | |                                                     " << endl;
        cout << "                                       --  --  --  --  --                                            " << endl;
         break;
    
    case 2:
        cout << "              \\                  /" << endl;
        cout << "    _________))                ((__________" << endl;
        cout << "   /.-------./\\\\    \\    /    //\\.--------.\\" << endl;
        cout << "  //#######//##\\\\   ))  ((   //##\\\\########\\\\" << endl;
        cout << " //#######//###((  ((    ))  ))###\\\\########\\\\" << endl;
        cout << "((#######((#####\\\\  \\\\  //  //#####))########))" << endl;
        cout << " \\##' `###\\######\\\\  \\)(/  //######/####' `##/" << endl;
        cout << "  )'    ``#)'  `##\\`->oo<-'/##'  `(#''     `(" << endl;
        cout << "          (       ``\\`..'/''       )" << endl;
        cout << "                     \\\"\"(" << endl;
        cout << "                      `- )" << endl;
        cout << "                      / /" << endl;
        cout << "                     ( /\\" << endl;
        cout << "                     /\\| \\" << endl;
        cout << "                    (  \\" << endl;
        cout << "                        )" << endl;
        cout << "                       /" << endl;
        cout << "                      (" << endl;
        break;

     default:
        cout << R"(
             ,      ,   
            /(.-""-.)\
        |\  \/      \/  /|
        | \ / =.  .= \ / |
        \( \   o\/o   / )/
         \_, '-/  \-' ,_/
           /   \__/   \
           \ \__/\__/ /
         ___\ \|--|/ /___
       /`    \      /    `\
      /       '----'       \
    )";
        break;
    }

        
}

int monster::fight(int weaponLevel, int userHealth, bool hasBomb){
        cout << name << " looks at you and readies for attack" << endl;
        displayMonster();
        if(userHealth <= (level*10)){
            cout << "You die" << endl;
            return -1;
        } else{
            int projected = (health - ((weaponLevel-1) * 15) + (level * 5));
            if (hasBomb){
                cout << "It is halfway through the fight and your health is at "<< userHealth - (level * 10) << " while " << name << "'s health is at "<< projected - (projected%100) << ". Enter c to continue fighting or 'sb' to escape using a smoke bomb" << endl;
                string response;
                bool quitting = false;
                while(true){
                    cin >> response;
                    if (response == "c") {
                        break;
                    } else if (response == "sb") {
                        quitting = true;
                        break;
                    } else{
                        cout << "Command not recognized" << endl;
                    }
                }
                if (quitting){
                    return 0;
                }

            }
            if(userHealth <= level * 10 || ((userHealth - (level * 15) + (level * 5)) < projected)){
                cout << "You die " << endl;
                return -1;
            }
            cout << "You have defeated the monster." << endl;
            defeated = true;
            return level * 20;
        }

    }