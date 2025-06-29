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

    // --- Phase 1: Prepare simulated user input ---
    string input = testFileName + "\n"; 
    input += message;                   
    input += "quit\n";                  

    // Redirect cin to use the prepared input
    istringstream testCin(input);
    cin.rdbuf(testCin.rdbuf());

    // --- Phase 2: Execute CreateNewFile ---
    ASSERT_TRUE(notePadTestObj.CreateNewFile());

    // --- Phase 3: Check file exists ---
    string pathToTestFile = dirPathForTestFiles + testFileName;
    ASSERT_TRUE(fs::exists(pathToTestFile));

    // --- Phase 4: Check file content matches input ---
    string testFileContent = readFileContentHelper(pathToTestFile);
    EXPECT_EQ(message, testFileContent) << "Created file content does not match expected message.";
}


TEST_F(NotePadTest, ReadFile){
    NotePad notePadTestObj;
    string message = "This is a test for my program using Google Test!\n";

    // --- Phase 1: Setup - Create a file to be read ---
    string createFileInput = testFileName + "\n";
    createFileInput += message;
    createFileInput += "quit\n";
    istringstream createTestCin(createFileInput);
    cin.rdbuf(createTestCin.rdbuf());
    ASSERT_TRUE(notePadTestObj.CreateNewFile());

    string pathToTestFile = dirPathForTestFiles + testFileName;
    ASSERT_TRUE(fs::exists(pathToTestFile));

    // --- Phase 2: Prepare for OpenFiles execution ---
    // Clear testCout to remove output from the CreateNewFile setup phase.
    testCout.str("");
    testCout.clear();

    // Prepare input for OpenFiles.
    string openFileInput = testFileName + "\n";
    istringstream openTestCin(openFileInput);
    cin.rdbuf(openTestCin.rdbuf());

    // --- Phase 3: Execute OpenFiles ---
    ASSERT_TRUE(notePadTestObj.OpenFiles());

    // --- Phase 4: Verify captured output ---
    string actualFileContent = readFileContentHelper(pathToTestFile);
    string capturedOpenFileOutput = testCout.str();

    // Define marker string that precedes actual file content in captured output.
    string marker = "Opening: " + pathToTestFile + "\n";
    size_t markerPos = capturedOpenFileOutput.find(marker);

    // Assert marker is found, then extract content for comparison.
    ASSERT_NE(markerPos, string::npos);
    string extractedFileContent = capturedOpenFileOutput.substr(markerPos + marker.length());

    // Compare extracted output with the actual file content.
    EXPECT_EQ(actualFileContent, extractedFileContent);

}

TEST_F(NotePadTest, EditFile){
    cerr << "DEBUG: TEST_F EditFile started." << endl;

    NotePad notePadTestObj;
    string message = "This is a test for my program using Google Test!\n";
    string updatedMessage = "I've updated my program with a new message\n"; // Ensure consistent newlines

    // --- Phase 1: Create the initial file ---
    string createInput = testFileName + "\n";
    createInput += message;
    createInput += "quit\n";

    istringstream createTestCin(createInput); // Dedicated stream for creation
    cin.rdbuf(createTestCin.rdbuf());

    cerr << "DEBUG: Calling CreateNewFile for initial setup." << endl;
    bool success = notePadTestObj.CreateNewFile();
    string pathToTestFile = dirPathForTestFiles + testFileName;
    ASSERT_TRUE(success) << "Initial file creation failed.";
    ASSERT_TRUE(fs::exists(pathToTestFile)) << "Initial file does not exist after creation.";
    cerr << "DEBUG: Initial file created." << endl;

    // --- Phase 2: Verify initial file content 
    // Clear cout buffer of prompts from file creation
    testCout.str("");
    testCout.clear();

    string openOriginalFileInput = testFileName + "\n";
    istringstream openOriginalTestCin(openOriginalFileInput); // Dedicated stream for initial open
    cin.rdbuf(openOriginalTestCin.rdbuf());

    cerr << "DEBUG: Calling OpenFiles to verify initial content." << endl;
    bool openSuccess = notePadTestObj.OpenFiles();
    ASSERT_TRUE(openSuccess) << "Initial file opening for verification failed.";

    string actualFileContent = readFileContentHelper(pathToTestFile); // Reads directly from file
    string capturedOriginalOpenOutput = testCout.str(); // Captured output from OpenFiles()

    string marker = "Opening: " + pathToTestFile + "\n";
    size_t markerPosOriginal = capturedOriginalOpenOutput.find(marker); 

    ASSERT_NE(markerPosOriginal, string::npos);
    string extractedOriginalFileContent = capturedOriginalOpenOutput.substr(markerPosOriginal + marker.length());

    EXPECT_EQ(actualFileContent, extractedOriginalFileContent) << "Initial file content verification mismatch.";
    cerr << "DEBUG: Initial file content verified successfully." << endl;

    // --- Phase 3: Edit the file ---
    // Prepare input for EditFile: filename to edit, new content, and quit signal
    string editInput = testFileName + "\n"; 
    editInput += updatedMessage;             
    editInput += "quit\n";                   

    istringstream editTestCin(editInput); 
    cin.rdbuf(editTestCin.rdbuf());

    // Clear cout buffer of prompts from previous actions (like initial OpenFiles)
    testCout.str("");
    testCout.clear();

    cerr << "DEBUG: Calling EditFile." << endl;
    bool editSuccess = notePadTestObj.EditFile();
    ASSERT_TRUE(editSuccess) << "EditFile function call failed.";
    cerr << "DEBUG: EditFile returned." << endl;

    // --- Phase 4: Read and verify the EDITED file ---
    // Clear cout buffer of prompts from EditFile 
    testCout.str(""); // 
    testCout.clear();

    string openEditedFileInput = testFileName + "\n"; // Input for opening the edited file
    istringstream openEditedTestCin(openEditedFileInput); // Dedicated stream for reading edited file
    cin.rdbuf(openEditedTestCin.rdbuf());

    cerr << "DEBUG: Calling OpenFiles to read edited content." << endl;
    bool openEditSuccess = notePadTestObj.OpenFiles();
    ASSERT_TRUE(openEditSuccess) << "OpenFiles after edit failed.";
    cerr << "DEBUG: OpenFiles after edit returned." << endl;

    // Get the actual content from the file system AFTER the edit
    string actualEditedFileContent = readFileContentHelper(pathToTestFile);

    // Get the output captured by testCout from the *latest* OpenFiles call
    string capturedEditedOpenOutput = testCout.str();

    cerr << "DEBUG: Captured output for edited OpenFiles:\n---\n" << capturedEditedOpenOutput << "---\n";
    cerr << "DEBUG: Expected edited file content:\n---\n" << updatedMessage << "---\n"; // Compare against the updated message

    size_t markerPosEdited = capturedEditedOpenOutput.find(marker);

    ASSERT_NE(markerPosEdited, string::npos) << "Marker not found in edited OpenFiles output for '" << marker << "'. Full output:\n" << capturedEditedOpenOutput;
    string extractedEditedFileContent = capturedEditedOpenOutput.substr(markerPosEdited + marker.length());

    // Compare the extracted content with the expected updated message
    EXPECT_EQ(updatedMessage, extractedEditedFileContent) << "Edited file content verification mismatch.";
    cerr << "DEBUG: Edited file content verified successfully." << endl;

    cerr << "DEBUG: TEST_F EditFile finished." << endl;
}