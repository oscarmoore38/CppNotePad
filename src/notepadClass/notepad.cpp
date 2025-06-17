#include "notepad.hpp"
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

// Constructor definiton 
NotePad:: NotePad(){}


void NotePad:: run(int argumentCount, char* arguementValue[]){  
    cout << "--------------------------------------------------------------------------------------------------------------"  << endl; 
    cout <<  "Welcome to CPPNotePad. Please select a menu option. You can close the program at any time by using 'Ctrl + C'" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------"  << endl; 
    cout << '\n' << endl; 
    
    
    for (;;){
        if(!UserMenuOption()){
            cout << "Invalid choice, please choose option 1, 2, or 3" << endl;
        }
    }

};

bool NotePad:: UserMenuOption(){
    cout << "****"  << endl; 
    cout << "Menu" << endl;
    cout << "****" << endl;
    cout << "Press 1 - Open file" << endl;
    cout << "Press 2 - Create new file" << endl;
    cout << "Press 3 - Edit exisiting file" << endl;
    cout << "****" << endl;
    
    getline(cin, UserInput);

    if (UserInput != "1" &&  UserInput != "2" && UserInput != "3"){
        return false;
    }

    if (UserInput == "1"){
        OpenFiles();
    }

    else if(UserInput == "2"){
        CreateNewFile(); 
    }
    else {
        EditFile(UserFile); // Come back and change this later. Just placeholder for now. 
    }

    return true;
}

bool NotePad:: OpenFiles(){

     // Check valid directory 
    try {
        fileOperations.showFiles(dirPathForUserFiles);
    } catch(exception& e){
        cerr << "No such directory exists. Please check file path " << endl;
        return false; 
    }

    // Check if any files exist. 
    int count = fileOperations.getFileCountInDir(dirPathForUserFiles);

    if (count == 0){
        cout << "You have no files in your directory to open. Please create a file" << endl; 
        CreateNewFile();
        return false; 
    }
    

    cout << "What file would you like to open?" << endl; 

    getline(cin, UserFile); 

    string fullPath = dirPathForUserFiles + UserFile;

    fileOperations.readFile(fullPath);

    return true; 

}

bool  NotePad:: CreateNewFile(){

}

bool  NotePad:: EditFile(const string& filename ){
    
}





