#include "notepad.hpp"
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

// Constructor definiton 
NotePad:: NotePad(){}


void NotePad:: run(int argumentCount, char* arguementValue[]){

    cout << "Program" << arguementValue[0] << " running. Please CTRL + C to stop" << endl;

};

