#include <gtest/gtest.h>
#include "../src/fileOperationsClass/fileOperations.hpp"
#include "string"

using namespace std;

// Unit tests for FileOperations

/*
 * TEST: FileOperationsTest.TestReadFileNotFound
 * PURPOSE: To verify that the ReadFile function successfully returns false when a non-existent or incorrect file is passed.
 * SETUP: None
 * EXPECTED BEHAVIOR: The function should return false.
 */
TEST(CppNotePadTest, TestReadFileNotFound){
    FileOperations fileOperationsTest;

    string falseFilePath = "notARealFile.txt";

    ASSERT_EQ(false, fileOperationsTest.readFile(falseFilePath));

}

/*
 * TEST: FileOperationsTest.TestReadFile
 * PURPOSE: To verify that the ReadFile function successfully opens an existing file.
 * SETUP: Ensure that the file "test.txt" exists in the project directory.
 * EXPECTED BEHAVIOR: The function should return true when the file exists.
 */
TEST(CppNotePadTest, TestReadFile){
    FileOperations fileOperationsTest;

    string trueFilePath = "/workspaces/CppNotePad/Files/test.txt";

    ASSERT_EQ(true, fileOperationsTest.readFile(trueFilePath));

}