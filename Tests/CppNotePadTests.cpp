#include <gtest/gtest.h>
#include "../src/fileOperationsClass/fileOperations.hpp"
#include "../src/notepadClass/notepad.hpp"
#include "string"
#include <filesystem> 
#include <iostream>
#include <sstream> 
#include <fstream> 


using namespace std;
namespace fs = filesystem;


class NotePadTest: public :: testing:: Test {
protected: 
    streambuf* oldCinBuf; 
    streambuf* oldCoutBuf; 
    stringstream testCout; 
    string testFileName = "testFile.txt"; 
    string dirPathForTestFiles = "/workspaces/CppNotePad/Files/";

    void SetUp() override {
        // Save orginal buffers 
        oldCinBuf = cin.rdbuf(); 
        oldCoutBuf = cout.rdbuf(); 

        // Replace cout's output buffer to capture output of program. 
        cout.rdbuf(testCout.rdbuf());
    }

    void TearDown() override {
        cin.rdbuf(oldCinBuf);
        cout.rdbuf(oldCoutBuf);

        // Delete test file. 
        string pathToTestFile = dirPathForTestFiles + testFileName;
        if(!remove(pathToTestFile)){
            cout << "Unable to delete test files" << endl;
        } else{
            cout << "Test files successfully deleted. Testing complete." << endl;
        }

    }

    // Helper for tests to read files
    string readFileContentHelper(const string& fileName){
        ifstream inFile(fileName);

        if (!inFile.is_open()){
            return "";
        }

        stringstream tempOutputBuf; 
        tempOutputBuf << inFile.rdbuf(); 
        return tempOutputBuf.str(); 
    }


};

TEST_F(NotePadTest, CreateNewFile){
    NotePad notePadTestObj; 
    string message = "This is a test for my program using Google Test!\n";

    string input = testFileName + "\n";
    input += message;
    input += "quit\n";

    // Create new stream buffer for cin for test input
    istringstream testCin(input);
    cin.rdbuf(testCin.rdbuf()); 

    // Call function directly
    bool success = notePadTestObj.CreateNewFile();
    
    string pathToTestFile = dirPathForTestFiles + testFileName;
    ASSERT_TRUE(success); 
    ASSERT_TRUE(fs::exists(pathToTestFile));

    // Check file content matches orginal message 
    string testFileContent = readFileContentHelper(pathToTestFile);

    EXPECT_EQ(message, testFileContent);

}


TEST_F(NotePadTest, ReadFIle){
    NotePad notePadTestObj; 
    string message = "This is a test for my program using Google Test!\n";

    string input = testFileName + "\n";
    input += message;
    input += "quit\n";

    // Create new stream buffer for cin for test input
    istringstream readTestCin(input);
    cin.rdbuf(readTestCin.rdbuf()); 

    // Call create new file directly
    bool success = notePadTestObj.CreateNewFile();
    
    string pathToTestFile = dirPathForTestFiles + testFileName;
    ASSERT_TRUE(success); 
    ASSERT_TRUE(fs::exists(pathToTestFile));

    string openFileInput = testFileName + "\n";

    //clear cout buffer of prompts from file create
    testCout.str("");
    testCout.clear();

    istringstream openTestCin(openFileInput);
    cin.rdbuf(openTestCin.rdbuf());

    // Call open file directly. 
    bool openSuccess = notePadTestObj.OpenFiles();
    ASSERT_TRUE(openSuccess); 

    // Compare file content to output of openfile function
    string actualFileContent = readFileContentHelper(pathToTestFile);

    string readFileContent = testCout.str(); 

    // Extract file content from cout buffer. Prompt that preceeds file content is "Opening: /workspaces/CppNotePad/Files/testFile.txt\n." 
    string marker = "Opening: " + pathToTestFile + "\n";
    size_t markerPos = readFileContent.find(marker);

     // Assert that the marker was actually found in the output. Useful if prompts change. 
    ASSERT_NE(markerPos, string:: npos);

    // Extract substring
    size_t contentStartPos = markerPos + marker.length();
    string extractedFileContent = readFileContent.substr(contentStartPos);

    EXPECT_EQ(actualFileContent, extractedFileContent);

}