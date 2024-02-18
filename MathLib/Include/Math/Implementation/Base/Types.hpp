#ifndef MATHLIB_IMPLEMENTATION_BASE_TYPES_HPP
#define MATHLIB_IMPLEMENTATION_BASE_TYPES_HPP

#include "StrongTypes.hpp"
#include "StrongTypesUtils.hpp"
#include "Packs.hpp"

#include <limits>

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Assumptions
    //////////////////////////////////////////////////////////////////////////

    static_assert(std::numeric_limits<float>::is_iec559);
    static_assert(std::numeric_limits<double>::is_iec559);

    static_assert(sizeof(float) == 4);
    static_assert(sizeof(double) == 8);

    //////////////////////////////////////////////////////////////////////////
    // Basic Types
    //////////////////////////////////////////////////////////////////////////

    enum class Orientation
    {
        Left,
        Right
    };

    //////////////////////////////////////////////////////////////////////////
    // Type utilities
    //////////////////////////////////////////////////////////////////////////

    namespace Implementation
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
    }

    template <bool Condition, typename TrueType, typename FalseType>
    using ConditionalType = typename Implementation::ConditionalType<Condition, TrueType, FalseType>::Type;

    namespace Implementation
    {
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
    }

    template <typename... T>
    using GetValueType = typename Implementation::GetValueType<T...>::Type;

    namespace Implementation
    {
        template <typename Specialized, template <typename...> typename Base, SizeType Index = 0>
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

    template <typename Specialized, template <typename...> typename Base, SizeType Index = 0>
    using TemplateArgument = typename Implementation::TemplateArgument<Specialized, Base, Index>::Type;
}

#endif //MATHLIB_IMPLEMENTATION_BASE_TYPES_HPP
