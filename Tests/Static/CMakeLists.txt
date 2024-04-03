include(${PROJECT_SOURCE_DIR}/CMake/Catch2.cmake)

add_executable(StaticTests)

target_link_libraries(StaticTests PRIVATE
    MathLib
    Catch2::Catch2WithMain
)

target_sources(StaticTests
    PRIVATE
    "Types.cpp"
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(StaticTests PRIVATE /W4)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(StaticTests PRIVATE -Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    target_compile_options(StaticTests PRIVATE -Weverything -Wpedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-unsafe-buffer-usage)
else()
    message(WARNING "Unknown compiler, no compiler warnings set for StaticTests target!")
endif()
