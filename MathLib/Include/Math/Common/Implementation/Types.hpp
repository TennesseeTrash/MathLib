#ifndef MATHLIB_COMMON_IMPLEMENTATION_TYPES_HPP
#define MATHLIB_COMMON_IMPLEMENTATION_TYPES_HPP

#include "../Traits.hpp"
#include "StrongTypes.hpp"
#include "Packs.hpp"

namespace Math::Implementation
{
    template <bool Condition, typename TrueType, typename FalseType>
    struct ConditionalType
    {
        using Type = TrueType;
    };

    template <typename TrueType, typename FalseType>
    struct ConditionalType<false, TrueType, FalseType>
    {
        using Type = FalseType;
    };

    template <typename... Ts>
    struct GetValueType
    {};

    template <typename T1, typename... T>
    struct GetValueType<T1, T...>
    {
    private:
        using ValueType1 = typename GetValueType<T1>::Type;
        using ValueType2 = typename GetValueType<T...>::Type;
        static_assert(IsSame<ValueType1, ValueType2>);
    public:
        using Type = ValueType1;
    };

    template <typename T>
        requires requires { typename T::ValueType; }
    struct GetValueType<T>
    {
        using Type = typename T::ValueType;
    };

    template <typename... Ts>
    struct GetValueType<TypePack<Ts...>>
    {
        using Type = typename GetValueType<Ts...>::Type;
    };

    template <typename Specialized, template <typename...> typename Base, StaticSizeType Index = 0>
    struct TemplateArgument
    {
    private:
        template <typename... Args>
        static TypePack<Args...> GetArg(Base<Args...>);

        using SpecializedArgs = decltype(GetArg(Specialized{}));
    public:
        using Type = typename SpecializedArgs::template At<Index>;
    };
}

#endif //MATHLIB_COMMON_IMPLEMENTATION_TYPES_HPP
