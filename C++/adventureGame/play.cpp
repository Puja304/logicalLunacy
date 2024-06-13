#include "play.h"


play::play(){
        for(int i = 0; i < 40; i++){
            for(int j = 0; j< 120; j++){
                mainMap[i][j] = ' ';
            }
    }

    rc_converter('r', 0, 0, 119, '-');
    rc_converter('r', 39, 0, 119, '-');
    rc_converter('c', 0, 0, 39, '|');
    rc_converter('c', 119, 0 , 39, '|');

    room_creator( 5,20);
    room_creator( 5,40);
    room_creator( 5,60);
    room_creator( 10,100);
    room_creator( 18,30);
    room_creator( 18,55);
    room_creator( 26,105);
    room_creator( 29,15);
    room_creator( 29,55);


    rc_converter( 'r',35,0, 92, '-');
    rc_converter( 'r',38,0, 98, '-');

    rc_converter( 'c',92,27, 35, '|');
    rc_converter( 'c',98,24, 38, '|');

    rc_converter( 'r',24,20, 98, '-');
    rc_converter( 'r',27,12, 92, '-');
    
    rc_converter( 'c',20,15, 24, '|');
    rc_converter( 'c',12,12, 27, '|');

    rc_converter( 'r',12,12, 85, '-');
    rc_converter( 'r',15,20, 92, '-');

    rc_converter( 'c',85,4, 12, '|');
    rc_converter( 'c',92,1, 15, '|');

    rc_converter( 'r',4,0, 85, '-');
    rc_converter( 'r',1,0, 92, '-');

    locations[0] = new area(37,5);
    locations[0]->addDescription("You are at the front door");

    locations[1]  = new area{37,20};
    locations[1]->addDescription("You are outside room 1");

    locations[2] = new area{37,60};
    locations[2]->addDescription("You are outside room 2");

    locations[3] = new area{29, 95};
    locations[3]->addDescription("You are outside room 3");

    locations[4] = new area{26, 59};
    locations[4]->addDescription("You are outside room 4");

    locations[5] = new area{26, 34};
    locations[5]->addDescription("You are outside room 5");

    locations[6] = new area{13,87};
    locations[6]->addDescription("You are outside room 6");

    locations[7] = new area{3, 64};
    locations[7]->addDescription("You are outside room 7");

    locations[8] = new area{3, 44};
    locations[8]->addDescription("You are outside room 8");

    locations[9] = new area{3,24};
    locations[9]->addDescription("You are outside room 9");

    locations[10] = new area{3, 3};
    locations[10]->addDescription("You are at the aexit door");

    item object1 ("piano");
    object1.setInteract(item::playIt);
    item object2("plant");
    object2.setInteract(item::playIt);
    item object3 ("sofa");
    object3.setInteract(item::playIt);

    item objectDC ("box");
    objectDC.setInteract(item::digitCode);

    item objectWT ("wall");
    objectWT.setInteract(item::foundSword);

    locations[11] = new area{31,20,true, object1, object2, object3};
    locations[12] = new area{31,60,false, object1, object2, objectDC};
    locations[13] = new area{29,108,false, 3, object1, object2, object3};
    locations[14] = new area{20, 59,true, object1, object2, object3};
    locations[15] = new area{20, 34,false, 1, object1, object2, object3};
    locations[16] = new area{13,103,false, object1, object2, object3};
    locations[17] = new area{6,64,false, 2, object1, object2, object3};
    locations[18] = new area{6, 44,true, object1, object2, object3};
    locations[19] = new area{6,24,false, object1, object2, objectWT};

    locations[11]->addDescription("This is room 1");
    locations[12]->addDescription("This is room 2");
    locations[13]->addDescription("This is room 3");
    locations[14]->addDescription("This is room 4");
    locations[15]->addDescription("This is room 5");
    locations[16]->addDescription("This is room 6");
    locations[17]->addDescription("This is room 7");
    locations[18]->addDescription("This is room 8");
    locations[19]->addDescription("This is room 9");
}

void play::rc_converter(char roc, int rcn, int beg, int end, char charac){
    if(roc == 'r'){
        for(int i = beg; i < end; i++){
            mainMap[rcn][i] = charac;
        }
    } else{
        for(int i = 1+beg; i < end; i++){
            mainMap[i][rcn] = charac;
        }
    }
}


void play::room_creator(int x, int y){
    rc_converter('r',x, y+1, y+7,'_' );
    rc_converter('r', x+4,  y+1, y+7,'_' );
    rc_converter('c',y, x, x+5, '|');
    rc_converter('c',y+7, x, x+5, '|');
}

void play::map_printer(){
    display_stats();
    for(int i = 0; i < 120; i++){
        cout << mainMap[0][i];
    }
    cout<< endl;
    for(int i = 1; i < 40; i++){
        for(int j = 0; j< 120; j++){
            cout << mainMap[i][j];
        }
        cout << endl;
    }   
}

void play::display_stats(){
    cout << endl << endl << endl << endl;
    cout << "Lives: " << gamer.getLives() <<"    Health:" << gamer.gethealth() << "                                                     Menu: " << endl;
    cout << "                                                                            Map" << endl;
    cout << "                                                                          Weapons" << endl;
    cout << "                                                                         Inventory" << endl;
    cout << endl << endl;
}

void play::updatePosition(int a){
    mainMap[locations[currentPosition]->getX()][locations[currentPosition]->gety()] = ' ';
    mainMap[locations[a]->getX()][locations[a]->gety()] = '*';
    cout << locations[a]->getDescription() << endl;
}

void play::move_forward(){
    if (currentPosition < 10){
        updatePosition (currentPosition + 1);
        currentPosition += 1;
    } else if (currentPosition == 10){
        cout << "You have reached the exit gate. You need a key to leave." << endl;
    } else{
        cout << "You are inside a room. Please exit before you can move forward or back" << endl;
    }
}

void play::go_back(){
    if(currentPosition <= 10 && currentPosition > 0 ){
        updatePosition(currentPosition - 1);
        currentPosition -= 1;
    } else if (currentPosition == 0){
        cout << "You are at the front door. You cannot move backwards." << endl;
    } else{
        cout << "You are inside a room. Please exit before you can move forward or back" << endl;
    }
}

void play::enterRoom(){
    if(currentPosition < 10 && !locations[currentPosition+10]->isLocked()){
           updatePosition(currentPosition + 10);
           currentPosition += 10;
           area* currentArea = getArea();
           if (currentArea->hasMonster()){
            monster* monstr = currentArea->getMonster();
            if(!monstr->isDefeated()){
                int result = monstr->fight(gamer.getWeaponCount(), gamer.gethealth(), gamer.hasSB());
                if (result == -1){
                    gamer.death();
                    exitRoom();
                } else if (result == 0){
                    gamer.use_bomb();
                    gamer.reduced_health(10 * monstr->getLevel());
                    exitRoom();
                } else{
                    gamer.reduced_health(result);
                }
            } else{
                exit;
            }
           }
    }
    else if(currentPosition < 10 && locations[currentPosition+10]->isLocked()){
        cout << "Sorry, the room is locked. Find a key to enter it." << endl;
    }
    else{
        cout << "You are not close to a room" << endl;
    }

}

void play::exitRoom(){
    if(currentPosition > 10){
        updatePosition(currentPosition - 10);
        currentPosition -= 10;
    } else{
        cout << "You must enter a room in order to exit it" << endl;
    }

}


play::~play(){
    for(int i = 0; i < 20; i++){
        delete locations[i];
    }
}

area* play::getArea(){
    return locations[currentPosition];
}

int play::getCurrentPosition(){
    return currentPosition;
}


void play::helpCommnads(){
    cout << R"(d : move forward (hallway only)
    a: go back (hallway only)
    w: enter room
    s: exit room
    x: stop interacting with an item
    exit: end game
    m or map : view map (your location = *)
    i or inventory: view inventory
    sb : throw smoke bomb (only valid during a fight);
     )";
}

void play::lore(){
    cout << "\nWelcome to Derelict Nightmares. Your name is Volchitsa Okhotnik and you are humanity's last hope.\n\nIt all began 3 months ago, when King Lycaon of the Werewolves, in a greedy frenzy for more people, attempted to engineer a virus that turned " 
    "humans into werewolves. Only he failed, and unleashed something far more sinsiter into the world. The infected slowly went mad with rage, turning less and "
    "less human with each passing day. They became exceedingly picky eaters, finding fewr thibg edible from one day to the next, until the only "
    "thing that could satiate them was the flesh of those around them. One bite was all it took to spread the virus onto their victim. The worst part," 
    "however, was the mind control. The werewold blood in the virus made the infected susceptible to mind-control by the Lycaon and his people, giving him "
    "a growing army of immortal slaves. The slave-master connection is what keeps the infected 'alive'\n\nThe werewolves are high on power, but there are a select few in their ranks who question the morality of their actions. These wolves, condemned "
    "as 'traitors' by their King, have banded together to help the humans. They seek hiddens groups of people, like yourself and your familiy, and take them"
    " to known safe spaces. You were journeying with them when you found out the likely location of the King Lycaon, and learnt that killing him would"
    " sever werewolves' connection with all of the enslaved infected, turning them immobile. You were attacked shortly afrer, and watched you family get"
    " torn to pieces as you escaped by a thread. You now stand in before the building King Lycaon is rumored to be in, with an army of the infected not far"
    " behind. Your sole bit of luck comes from the King's paranoid distrust translating into a werewolf-less protection detail. He does, however, get a little"
    " enchanted help. You must defeat the King and exit the building before either the infected find you or his loyal wolves come running at the death of "
    "their King. Good Luck.\n\n Enter 'p' to begin playing" << endl;
}

void play::unlock(int a){
    locations[a + 10]->key_Found();
}