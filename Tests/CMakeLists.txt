Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(Tests)

target_link_libraries(Tests PRIVATE
    MathLib
    Catch2::Catch2WithMain
)

target_sources(Tests PRIVATE
    "TestFunctions.cpp"
    "TestVectors.cpp"
    "TestPoints.cpp"
    "TestMatrices.cpp"
    "TestQuaternions.cpp"
    "TestUtilsContainerTools.cpp"
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Tests PRIVATE /W4)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(Tests PRIVATE -Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(Tests PRIVATE -Weverything -Wpedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic)
else()
    message(WARNING "Unknown compiler, no compiler warnings set for Tests target!")
endif()
