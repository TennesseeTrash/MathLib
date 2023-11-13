#ifndef MATHLIB_COMMON_IMPL_PACKS_HPP
#define MATHLIB_COMMON_IMPL_PACKS_HPP

#include "StrongTypes.hpp"
#include "StrongTypesUtils.hpp"

namespace Math::Implementation
{
    template <typename... Types>
    struct TypePack
    {
    private:
        template <StaticSizeType Index, typename... AtImplTypes>
        struct AtImpl;

        template <StaticSizeType Index, typename Head, typename... AtImplTypes>
        struct AtImpl<Index, Head, AtImplTypes...>
        {
            using Type = typename AtImpl<Convert<StaticSizeType>(SizeType(Index) - 1), Types...>::Type;
        };

        template <typename Head, typename... AtImplTypes>
        struct AtImpl<0, Head, AtImplTypes...>
        {
            using Type = Head;
        };
    public:
        static constexpr StaticSizeType Size = sizeof...(Types);

        template <StaticSizeType Index>
        using At = typename AtImpl<Index, Types...>::Type;
    };
}

#endif //MATHLIB_COMMON_IMPL_PACKS_HPP
