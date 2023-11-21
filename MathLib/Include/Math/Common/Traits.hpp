#ifndef MATHLIB_COMMON_TRAITS_HPP
#define MATHLIB_COMMON_TRAITS_HPP

#include "Implementation/Traits.hpp"

#include <type_traits>

namespace Math
{
    template <typename T, typename U>
    concept IsSame = std::is_same_v<T, U>;

    template <typename T, typename U>
    concept SameBaseType = std::is_same_v<std::remove_cvref_t<U>, std::remove_cvref_t<T>>;

    template <typename T, typename U>
    concept SameTypeRef = std::is_same_v<U&, T>;

    template <typename T>
    concept FundamentalType = std::is_fundamental_v<T>;

    template <typename T>
    concept IntegralType = std::is_integral_v<T>
                        || std::is_integral_v<typename T::ValueType>;

    template <typename T>
    concept SignedIntegralType = IntegralType<T>
                              &&(std::is_signed_v<T>
                              || std::is_signed_v<typename T::ValueType>);

    template <typename T>
    concept UnsignedIntegralType = IntegralType<T>
                                &&(std::is_unsigned_v<T>
                                || std::is_unsigned_v<typename T::ValueType>);

    template <typename T>
    concept FloatingPointType = std::is_floating_point_v<T>
                             || std::is_floating_point_v<typename T::ValueType>;

    template <typename T>
    concept IsEmpty = std::is_empty_v<T>;

    template <typename T>
    concept HasValueType = requires
    {
        typename T::ValueType;
    };

    template <typename Specialization, template<typename...> typename Base>
    concept IsSpecialization = Implementation::IsSpecialization<Specialization, Base>::Value;

    template <typename Specialization, template<typename...> typename... Bases>
    concept IsSpecializationOfAny = Implementation::IsSpecializationOfAny<Specialization, Bases...>::Value;
}

#endif //MATHLIB_COMMON_TRAITS_HPP
