#ifndef MATHLIB_IMPLEMENTATION_BASE_PACKS_HPP
#define MATHLIB_IMPLEMENTATION_BASE_PACKS_HPP

#include "StrongTypes.hpp"
#include "StrongTypesUtils.hpp"

namespace Math
{
    //////////////////////////////////////////////////////////////////////////
    // Type Pack
    //////////////////////////////////////////////////////////////////////////

    template <typename... Types>
    struct TypePack final
    {
    private:
        template <SizeType Index, typename... AtImplTypes>
        struct AtImpl;

        template <SizeType Index, typename Head, typename... AtImplTypes>
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

        template <SizeType Index>
        using At = typename AtImpl<Index, Types...>::Type;

        using First = At<0>;
        using Last  = At<Size - 1>;

        template <typename T>
        using Append = TypePack<Types..., T>;

        template <typename T>
        using Prepend = TypePack<T, Types...>;
    };

    //////////////////////////////////////////////////////////////////////////
    // Value Pack
    //////////////////////////////////////////////////////////////////////////

    template <typename T, T... Pack>
    struct ValuePack final
    {
    private:
        template <SizeType Index, T... AtImplPack>
        struct AtImpl;

        template <SizeType Index, T Head, T... AtImplPack>
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

        template <SizeType Index>
        static constexpr ValueType At = AtImpl<Index, Pack...>::Value;

        static constexpr ValueType First = At<0>;
        static constexpr ValueType Last  = At<Size - 1>;

        template <T Value>
        using Append = ValuePack<T, Pack..., Value>;

        template <T Value>
        using Prepend = ValuePack<T, Value, Pack...>;

    private:
        template <SizeType Count, SizeType Index = 0>
        struct MakeAscendingImpl
        {
            using Type = typename MakeAscendingImpl<Count, SizeType(Index) + 1>::Type::template Prepend<Cast<T>(Index)>;
        };

        template <SizeType Count>
        struct MakeAscendingImpl<Count, Count>
        {
            using Type = ValuePack<T>;
        };

        template <SizeType Count, SizeType Index = 0>
        struct MakeDescendingImpl
        {
            using Type = typename MakeDescendingImpl<Count, SizeType(Index) + 1>::Type::template Append<Cast<T>(Index)>;
        };

        template <SizeType Count>
        struct MakeDescendingImpl<Count, Count>
        {
            using Type = ValuePack<T>;
        };

    public:
        template <SizeType Count>
        using MakeAscending = typename MakeAscendingImpl<Count, 0>::Type;

        template <SizeType Count>
        using MakeDescending = typename MakeDescendingImpl<Count, 0>::Type;
    };



    //////////////////////////////////////////////////////////////////////////
    // Pack Operations
    //////////////////////////////////////////////////////////////////////////

    namespace Implementation
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
    }

    template <typename First, typename Second>
    using Concatenate = typename Implementation::Concatenate<First, Second>::Type;


    namespace Implementation
    {
        template <typename T, SizeType Index>
        struct RemoveAt;

        template <SizeType Index, typename HeadType, typename... TailTypes>
        struct RemoveAt<TypePack<HeadType, TailTypes...>, Index>
        {
            using Type = typename Concatenate<TypePack<HeadType>, typename RemoveAt<TypePack<TailTypes...>, Cast<SizeType>(Index) - 1>::Type>::Type;
        };

        template <typename HeadType, typename... TailTypes>
        struct RemoveAt<TypePack<HeadType, TailTypes...>, 0>
        {
            using Type = TypePack<TailTypes...>;
        };

        template <SizeType Index, typename T, T HeadValue, T... TailValues>
        struct RemoveAt<ValuePack<T, HeadValue, TailValues...>, Index>
        {
            using Type = typename Concatenate<ValuePack<T, HeadValue>, typename RemoveAt<ValuePack<T, TailValues...>, Cast<SizeType>(Index) - 1>::Type>::Type;
        };

        template <typename T, T HeadValue, T... TailValues>
        struct RemoveAt<ValuePack<T, HeadValue, TailValues...>, 0>
        {
            using Type = ValuePack<T, TailValues...>;
        };
    }

    template <typename T, SizeType Index>
    using RemoveAt = typename Implementation::RemoveAt<T, Index>::Type;



    namespace Implementation
    {
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
    }

    template <typename T>
    using RemoveFirst = typename Implementation::RemoveFirst<T>::Type;



    namespace Implementation
    {
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
    }

    template <typename T>
    using RemoveLast = typename Implementation::RemoveLast<T>::Type;



    namespace Implementation
    {
        template <typename T, SizeType Begin, SizeType Length>
        struct SubPack;

        template <SizeType Begin, SizeType Length, typename HeadType, typename... TailTypes>
        struct SubPack<TypePack<HeadType, TailTypes...>, Begin, Length>
        {
            using Type = typename SubPack<TypePack<TailTypes...>, Cast<SizeType>(Begin) - 1, Length>::Type;
        };

        template <SizeType Length, typename HeadType, typename... TailTypes>
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

        template <SizeType Begin, SizeType Length, typename T, T HeadValue, T... TailValues>
        struct SubPack<ValuePack<T, HeadValue, TailValues...>, Begin, Length>
        {
            using Type = typename SubPack<ValuePack<T, TailValues...>, SizeType(Begin) - 1, Length>::Type;
        };

        template <SizeType Length, typename T, T HeadValue, T... TailValues>
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
    }

    template <typename T, SizeType Begin, SizeType Length>
    using SubPack = typename Implementation::SubPack<T, Begin, Length>::Type;



    namespace Implementation
    {
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
    }

    template <typename T>
    using Reverse = typename Implementation::Reverse<T>::Type;



    namespace Implementation
    {
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
    }

    template <typename Pack1, typename Pack2>
    using Zip = typename Implementation::Zip<Pack1, Pack2>::Type;



    namespace Implementation
    {
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

    template <typename Zipper, typename Pack1, typename Pack2>
    using ZipWith = typename Implementation::ZipWith<Zipper, Pack1, Pack2>::Type;

    template <template <typename, typename> typename ZipperImpl>
    struct MakeTypeZipper
    {
        template <typename First, typename Second>
        using Impl = ZipperImpl<First, Second>;
    };
}

#endif //MATHLIB_IMPLEMENTATION_BASE_PACKS_HPP
