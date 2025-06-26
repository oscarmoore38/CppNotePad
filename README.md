# CppNotePad

This is a fun personal project I did to gain experience with file handling in C++. It is essentially a basic C++ command-line application that mimics standard notepad functionalities, allowing users to write, edit, save, and delete text files. If you only wish to run the program, you can follow the installation steps, omitting the Google Test setup. However, if you plan to extend or modify the program, then installing Google Test as per the instructions will be necessary for testing setup.

**Features**
- Create New Files: creates a new blank text file.

- Edit Existing Files: Open and modify your text files.

- Save Files: Persist your changes to disk.

- Delete Files: Remove unwanted files.

**Setup & Building**
To get CppNotePad up and running on your local machine, follow these steps:

**Prerequisites**

Make sure you have the following installed:

- CMake: A cross-platform build system.

- C++ Compiler: (e.g., GCC, Clang, MSVC)

- Git: For cloning repositories.

**Recommended VS Code Extensions (if using VS Code)**

For the best development experience with IntelliSense and seamless CMake integration, install these extensions in VS Code:

- CMake Tools

- C/C++ extension

**Installation Steps**

**Clone the Repository:**
Navigate to the directory where you want to store the project and clone the CppNotePad repository:

- `git clone https://github.com/oscarmoore38/CppNotePad.git`
- `cd CppNotePad`

Please ensure the CMakeLists.txt file remains in the project root. The program uses this file to identify the root directory and create the Files directory for storing program files upon its first run.

**Clone GoogleTest:**
Google Test is used for the project's unit and integration tests. Clone the GoogleTest repository directly into your project's root directory:

`git clone https://github.com/google/googletest.git`

**Build with CMake:**
Create a build directory, navigate into it, and use CMake to configure and build your project. This will generate the necessary build files and compile the source code.

- `mkdir build`
- `cd build`
- `cmake ..`         # Configures the project and generates build files
- `cmake --build .`    # Compiles the project

**Usage**
After successfully building the project, your executable (CppNPExec on Linux/macOS or CppNPExec.exe on Windows) will be located in the build/bin directory.

To run the application:

- `./bin/CppNPExec`

Or on Windows

- `.\bin\CppNPExec.exe` 

**Running Tests**
The project includes unit and integration tests using Google Test. After building with CMake, you can run all tests using ctest from your build directory:

- `cd build`
- `ctest` Use --verbose to see detailed test output

You can also run tests directly from the VS Code Test Explorer sidebar after the CMake Tools extension has configured the project.


