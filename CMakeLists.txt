cmake_minimum_required(VERSION 3.14)

set(This CppNotePad)

project(${This} C CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(googletest)

# Automatically gather all source and header files
file(GLOB Sources
    src/*.cpp  
    src/notepadClass/*.cpp
)

# Header files
file(GLOB Headers
    src/*.hpp
    src/notepadClass/*.hpp
)

# Create static library for testing
add_library(${This} STATIC ${Sources} ${Headers})

# Create an executable for main program 
add_executable(CppNPExec ${Sources}) 

# Link your executable to the static library 
target_link_libraries(CppNPExec PRIVATE ${This})

# Integration Tests
enable_testing()
add_subdirectory(Tests)