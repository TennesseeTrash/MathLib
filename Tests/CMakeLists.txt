include(${PROJECT_SOURCE_DIR}/CMake/Catch2.cmake)

add_executable(Tests)

target_link_libraries(Tests PRIVATE
    MathLib
    Catch2::Catch2WithMain
)

target_sources(Tests PRIVATE
    "Base/Array.cpp"
    "Functions/SignAbs.cpp"
    "Functions/Power.cpp"
    "Functions/Log.cpp"
    "Functions/Sqrt.cpp"
    "Functions/SimpleUtilFuncs.cpp"
    "Functions/ValueShift.cpp"
    "Functions/Angles.cpp"
    "Functions/MinMax.cpp"
    "Functions/Sin.cpp"
    "Functions/Cos.cpp"
    "Functions/Polynomials.cpp"
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
    "Quaternion/TestQuaternions.cpp"
    "Random/UniformDistribution.cpp"
    "Geometry/2D/Line.cpp"
    "Geometry/2D/Circle.cpp"
    "Geometry/2D/Triangle.cpp"
    "Geometry/2D/Rectangle.cpp"
    "Geometry/2D/Ellipse.cpp"
    "Geometry/2D/Quadrilateral.cpp"
    "Noise/TestNoise.cpp"
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(Tests PRIVATE /W4)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(Tests PRIVATE -Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    target_compile_options(Tests PRIVATE -Weverything -Wpedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-unsafe-buffer-usage)
else()
    message(WARNING "Unknown compiler, no compiler warnings set for Tests target!")
endif()
