include(${PROJECT_SOURCE_DIR}/CMake/Catch2.cmake)

add_executable(UnitTests)

target_link_libraries(UnitTests PRIVATE
    MathLib
    Catch2::Catch2WithMain
)

target_sources(UnitTests PRIVATE
    "Base/Array.cpp"
    "Functions/BasicFunctions/SignAbsTests.cpp"
    "Functions/BasicFunctions/PowerTests.cpp"
    "Functions/BasicFunctions/LogTests.cpp"
    "Functions/BasicFunctions/SqrtTests.cpp"
    "Functions/BasicFunctions/SimpleUtilFuncsTests.cpp"
    "Functions/BasicFunctions/ValueShiftTests.cpp"
    "Functions/BasicFunctions/DegreeRadianConversionTests.cpp"
    "Functions/BasicFunctions/MinMaxTests.cpp"
    "Functions/BasicFunctions/TrigTests/SinTests.cpp"
    "Functions/BasicFunctions/TrigTests/CosTests.cpp"
    "Vector/VectorType.cpp"
    "Vector/VectorOperator.cpp"
    "Vector/VectorUtils.cpp"
    "Matrix/MatrixType.cpp"
    "Matrix/MatrixOperator.cpp"
    "Matrix/MatrixUtils.cpp"
    "Matrix/MatrixScalarOperator.cpp"
    "Matrix/MatrixVectorOperator.cpp"
    "Matrix/MatrixPointOperator.cpp"
    "Transform/TransformType.cpp"
    "Transform/TransformOperator.cpp"
    "Transform/TransformUtils.cpp"
    "Transform/TransformVectorOperator.cpp"
    "Transform/TransformPointOperator.cpp"
    "Point/PointType.cpp"
    "Point/PointConversions.cpp"
    "Point/PointOperator.cpp"
    "Point/PointUtils.cpp"
    "Point/PointVectorOperator.cpp"
    "Random/UniformDistribution.cpp"
    "Geometry/2D/Line.cpp"
    "Geometry/2D/Circle.cpp"
    "Geometry/2D/Triangle.cpp"
    "Geometry/2D/Rectangle.cpp"
    "Geometry/2D/Ellipse.cpp"
    "Geometry/2D/Quadrilateral.cpp"
    "Geometry/2D/Ray.cpp"
    "TestTypes.cpp"
    "TestQuaternions.cpp"
    "TestNoise.cpp"
    "TestUtilsContainerTools.cpp"
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(UnitTests PRIVATE /W4)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(UnitTests PRIVATE -Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    target_compile_options(UnitTests PRIVATE -Weverything -Wpedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-unsafe-buffer-usage)
else()
    message(WARNING "Unknown compiler, no compiler warnings set for UnitTests target!")
endif()
