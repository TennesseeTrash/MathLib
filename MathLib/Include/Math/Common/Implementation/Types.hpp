#ifndef MATHLIB_COMMON_IMPLEMENTATION_TYPES_HPP
#define MATHLIB_COMMON_IMPLEMENTATION_TYPES_HPP

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

    template <typename T>
        requires requires { typename T::ValueType; }
    struct GetValueType<T>
    {
        using Type = typename T::ValueType;
    };

    template <typename T, typename... Ts>
    struct GetValueType<T, Ts...>
    {
    private:
        template <typename... InTypes>
        struct SameTypes;

        template <typename InType>
        struct SameTypes<InType, InType>
        {
            using Type = InType;
        };

        using ValueType  = typename GetValueType<T>::Type;
        using ValueTypes = typename GetValueType<Ts...>::Type;
    public:
        using Type = typename SameTypes<ValueType, ValueTypes>::Type;
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
