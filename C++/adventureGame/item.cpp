#include "item.h"
#include "play.h"


item::item(){
    name = "unnamed";
}

item::item(string itemName){
    name = itemName;
}

string item::interact(){
    return interactionFunction(*this);
}

void item::setInteract(string (*interaction)(item& rn)){
    interactionFunction = interaction;
}

string item::waterIt(item& something){
    cout << "You water the plant. It looks happy in the sunlight." << endl;
    return "";
}

string  item::getName(){
    return name;
}

bool item::isSolved(){
    return solved;
}

void item::solveIt(){
    solved = true;
}

string item::digitCode(item& something){
       if(something.isSolved() == true){
        cout << "You see an empty chest on the dresser." << endl;
        return "";
        exit;
       }
       cout << "The dresser has a pale golden chest on it, its color blackened with age and its paint chipped in more places than not. You try to open the chest, but find it locked. Upon closer"
       " examination, you see it has three little dials to input a code. Enter a code to try and open it, or enter 'x' to stop interacting with it" << endl;
        int code = 430;
        string user_code;
        while(true){
            try
            {   
                cin >> user_code;
                int code_num = stoi(user_code);
                if(code_num == code){
                    cout << "Congrats! You found a key!" << endl;
                    something.solveIt();
                    break;

                } else if(code_num != code){
                    cout << "Try again" << endl;
                }

            }
            catch(const std::exception& e)
            {
                if(user_code == "exit"){
                    return "";
                    exit;
                } else if(user_code == "x"){
                    break;
                } else {
                    cout << "Remember : the code is fully numeric" << endl;
                }
            }
            
        }
        return "";
   
}

string item::foundSword(item& something){
    if (something.isSolved()){
        cout << "There is nothing to do anynore" << endl;
        return "";
    } else{
        cout << "You just discovered a new weapon" << endl;
        something.solveIt();
        return "sword";
    }
}


string item::foundRifle(item& something){
    if (something.isSolved()){
        cout << "There is nothing to do anynore" << endl;
        return "";
    } else{
        cout << "You just discovered a new weapon" << endl;
        something.solveIt();
        return "rifle";
    }
}

string item::foundScythe(item& something){
    if (something.isSolved()){
        cout << "There is nothing to do anynore" << endl;
        return "";
    } else{
        cout << "You just discovered a new weapon" << endl;
        something.solveIt();
        return "scythe";
    }
}

string item::foundSB(item& something){
    if (something.isSolved()){
        cout << "There is nothing to do anynore" << endl;
        return "";
    } else{
        cout << "You just discovered a new weapon" << endl;
        something.solveIt();
        return "sb";
    }
}

string item::foundKey1(item& something){
    if (something.isSolved()){
        cout << "There is nothing to do anynore" << endl;
        return "";
    } else{
        cout << "You just discovered a new weapon" << endl;
        something.solveIt();
        return "key1";
    }
}

string item::foundKey4(item& something){
    if (something.isSolved()){
        cout << "There is nothing to do anynore" << endl;
        return "";
    } else{
        cout << "You just discovered a new weapon" << endl;
        something.solveIt();
        return "key4";
    }
}

string item::foundKey8(item& something){
    if (something.isSolved()){
        cout << "There is nothing to do anynore" << endl;
        return "";
    } else{
        cout << "You just discovered a new weapon" << endl;
        something.solveIt();
        return "key8";
    }
}

string item::deskNotebook(item& something){
    cout << "You take a tentative step towards the desk, the rotten wood under your feet creaking with every step. You stand over the dust-covered piece of furniture, unwilling"
    "to touch anything, when you notice a drawer sticking out at the bottom, slightly open. You open the drawer to find a notebook. DR. JACE MONROE it says, "
    "in a big, messy scrawl on the top of the notebook. You open it and find a few numbers written and scratched out. It looks like someone was trying to "
    "crack a code." << endl;

    cout << "2 0 6   --> 1, wrong" << endl;
    cout << "0 1 4   --> 2, wrong" << endl;
    cout << "1 3 7   --> 1, correct" << endl;
    cout << "5 4 9   --> 1, wrong" << endl;
    cout << "9 2 1   --> 0" << endl;
    

    cout << "You are unsure what the keywords mean exactly, but they probably indicate the number of values that exist in the actual code and how many are"
    "correctly places in that attempt." << endl;

    return "";
}



