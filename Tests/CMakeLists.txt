cmake_minimum_required(VERSION 3.14)

set(This CppNotePadTests)

set(Sources
    CppNotePadTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    CppNotePad
)

add_test(
    NAME ${This}
    COMMAND ${This}
)