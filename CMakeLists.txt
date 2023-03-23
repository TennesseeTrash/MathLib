cmake_minimum_required(VERSION 3.22)

project(MathLib)

add_library(MathLib INTERFACE)
target_include_directories(MathLib INTERFACE "include")
set_property(TARGET MathLib PROPERTY CXX_STANDARD 20)

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory("Tests")
endif()
