# MathLib

A work-in-progress C++20 math library. Any comments or criticisms are welcome.

## Usage

Since this library is header-only, you can just copy the contents of
the `Include` directory into your include path. If you're using CMake,
it's probably better to use FetchContent for this, to make it easier to
update to newer versions.

```cmake
if(NOT TARGET MathLib)
    include(FetchContent)

    FetchContent_Declare(
        MathLib
        GIT_REPOSITORY https://github.com/3O11/MathLib
    #   GIT_TAG        vX.X.X # - This will be relevant then there are actual releases
    )

    FetchContent_MakeAvailable(
        MathLib
    )
endif()
```

For now, consider using a specific commit hash as the `GIT_TAG` to prevent
a nasty surprise when a breaking change occurs in newest commits.

After that, you can just include the appropriate headers in your projects.

```cpp
// This makes the Math::Vector3f type (and others) available.
#include <Math/Vector.hpp>
```

## Roadmap

The library can be considered complete in terms of the basics. The usual
core types, such as Vectors and Matrices are implemented and work (for my purposes at least).
Some extra utilities are also present, such as a few `constexpr` compatible
RNGs and a uniform distribution adapter (in the C++11 `<random>` style) to make them more useful.

The library was written with easy *static* extensibility in mind, which means that most utilities
are not implemented in terms of specific types, but in terms of concepts, such that you can use
them for your own types as long as they satisfy the concept. The most unfortunate exception to this are
the utility functions for transforms, because C++ cannot deduce template arguments for return types
(apart from a trick with conversion operators that I've found a bit too clunky to actually use).

Everything in the library is a near-POD type, the only condition it fails is that the default constructor
does zero initialization (if the committee has any sense, this will be default in C++26 anyway).
On top of that, there are no dynamic allocations, but everything should be compatible with dynamic allocations
if you need them. A (sort of) side effect of that is that no error checking is performed, you need to do all
potential error checking yourself. For example, if you try to calculate the inverse of a singular matrix,
you will get garbage in the result.

All that said, the library still isn't in a state where it can be considered complete or finished.
A small mountain of utilities is still missing, incomplete or implemented poorly. The random numbers could
use a few more distributions, because there are fairly common cases when uniform distribution just doesn't cut it
and implementing other distributions correctly is a pain.

There is also a section of the library dedicated to geometry. Some 2D shapes with a few utilities are implemented, but
a lot is still missing (outline intersections, distance, projections etc.). 3D geometry is sadly still far, far away from
becoming reality.

Another section that still needs work is related to noise functions and functions in general. There was a proof-of-concept
implementation of differentiable functions at one point, but it was a gargantuan mess of templates that wasn't particularly
useful. A better implementation is currently work in progress. As for the noise functions, the main idea is that they
should be useable standalone, but compatible with the differentiable functions. So far an initial Perlin noise implementation
is present and I have a few other noise functions implemented in a private "experimental" sandbox, but it would be better
to add the proper groundwork for reasonable differentiable functions first before adding them here.


## Example

Below is a small example of what the library has to offer. Larger and more
practical examples are in [Examples](Examples/)

```cpp
#include <Math/Vector.hpp>
#include <Math/Matrix.hpp>

int main()
{
    Math::Vector3f v1(4.0f); // All values initialized to 4.0f
    Math::Vector3f v2(1.0f, 2.0f, 3.0f);

    Math::Vector3f v3 = v1 + v2; // Other arithmetic operations are also supported

    Math::Matrix3f m1(1.0f); // Identity matrix
    Math::Matrix3f m2(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    );

    Math::Matrix3f m3 = m1 * m2; // Some other arithmetic operations are also supported

    Math::Vector3f v4 = m3 * v3; // Preferred
    Math::Vector3f v5 = v3 * m3; // Also possible, but potentially slower

    // f32 is a custom wrapper for floats, use ToUnderlying(cosAngle) to convert to float.
    Math::f32 cosAngle = Dot(v4, v5); // Cross products are also present
}
```
