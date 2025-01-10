#ifndef NOTEPAD_HPP
#define NOTEPAD_HPP

#include <string>
#include <vector> 


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

    // Attributes 
    // ReadUserInput readUserInput; 
    // SaveUserInput saveUserInput; 
    // EditFile editUserInput; 
    // LoadFile loadUserInput; 
    // FileGUI fileGUI; 
    string UserInput;

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
     * @brief Prints CLI prompt for user
     * @note No params
     * @return bool 
     */ 
    bool getUserMenuOption();



};

#endif