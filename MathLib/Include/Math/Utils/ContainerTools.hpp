#ifndef MATHLIB_UTILS_CONTAINER_TOOLS_HPP
#define MATHLIB_UTILS_CONTAINER_TOOLS_HPP

#include "../Common/Types.hpp"
#include "../Common/Concepts.hpp"
#include "../Common/Array.hpp"

#include <unordered_map>

namespace Math
{
    template <ConceptBasicVector Vec>
        requires IntegralType<typename Vec::ScalarType>
    class VectorHasher
    {
    private:
        static constexpr Array<SizeType, 4> sHashPrimes = {
            SizeType(1610612741), SizeType(805306457), SizeType(402653189), SizeType(201326611),
        };
    public:
        [[nodiscard]] constexpr
        std::size_t operator()(const Vec& vec) const noexcept
        {
            SizeType hash = 0;

            for (SizeType i = 0; i < Vec::Dimension; ++i)
            {
                hash ^= Cast<SizeType>(vec[i]) * sHashPrimes[i];
            }

            return ToUnderlying(hash);
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
