#ifndef MATHLIB_COMMON_IMPL_PACKS_HPP
#define MATHLIB_COMMON_IMPL_PACKS_HPP

#include "StrongTypes.hpp"
#include "StrongTypesUtils.hpp"

namespace Math
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
            using Type = typename AtImpl<SizeType(Index) - 1, AtImplTypes...>::Type;
        };

        template <typename Head, typename... AtImplTypes>
        struct AtImpl<0, Head, AtImplTypes...>
        {
            using Type = Head;
        };
    public:
        static constexpr SizeType Size = sizeof...(Types);

        template <StaticSizeType Index>
        using At = typename AtImpl<Index, Types...>::Type;

        template <typename T>
        using Append = TypePack<Types..., T>;
    };

    template <typename T, T... Pack>
    struct ValuePack
    {
    private:
        template <StaticSizeType Index, T... AtImplPack>
        struct AtImpl;

        template <StaticSizeType Index, T Head, T... AtImplPack>
        struct AtImpl<Index, Head, AtImplPack...>
        {
            static constexpr T Value = AtImpl<SizeType(Index) - 1, AtImplPack...>::Value;
        };

        template <T Head, T... AtImplPack>
        struct AtImpl<0, Head, AtImplPack...>
        {
            static constexpr T Value = Head;
        };
    public:
        static constexpr SizeType Size = sizeof...(Pack);
        using ValueType = T;

        template <StaticSizeType Index>
        static constexpr T At = AtImpl<Index, Pack...>::Value;

        template <T Value>
        using Append = ValuePack<T, Pack..., Value>;
    };
}

#endif //MATHLIB_COMMON_IMPL_PACKS_HPP
