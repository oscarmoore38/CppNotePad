#include "notepad.hpp"
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

// Constructor definiton 
NotePad:: NotePad(){}


void NotePad:: run(int argumentCount, char* arguementValue[]){

    // Give user options. 

    // Do some action based on those options
    // 1) open a file 
    // 2) create new file 
    // 3) save file 
    // 4) Edit existing file. 
    bool validInput = false; 
    
    while (!validInput){
        validInput = getUserMenuOption();
    }



};

bool NotePad:: getUserMenuOption(){
    cout << "Welcome to CPPNotePad. Please select an option" << endl;
    cout << "****" << endl;
    cout << "1 - Open file" << endl;
    cout << "2 - Create new file" << endl;
    cout << "3 - Edit exisiting file" << endl;
    cout << "****" << endl;
    
    getline(cin, UserInput);

    if (UserInput != "1" &&  UserInput != "2" && UserInput != "3"){
        cout << "Invalid choice, please choose again" << endl;
        return false;
    }

    return true;
}




