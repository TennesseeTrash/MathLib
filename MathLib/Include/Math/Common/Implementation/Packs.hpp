#ifndef MATHLIB_COMMON_IMPLEMENTATION_PACKS_HPP
#define MATHLIB_COMMON_IMPLEMENTATION_PACKS_HPP

#include "StrongTypes.hpp"
#include "StrongTypesUtils.hpp"

namespace Math
{
    template <typename... Types>
    struct TypePack final
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

        using First = At<0>;
        using Last  = At<Size - 1>;

        template <typename T>
        using Append = TypePack<Types..., T>;

        template <typename T>
        using Prepend = TypePack<T, Types...>;
    };

    template <typename T, T... Pack>
    struct ValuePack final
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
        static constexpr ValueType At = AtImpl<Index, Pack...>::Value;

        static constexpr ValueType First = At<0>;
        static constexpr ValueType Last  = At<Size - 1>;

        template <T Value>
        using Append = ValuePack<T, Pack..., Value>;

        template <T Value>
        using Prepend = ValuePack<T, Value, Pack...>;

    private:
        template <StaticSizeType Count, StaticSizeType Index = 0>
        struct MakeAscendingImpl
        {
            using Type = typename MakeAscendingImpl<Count, SizeType(Index) + 1>::Type::template Prepend<Cast<T>(Index)>;
        };

        template <StaticSizeType Count>
        struct MakeAscendingImpl<Count, Count>
        {
            using Type = ValuePack<T>;
        };

        template <StaticSizeType Count, StaticSizeType Index = 0>
        struct MakeDescendingImpl
        {
            using Type = typename MakeDescendingImpl<Count, SizeType(Index) + 1>::Type::template Append<Cast<T>(Index)>;
        };

        template <StaticSizeType Count>
        struct MakeDescendingImpl<Count, Count>
        {
            using Type = ValuePack<T>;
        };

    public:
        template <StaticSizeType Count>
        using MakeAscending = typename MakeAscendingImpl<Count, 0>::Type;

        template <StaticSizeType Count>
        using MakeDescending = typename MakeDescendingImpl<Count, 0>::Type;
    };
}

#endif //MATHLIB_COMMON_IMPLEMENTATION_PACKS_HPP
