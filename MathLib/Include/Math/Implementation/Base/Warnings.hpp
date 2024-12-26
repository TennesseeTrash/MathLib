#ifndef MATHLIB_IMPLEMENTATION_BASE_WARNINGS_HPP
#define MATHLIB_IMPLEMENTATION_BASE_WARNINGS_HPP

#if defined(__clang__)
#   define MATH_APPLY_PRAGMA(x) _Pragma(#x)
#else
#   define MATH_APPLY_PRAGMA(x)
#endif

#define MATH_NO_WARN(Warning, ...)                         \
        MATH_APPLY_PRAGMA(clang diagnostic push)             \
        MATH_APPLY_PRAGMA(clang diagnostic ignored #Warning) \
        __VA_ARGS__                                        \
        MATH_APPLY_PRAGMA(clang diagnostic pop)

#endif //MATHLIB_IMPLEMENTATION_BASE_WARNINGS_HPP
