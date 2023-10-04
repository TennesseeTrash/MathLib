#ifndef MATHLIB_UTILS_CONTAINER_TOOLS_HPP
#define MATHLIB_UTILS_CONTAINER_TOOLS_HPP

#include "../Common/Types.hpp"
#include "../Common/Concepts.hpp"

#include <array>
#include <unordered_map>

namespace Math
{
    template <ConceptBasicVector Vec>
        requires IntegralType<typename Vec::ScalarType>
    class VectorHasher
    {
    private:
        static constexpr std::array<SizeType, 4> sHashPrimes = {
            1610612741, 805306457, 402653189, 201326611,
        };
    public:
        [[nodiscard]] constexpr
        std::size_t operator()(const Vec& vec) const noexcept
        {
            SizeType hash = 0;

            for (SizeType i = 0; i < Vec::Dimension; ++i)
            {
                hash ^= vec[i] * sHashPrimes[i];
            }

            return hash;
        }
    };

    template <ConceptBasicVector Vec>
        requires IntegralType<typename Vec::ScalarType>
    class VectorEqual
    {
    public:
        [[nodiscard]] constexpr
        std::size_t operator()(const Vec& u, const Vec& v) const noexcept
        {
            for (SizeType i = 0; i < Vec::Dimension; ++i)
            {
                if (u[i] != v[i])
                {
                    return false;
                }
            }
            return true;
        }
    };

    template <ConceptBasicVector Vec, typename T>
    using UnorderedVecMap = std::unordered_map<Vec, T, VectorHasher<Vec>, VectorEqual<Vec>>;
}

#endif //MATHLIB_UTILS_CONTAINER_TOOLS_HPP
