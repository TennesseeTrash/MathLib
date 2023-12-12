#ifndef MATHLIB_COMMON_PACKS_HPP
#define MATHLIB_COMMON_PACKS_HPP

#include "Implementation/Packs.hpp"
#include "Implementation/PacksTools.hpp"

namespace Math
{
    template <typename First, typename Second>
    using Concatenate = typename Implementation::Concatenate<First, Second>::Type;

    template <typename T, StaticSizeType Index>
    using RemoveAt = typename Implementation::RemoveAt<T, Index>::Type;

    template <typename T>
    using RemoveFirst = typename Implementation::RemoveFirst<T>::Type;

    template <typename T>
    using RemoveLast = typename Implementation::RemoveLast<T>::Type;

    template <typename T, StaticSizeType Begin, StaticSizeType Length>
    using SubPack = typename Implementation::SubPack<T, Begin, Length>::Type;

    template <typename T>
    using Reverse = typename Implementation::Reverse<T>::Type;

    template <typename Pack1, typename Pack2>
    using Zip = typename Implementation::Zip<Pack1, Pack2>::Type;

    template <typename Zipper, typename Pack1, typename Pack2>
    using ZipWith = typename Implementation::ZipWith<Zipper, Pack1, Pack2>::Type;

    template <template <typename, typename> typename ZipperImpl>
    struct MakeTypeZipper
    {
        template <typename First, typename Second>
        using Impl = ZipperImpl<First, Second>;
    };
}

#endif //MATHLIB_COMMON_PACKS_HPP
