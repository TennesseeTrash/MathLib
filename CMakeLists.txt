cmake_minimum_required(VERSION 3.22)

project(math-cpp)

add_library(math-cpp INTERFACE)
target_include_directories(math-cpp INTERFACE "include")
set_property(TARGET math-cpp PROPERTY CXX_STANDARD 20)

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory("Tests")
endif()
