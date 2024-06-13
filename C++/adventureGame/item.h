#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class item{
    private:
    string (*interactionFunction)(item& current);
    string name;
    bool solved = false;

    public:
 
    item();

    item(string itemName);

    void setInteract(string (*interaction)(item& rn));

    string interact();

    string getName();

    bool isSolved();

    void solveIt();

    //each individual interaction function

    static string playIt(item& something);

    static string digitCode(item& something);

    static string foundSword(item& something);

    static string foundRifle(item& something);

    static string foundScythe(item& something);

    static string foundSB(item& something);

    static string foundKey1(item& something);

    static string foundKey4(item& something);

    static string foundKey8(item& something);
};


#endif

