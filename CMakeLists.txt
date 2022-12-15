cmake_minimum_required(VERSION 3.22)

project(ccMath)

add_library(ccMath INTERFACE)
target_include_directories(ccMath INTERFACE "include")
set_property(TARGET ccMath PROPERTY CXX_STANDARD 20)

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory("Tests")
endif()
