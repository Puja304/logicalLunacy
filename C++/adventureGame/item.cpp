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

string item::playIt(item& something){
    cout << "You played the piano" << endl;
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
        cout << "You see an empty box" << endl;
        return "";
        exit;
       }
        int code = 8312;
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





