#ifndef _MATH_DEBUG_PRINT_HPP
#define _MATH_DEBUG_PRINT_HPP

#include <iostream>
#include <iomanip>

#include "../Vector.hpp"
#include "../Matrix.hpp"

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const cc::Vector2T<T>& vec)
{
    os  << "Vector2T("
        << std::setprecision(4) << vec.x << ", "
        << std::setprecision(4) << vec.y << ")";
    return os;
}

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const cc::Vector3T<T>& vec)
{
    os  << "Vector3T("
        << std::setprecision(4) << vec.x << ", "
        << std::setprecision(4) << vec.y << ", "
        << std::setprecision(4) << vec.z << ")";
    return os;
}

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const cc::Vector4T<T>& vec)
{
    os  << "Vector4T("
        << std::setprecision(4) << vec.x << ", "
        << std::setprecision(4) << vec.y << ", "
        << std::setprecision(4) << vec.z << ", "
        << std::setprecision(4) << vec.w << ")";
    return os;
}

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const cc::Matrix2T<T>& mat)
{
    os << "Matrix2T(\n";
    for (size_t i = 0; i < 2; ++i)
    {
        os << "    ";
        for (size_t j = 0; j < 2; ++j)
        {
            os << std::setprecision(4) << mat[i][j] << ", ";
        }
        os << "\n";
    }
    os << ")";
    return os;
}

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const cc::Matrix3T<T>& mat)
{
    os << "Matrix3T(\n";
    for (size_t i = 0; i < 3; ++i)
    {
        os << "    ";
        for (size_t j = 0; j < 3; ++j)
        {
            os << std::setprecision(4) << mat[i][j] << ", ";
        }
        os << "\n";
    }
    os << ")";
    return os;
}

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const cc::Matrix4T<T>& mat)
{
    os << "Matrix4T(\n";
    for (size_t i = 0; i < 4; ++i)
    {
        os << "    ";
        for (size_t j = 0; j < 4; ++j)
        {
            os << std::setprecision(4) << mat[i][j] << ", ";
        }
        os << "\n";
    }
    os << ")";
    return os;
}

#endif // _MATH_DEBUG_PRINT_HPP
