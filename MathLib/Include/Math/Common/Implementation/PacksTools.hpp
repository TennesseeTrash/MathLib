#ifndef MATHLIB_COMMON_IMPL_PACKS_TOOLS_HPP
#define MATHLIB_COMMON_IMPL_PACKS_TOOLS_HPP

#include "Packs.hpp"

namespace Math::Implementation
{
    template <typename First, typename Second>
    struct Concatenate;

    template <typename... FirstTypes, typename... SecondTypes>
    struct Concatenate<TypePack<FirstTypes...>, TypePack<SecondTypes...>>
    {
        using Type = TypePack<FirstTypes..., SecondTypes...>;
    };

    template <typename T, T... FirstPack, T... SecondPack>
    struct Concatenate<ValuePack<T, FirstPack...>, ValuePack<T, SecondPack...>>
    {
        using Type = ValuePack<T, FirstPack..., SecondPack...>;
    };



    template <typename T, StaticSizeType Index>
    struct RemoveAt;

    template <StaticSizeType Index, typename HeadType, typename... TailTypes>
    struct RemoveAt<TypePack<HeadType, TailTypes...>, Index>
    {
        using Type = typename Concatenate<TypePack<HeadType>, typename RemoveAt<TypePack<TailTypes...>, Cast<SizeType>(Index) - 1>::Type>::Type;
    };

    template <typename HeadType, typename... TailTypes>
    struct RemoveAt<TypePack<HeadType, TailTypes...>, 0>
    {
        using Type = TypePack<TailTypes...>;
    };

    template <StaticSizeType Index, typename T, T HeadValue, T... TailValues>
    struct RemoveAt<ValuePack<T, HeadValue, TailValues...>, Index>
    {
        using Type = typename Concatenate<ValuePack<T, HeadValue>, typename RemoveAt<ValuePack<T, TailValues...>, Cast<SizeType>(Index) - 1>::Type>::Type;
    };

    template <typename T, T HeadValue, T... TailValues>
    struct RemoveAt<ValuePack<T, HeadValue, TailValues...>, 0>
    {
        using Type = ValuePack<T, TailValues...>;
    };



    template <typename T>
    struct RemoveFirst;

    template <typename... Types>
    struct RemoveFirst<TypePack<Types...>>
    {
        using Type = typename RemoveAt<TypePack<Types...>, 0>::Type;
    };

    template <typename T, T... Values>
    struct RemoveFirst<ValuePack<T, Values...>>
    {
        using Type = typename RemoveAt<ValuePack<T, Values...>, 0>::Type;
    };



    template <typename T>
    struct RemoveLast;

    template <typename... Types>
    struct RemoveLast<TypePack<Types...>>
    {
        using Type = typename RemoveAt<TypePack<Types...>, sizeof...(Types) - 1>::Type;
    };

    template <typename T, T... Values>
    struct RemoveLast<ValuePack<T, Values...>>
    {
        using Type = typename RemoveAt<ValuePack<T, Values...>, sizeof...(Values) - 1>::Type;
    };



    template <typename T, StaticSizeType Begin, StaticSizeType Length>
    struct SubPack;

    template <StaticSizeType Begin, StaticSizeType Length, typename HeadType, typename... TailTypes>
    struct SubPack<TypePack<HeadType, TailTypes...>, Begin, Length>
    {
        using Type = typename SubPack<TypePack<TailTypes...>, Cast<SizeType>(Begin) - 1, Length>::Type;
    };

    template <StaticSizeType Length, typename HeadType, typename... TailTypes>
    struct SubPack<TypePack<HeadType, TailTypes...>, 0, Length>
    {
        using Type = typename Concatenate<TypePack<HeadType>, typename SubPack<TypePack<TailTypes...>, 0, SizeType(Length) - 1>::Type>::Type;
    };

    template <typename HeadType, typename... TailTypes>
    struct SubPack<TypePack<HeadType, TailTypes...>, 0, 0>
    {
        using Type = TypePack<>;
    };

    template <>
    struct SubPack<TypePack<>, 0, 0>
    {
        using Type = TypePack<>;
    };

    template <StaticSizeType Begin, StaticSizeType Length, typename T, T HeadValue, T... TailValues>
    struct SubPack<ValuePack<T, HeadValue, TailValues...>, Begin, Length>
    {
        using Type = typename SubPack<ValuePack<T, TailValues...>, SizeType(Begin) - 1, Length>::Type;
    };

    template <StaticSizeType Length, typename T, T HeadValue, T... TailValues>
    struct SubPack<ValuePack<T, HeadValue, TailValues...>, 0, Length>
    {
        using Type = typename Concatenate<ValuePack<T, HeadValue>, typename SubPack<ValuePack<T, TailValues...>, 0, SizeType(Length) - 1>::Type>::Type;
    };

    template <typename T, T HeadValue, T... TailValues>
    struct SubPack<ValuePack<T, HeadValue, TailValues...>, 0, 0>
    {
        using Type = ValuePack<T>;
    };

    template <typename T>
    struct SubPack<ValuePack<T>, 0, 0>
    {
        using Type = ValuePack<T>;
    };




    template <typename T>
    struct Reverse;

    template <typename HeadType, typename... TailTypes>
    struct Reverse<TypePack<HeadType, TailTypes...>>
    {
        using Type = typename Concatenate<typename Reverse<TypePack<TailTypes...>>::Type, TypePack<HeadType>>::Type;
    };

    template <typename HeadType>
    struct Reverse<TypePack<HeadType>>
    {
        using Type = TypePack<HeadType>;
    };

    template <typename T, T HeadValue, T... TailValues>
    struct Reverse<ValuePack<T, HeadValue, TailValues...>>
    {
        using Type = typename Concatenate<typename Reverse<ValuePack<T, TailValues...>>::Type, ValuePack<T, HeadValue>>::Type;
    };

    template <typename T, T HeadValue>
    struct Reverse<ValuePack<T, HeadValue>>
    {
        using Type = ValuePack<T, HeadValue>;
    };



    template <typename Pack1, typename Pack2>
    struct Zip;

    template <typename... PackTypes1, typename... PackTypes2>
        requires (sizeof...(PackTypes1) == sizeof...(PackTypes2))
    struct Zip<TypePack<PackTypes1...>, TypePack<PackTypes2...>>
    {
        using Type = TypePack<TypePack<PackTypes1, PackTypes2>...>;
    };

    template <typename... PackTypes1, typename... PackTypes2>
        requires (sizeof...(PackTypes1) != sizeof...(PackTypes2))
    struct Zip<TypePack<PackTypes1...>, TypePack<PackTypes2...>>
    {
    private:
        static constexpr SizeType PackLength = sizeof...(PackTypes1) < sizeof...(PackTypes2) ? sizeof...(PackTypes1) : sizeof...(PackTypes2);
        using Pack1 = typename SubPack<TypePack<PackTypes1...>, 0, PackLength>::Type;
        using Pack2 = typename SubPack<TypePack<PackTypes2...>, 0, PackLength>::Type;
    public:
        using Type = typename Zip<Pack1, Pack2>::Type;
    };

    template <typename T, T... PackValues1, T... PackValues2>
        requires (sizeof...(PackValues1) == sizeof...(PackValues2))
    struct Zip<ValuePack<T, PackValues1...>, ValuePack<T, PackValues2...>>
    {
        using Type = TypePack<ValuePack<T, PackValues1, PackValues2>...>;
    };

    template <typename T, T... PackValues1, T... PackValues2>
        requires (sizeof...(PackValues1) != sizeof...(PackValues2))
    struct Zip<ValuePack<T, PackValues1...>, ValuePack<T, PackValues2...>>
    {
    private:
        static constexpr SizeType PackLength = sizeof...(PackValues1) < sizeof...(PackValues2) ? sizeof...(PackValues1) : sizeof...(PackValues2);
        using Pack1 = typename SubPack<ValuePack<T, PackValues1...>, 0, PackLength>::Type;
        using Pack2 = typename SubPack<ValuePack<T, PackValues2...>, 0, PackLength>::Type;
    public:
        using Type = typename Zip<Pack1, Pack2>::Type;
    };



    template <typename Zipper, typename Pack1, typename Pack2>
    struct ZipWith;

    template <typename Zipper, typename... PackTypes1, typename... PackTypes2>
    struct ZipWith<Zipper, TypePack<PackTypes1...>, TypePack<PackTypes2...>>
    {
    private:
        using Zipped = typename Zip<TypePack<PackTypes1...>, TypePack<PackTypes2...>>::Type;
        template <typename First, typename Second>
        using ZipperType = typename Zipper::template Impl<First, Second>;

        template <typename ImplT>
        struct Impl;

        template <typename... ZippedTypes>
        struct Impl<TypePack<ZippedTypes...>>
        {
            using Type = TypePack<typename ZipperType<typename ZippedTypes::template At<0>, typename ZippedTypes::template At<1>>::Type...>;
        };
    public:
        using Type = typename Impl<Zipped>::Type;
    };

    template <typename Zipper, typename T, T... PackValues1, T... PackValues2>
    struct ZipWith<Zipper, ValuePack<T, PackValues1...>, ValuePack<T, PackValues2...>>
    {
    private:
        using Zipped = typename Zip<ValuePack<T, PackValues1...>, ValuePack<T, PackValues2...>>::Type;


        template <typename ImplT>
        struct Impl;

        template <typename... ZippedTypes>
        struct Impl<TypePack<ZippedTypes...>>
        {
            using Type = ValuePack<T, Zipper{}(ZippedTypes::template At<0>, ZippedTypes::template At<1>)...>;
        };
    public:
        using Type = typename Impl<Zipped>::Type;
    };
}

#endif //MATHLIB_COMMON_IMPL_PACKS_TOOLS_HPP
