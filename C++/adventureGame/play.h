#ifndef PLAY_H
#define PLAY_H

#include <iostream>
//#include <cstring>
#include "area.h"
#include "item.h"
#include "monster.h"
#include "character.h"

using namespace std;


class play {
    private:
    char mainMap[40][120];
    int currentPosition = 0;
    area* locations[20];
    
    public:
    character gamer;
    //constructor:
    //
    play();

    //
    ~play();

    //
    void rc_converter(char roc, int rcn, int beg, int end, char charac);

    //
    void room_creator(int x, int y);

    //
    void map_printer();

    //
    void updatePosition(int a);

    //
    void move_forward();

    //
    void go_back();

    //
    void enterRoom();

    void exitRoom();

    bool point_0();

    bool point_half();

    bool point_1();

    //
    void display_stats();

    area* getArea();

    int getCurrentPosition();

    void helpCommnads();

    void unlock(int a);

    void lore();
};


#endif