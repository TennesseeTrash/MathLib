#ifndef MATHLIB_TESTS_TRANSFORM_TESTS_COMMON_HPP
#define MATHLIB_TESTS_TRANSFORM_TESTS_COMMON_HPP

#include <Math/Transform.hpp>

constexpr Math::Transform2f MakeTransform2f1()
{
    return Math::Transform2f(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    );
}

constexpr Math::Transform2f MakeTransform2f2()
{
    return Math::Transform2f(
        7.0f,  8.0f,  9.0f,
        10.0f, 11.0f, 12.0f
    );
}

constexpr Math::Transform2f MakeTransform2f3()
{
    return Math::Transform2f(
        27.0f, 30.0f,  36.0f,
        78.0f, 87.0f, 102.0f
    );
}

constexpr Math::Transform3f MakeTransform3f1()
{
    return Math::Transform3f(
        1.0f,  2.0f,  3.0f,  4.0f,
        5.0f,  6.0f,  7.0f,  8.0f,
        9.0f, 10.0f, 11.0f, 12.0f
    );
}

constexpr Math::Transform3f MakeTransform3f2()
{
    return Math::Transform3f(
        13.0f, 14.0f, 15.0f, 16.0f,
        17.0f, 18.0f, 19.0f, 20.0f,
        21.0f, 22.0f, 23.0f, 24.0f
    );
}

constexpr Math::Transform3f MakeTransform3f3()
{
    return Math::Transform3f(
        110.0f, 116.0f, 122.0f, 132.0f,
        314.0f, 332.0f, 350.0f, 376.0f,
        518.0f, 548.0f, 578.0f, 620.0f
    );
}

#endif //MATHLIB_TESTS_TRANSFORM_TESTS_COMMON_HPP
