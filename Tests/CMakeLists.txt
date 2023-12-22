Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.0
)

FetchContent_MakeAvailable(Catch2)

add_executable(Tests)

target_link_libraries(Tests PRIVATE
    MathLib
    Catch2::Catch2WithMain
)

target_sources(Tests PRIVATE
    "CommonTests/PacksTests.cpp"
    "CommonTests/ArrayTests.cpp"
    "FunctionsTests/BasicFunctionsTests/SignAbsTests.cpp"
    "FunctionsTests/BasicFunctionsTests/PowerTests.cpp"
    "FunctionsTests/BasicFunctionsTests/LogTests.cpp"
    "FunctionsTests/BasicFunctionsTests/SqrtTests.cpp"
    "FunctionsTests/BasicFunctionsTests/SimpleUtilFuncsTests.cpp"
    "FunctionsTests/BasicFunctionsTests/ValueShiftTests.cpp"
    "FunctionsTests/BasicFunctionsTests/DegreeRadianConversionTests.cpp"
    "FunctionsTests/BasicFunctionsTests/MinMaxTests.cpp"
    "FunctionsTests/BasicFunctionsTests/TrigTests/SinTests.cpp"
    "FunctionsTests/BasicFunctionsTests/TrigTests/CosTests.cpp"
    "FunctionsTests/ElementaryFunctionsTests.cpp"
    "FunctionsTests/CompositionFunctionsTests.cpp"
    "VectorTests/VectorTypeTests.cpp"
    "VectorTests/VectorOperatorTests.cpp"
    "VectorTests/VectorUtilsTests.cpp"
    "MatrixTests/MatrixTypeTests.cpp"
    "MatrixTests/MatrixOperatorTests.cpp"
    "MatrixTests/MatrixUtilsTests.cpp"
    "MatrixTests/MatrixScalarOperatorTests.cpp"
    "MatrixTests/MatrixVectorOperatorTests.cpp"
    "MatrixTests/MatrixPointOperatorTests.cpp"
    "TransformTests/TransformTypeTests.cpp"
    "TransformTests/TransformOperatorTests.cpp"
    "TransformTests/TransformUtilsTests.cpp"
    "TransformTests/TransformVectorOperatorTests.cpp"
    "TransformTests/TransformPointOperatorTests.cpp"
    "PointTests/PointTypeTests.cpp"
    "PointTests/PointConversions.cpp"
    "PointTests/PointOperatorTests.cpp"
    "PointTests/PointUtilsTests.cpp"
    "PointTests/PointVectorOperatorTests.cpp"
    "RandomTests/UniformDistributionTests.cpp"
    "TestTypes.cpp"
    "TestConcepts.cpp"
    "TestFunctions.cpp"
    "TestQuaternions.cpp"
    "TestNoise.cpp"
    "TestUtilsContainerTools.cpp"
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Tests PRIVATE /W4)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(Tests PRIVATE -Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    target_compile_options(Tests PRIVATE -Weverything -Wpedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic)
else()
    message(WARNING "Unknown compiler, no compiler warnings set for Tests target!")
endif()
