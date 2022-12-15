cmake_minimum_required(VERSION 3.22)

project(ccMath)

add_library(ccMath INTERFACE)
target_include_directories(ccMath INTERFACE "Math")
set_property(TARGET ccMath PROPERTY CXX_STANDARD 20)
