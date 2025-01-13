#include "fileOperations.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cerrno> 
#include <cstring>
#include <filesystem>

using namespace std; 
using namespace std::filesystem;


FileOperations:: FileOperations(){}

bool FileOperations:: readFile(const string& userFile){

    cout << "Opening: " << userFile << endl; 
    InputFile.open(userFile);

    if (!InputFile.is_open()){
        cerr << "Error: Failed to open file " << userFile << ".";

        if (errno != 0) {
            cerr << " Reason: " << strerror(errno) << endl;
        } else {
            cerr << "Please check if the file exists and you have the correct permissions." << endl;
        }

        return false;
    }

    string line; 

    while(getline(InputFile, line)){
        cout << line << endl; 
    }

    InputFile.close();

    return true;

}

void FileOperations:: showFiles(const string& dirPath){
    cout << "Current saved files:" << endl;
    for (const auto & entry : directory_iterator(dirPath))
        cout << entry.path() << endl;

}