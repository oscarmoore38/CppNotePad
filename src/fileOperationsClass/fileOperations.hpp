#ifndef FILEOPERATIONS_HPP
#define FILEOPERATIONS_HPP

#include <string>
#include <vector> 
#include <fstream>
#include <filesystem>

using namespace std; 
using namespace std::filesystem;

/**
 * @class FileOperations
 * @brief Handles all operations on user files.
 * 
 */

class FileOperations{

    private: 
        ifstream InputFile;
        filesystem:: path targetDirectory; 
        bool FileDirCreated; 


    public: 
        /** 
         * @brief Constructor for NotePad class 
         * @param DirName Desired name for directory to store program files. 
         */ 
        FileOperations();

        /** 
         * @brief Reads content of file to command line. If file not found, then prints error. 
         * @param userFile The file a user wants to read
         * @return Bool  
         */ 
        bool readFile(const string& userFile);

        /** 
         * @brief Shows files a user has saved 
         * @param dirPath The path to the directory that holds userFiles 
         * @return Void  
         */ 
        void showFiles(const string& dirPath);

         /** 
         * @brief Counts files in a directory and returns count. 
         * @param dirPath The path to the directory that holds userFiles 
         * @return int   
         */ 
        int getFileCountInDir(const string& dirPath);

         /** 
         * @brief Creates a new file  
         * @param fileName name of new file to create.  
         * @return bool   
         */ 
        bool writeFile (const string& fileName);

        /** 
         * @brief Recursively finds the root directory by searching for the marker file "CMakeLists.txt" in root. 
         * @param curWorkingDir current working directory. 
         * @return bool value if able to locate root. 
         */ 
        bool findRootPath (path& curWorkingDir);

};


#endif