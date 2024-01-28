cmake_minimum_required(VERSION 3.21)

project(MathLib)

add_subdirectory("MathLib")

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory("Tests")
    add_subdirectory("Examples")
endif()
