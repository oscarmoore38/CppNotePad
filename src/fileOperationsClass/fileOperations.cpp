#include "fileOperations.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cerrno> 
#include <cstring>
#include <filesystem>

using namespace std; 
using namespace std::filesystem;


FileOperations:: FileOperations(){
    if (!FileDirCreated){
        filesystem::path currentPath = filesystem::current_path();

        if (!findRootPath(currentPath)){
            cerr << "Error: issue locating root directory. 'Files' directory not created. Please create manually in root" << endl; 
            return;
        }

        targetDirectory /= "Files";
        
        // Attempt to create the output directory. 
        try {
            filesystem::create_directories(targetDirectory);
        } catch (const filesystem::filesystem_error& e) {
            std::cerr << "Filesystem Error: " << e.what() << std::endl;
            std::cerr << "Path attempted: " << targetDirectory << std::endl;
        }

        FileDirCreated = true; 

    }
}

bool FileOperations:: readFile(const string& userFile){
    cout << "Opening: " << userFile << endl; 
    InputFile.open(userFile);

    if (!InputFile.is_open()){
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
    string pathToFile;
    string fileNameOnly;
    for (const auto & entry : directory_iterator(dirPath)){
        // Print just file not abs path. 
        pathToFile = entry.path();
        size_t pos = pathToFile.rfind("/");
        fileNameOnly = pathToFile.substr(pos+1);
        cout << "-- " << fileNameOnly << endl;
    }

}

int FileOperations:: getFileCountInDir(const string& dirPath){
    int count; 
    for (const auto & entry: directory_iterator(dirPath)){
        count ++; 
    }

    return count; 
}

bool FileOperations:: writeFile(const string& fileName){
    ofstream outFile; 
    string userInput; 
    outFile.open(fileName);

    if (outFile.is_open()){
        cout << "Enter lines of text to write to " <<fileName << endl; 
        cout << "Type 'quit' or 'q' on a newline when done" <<endl; 
        cout << "--------------------------------------------------" << endl; 

        for (;;){
            cout << ">"; 
            getline(cin, userInput); 

            if (userInput == "quit" || userInput == "q"){
                break; 
            }

            outFile << userInput << endl; 
        }


        outFile.close();
        std::cout << "\n---------------------------------------------------------" << std::endl;
        std::cout << "Content written to '" << fileName << "' and file closed." << std::endl;

    } else {
        return false; 
    }

    return true; 

}

bool FileOperations:: findRootPath(path& curWorkingDir){
    filesystem:: path pathToTargetFile = curWorkingDir / "CMakeLists.txt"; 

    // Check if it exists in current dir
    if (filesystem:: exists(pathToTargetFile)){
        targetDirectory = curWorkingDir; 
        return true;
    } 

    // Check if current filePath has a parent file before recursive call. 
    if (!curWorkingDir.has_parent_path()){
        return false; 
    }

    curWorkingDir = curWorkingDir.parent_path();

    return findRootPath(curWorkingDir);

}