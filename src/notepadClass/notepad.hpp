#ifndef NOTEPAD_HPP
#define NOTEPAD_HPP

#include <string>
#include <vector> 
#include "../fileOperationsClass/fileOperations.hpp"



using namespace std; 

/**
 * @class NotePad
 * @brief Class orchestrator for notepad program
 * 
 */
class NotePad{

private:
    // Objects 
    // ReadUserInput
    // SaveUserInput
    // EditFile 
    // LoadFile
    // FileGUI (stretch)
    string dirPathForUserFiles = "/workspaces/CppNotePad/Files/";

    // Attributes 
    FileOperations fileOperations;
    // FileGUI fileGUI; 
    string UserInput;
    string UserFile; 

public: 
    /** 
     * @brief Constructor for NotePad class 
     * @note Takes no params 
     */ 
    NotePad(); 

    /** 
     * @brief Runs the notePad program
     * @param arguementCount The total count of arguements passed to program. 
     * @param arguementValue The values of the arguments passed to program
     * @return Void
     */ 
    void run(int argumentCount, char* argumentValue[]);

    /** 
     * @brief Prints CLI prompt for user to collect choice. Will return true if valid choice, false otherwise. 
     * @note No params
     * @return bool 
     */ 
    bool UserMenuOption();


     /** 
     * @brief Opens file at target directory  
     * @note No params
     * @return bool 
     */ 
    bool OpenFiles();


    /** 
     * @brief Edits file at target directory  
     * @param filePath The path to the file to edit. 
     * @return bool 
     */ 
    bool EditFile();

    /** 
     * @brief Creates new file at target directory 
     * @note No params
     * @return bool 
     */ 
    bool CreateNewFile();



};

#endif