#ifndef MATHLIB_COMMON_TRAITS_HPP
#define MATHLIB_COMMON_TRAITS_HPP

namespace Math
{
    namespace Implementation
    {
        template <typename Specialization, template <typename...> typename Base>
        struct IsSpecialization
        {
            static constexpr bool Value = false;
        };

        template <template<typename...> typename Specialization, typename... Args>
        struct IsSpecialization<Specialization<Args...>, Specialization>
        {
            static constexpr bool Value = true;
        };

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

    template <typename Specialization, template <typename...> typename Base>
    inline constexpr bool IsSpecialization = Implementation::IsSpecialization<Specialization, Base>::Value;

    template <bool Condition, typename TrueType, typename FalseType>
    using ConditionalType = typename Implementation::ConditionalType<Condition, TrueType, FalseType>::Type;

    template <typename T>
    using GetValueType = typename Implementation::GetValueType<T>::Type;
}

#endif //MATHLIB_COMMON_TRAITS_HPP
