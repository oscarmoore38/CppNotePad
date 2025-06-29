#include "notepad.hpp"
#include <iostream>
#include <string> 
#include <vector>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

// Constructor definiton 
NotePad:: NotePad(){
    
}


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
    cout << ">"; 
    
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
        EditFile(); // Come back and change this later. Just placeholder for now. 
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
    cout << "New file name: " << endl; 
    string newFileName; 
    getline(cin, newFileName);

    cout << "Creating new file: " << newFileName << endl; 

    if(!fileOperations.writeFile(dirPathForUserFiles + newFileName)){
        return false; 
    }

    return true; 

}

bool  NotePad:: EditFile(){

    // Check files directory is created 
    try {
        fileOperations.showFiles(dirPathForUserFiles);
    } catch(exception& e){
        cerr << "No such directory exists. Please check file path " << endl;
        return false; 
    }

    // Check if any files exist to edit.  
    int count = fileOperations.getFileCountInDir(dirPathForUserFiles);

    if (count == 0){
        cout << "You have no files in your directory to edit. Please create a file" << endl; 
        CreateNewFile();
        return false; 
    }

    // Check specified file exists: 
    cout << "What file would you like to edit?" << endl; 
    getline(cin, UserFile); 
    string fullPath = dirPathForUserFiles + UserFile;

    while (!filesystem::exists(fullPath)){
        cout << "File: " + fullPath + " not found" << endl; 

        fileOperations.showFiles(dirPathForUserFiles);
        
        cout << "What file would you like to edit?" << endl; 

        getline(cin, UserFile); 

        fullPath = dirPathForUserFiles + UserFile;

    }

    fileOperations.writeFile(fullPath);

    return true; 

}





