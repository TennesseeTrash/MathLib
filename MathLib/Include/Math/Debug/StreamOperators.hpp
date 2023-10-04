#ifndef MATHLIB_DEBUG_PRINT_HPP
#define MATHLIB_DEBUG_PRINT_HPP

#include <iostream>
#include <iomanip>

#include "../Vector.hpp"
#include "../Point.hpp"
#include "../Matrix.hpp"
#include "../Quaternion.hpp"

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const Math::Vector2T<T>& vec)
{
    os  << "Vector2T("
        << std::setprecision(4) << vec.x << ", "
        << std::setprecision(4) << vec.y << ")";
    return os;
}

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const Math::Vector3T<T>& vec)
{
    os  << "Vector3T("
        << std::setprecision(4) << vec.x << ", "
        << std::setprecision(4) << vec.y << ", "
        << std::setprecision(4) << vec.z << ")";
    return os;
}

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const Math::Vector4T<T>& vec)
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
std::ostream& operator<<(std::ostream& os, const Math::Point2T<T>& vec)
{
    os  << "Point2T("
        << std::setprecision(4) << vec.x << ", "
        << std::setprecision(4) << vec.y << ")";
    return os;
}

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const Math::Point3T<T>& vec)
{
    os  << "Point3T("
        << std::setprecision(4) << vec.x << ", "
        << std::setprecision(4) << vec.y << ", "
        << std::setprecision(4) << vec.z << ")";
    return os;
}

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const Math::Matrix2T<T>& mat)
{
    os << "Matrix2T(\n";
    for (Math::SizeType i = 0; i < 2; ++i)
    {
        os << "    ";
        for (Math::SizeType j = 0; j < 2; ++j)
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
std::ostream& operator<<(std::ostream& os, const Math::Matrix3T<T>& mat)
{
    os << "Matrix3T(\n";
    for (Math::SizeType i = 0; i < 3; ++i)
    {
        os << "    ";
        for (Math::SizeType j = 0; j < 3; ++j)
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
std::ostream& operator<<(std::ostream& os, const Math::Matrix4T<T>& mat)
{
    os << "Matrix4T(\n";
    for (Math::SizeType i = 0; i < 4; ++i)
    {
        os << "    ";
        for (Math::SizeType j = 0; j < 4; ++j)
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
std::ostream& operator<<(std::ostream& os, const Math::QuaternionT<T>& quat)
{
    os  << "QuaternionT("
        << std::setprecision(4) << quat.mV.x << ", "
        << std::setprecision(4) << quat.mV.y << ", "
        << std::setprecision(4) << quat.mV.z << ", "
        << std::setprecision(4) << quat.mS   << ")";
    return os;
}

#endif // MATHLIB_DEBUG_PRINT_HPP
