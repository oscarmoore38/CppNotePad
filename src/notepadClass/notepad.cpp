#include "notepad.hpp"
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

// Constructor definiton 
NotePad:: NotePad(){}


void NotePad:: run(int argumentCount, char* arguementValue[]){

    bool validInput = false; 
    
    while (!validInput){
        validInput = getUserMenuOption();
    }

    if (UserInput == "1"){
        // Check valid file
        cout << "What file would you like to open?" << endl; 

        fileOperations.showFiles(dirPathForUserFiles);

        getline(cin, UserFile); 

        string fullPath = dirPathForUserFiles + UserFile;

        fileOperations.readFile(fullPath);
        
    }



};

bool NotePad:: getUserMenuOption(){
    cout << "***"  << endl; 
    cout << "Welcome to CPPNotePad. Please select an option" << endl;
    cout << "****" << endl;
    cout << "1 - Open file" << endl;
    cout << "2 - Create new file" << endl;
    cout << "3 - Edit exisiting file" << endl;
    cout << "****" << endl;
    
    getline(cin, UserInput);

    if (UserInput != "1" &&  UserInput != "2" && UserInput != "3"){
        cout << "Invalid choice, please choose option 1, 2, or 3" << endl;
        return false;
    }

    return true;
}




