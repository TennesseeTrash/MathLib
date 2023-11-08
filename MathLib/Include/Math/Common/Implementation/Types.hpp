#ifndef MATHLIB_COMMON_IMPL_TYPES_HPP
#define MATHLIB_COMMON_IMPL_TYPES_HPP

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

    template <typename T>
    concept HasValueType = requires
    {
        typename T::ValueType;
    };

    template <typename T>
    struct GetValueType
    {
        using Type = void;
    };

    template <typename T>
        requires HasValueType<T>
    struct GetValueType<T>
    {
        using Type = typename T::ValueType;
    };
}

#endif //MATHLIB_COMMON_IMPL_TYPES_HPP
