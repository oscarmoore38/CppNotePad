#ifndef FILEOPERATIONS_HPP
#define FILEOPERATIONS_HPP

#include <string>
#include <vector> 
#include <fstream>

using namespace std; 

/**
 * @class FileOperations
 * @brief Handles all operations on user files.
 * 
 */

class FileOperations{

    private: 
        ifstream InputFile;


    public: 
        /** 
         * @brief Constructor for NotePad class 
         * @note Takes no params 
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


};


#endif