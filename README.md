# MathLib

A work-in-progress C++20 math library. Any testing, feedback, suggestions for improvements, or
pull requests are welcome.

Documentation is currently work in progress [here](https://3011.io/Documentation/MathLib/).

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


## Status

The library is feature complete in terms of the foundational facilities necessary for
a wide variety of tasks. Templates (and their instantiations) are ready for vectors,
(square) matrices, points, and transforms. These types already have most utilities made
and can be considered near stable.

There are also several "modules" of the library that are incomplete, but already somewhat
usable in their current state and major changes to the existing code are not planned at least
until after the first actual release. These include the random number utilities (`Math/Random.hpp`),
and geometry utilities. These modules will be only expanded without major modifications to existing code
(and API).

Finally, some parts of the library, such as `Math/Noise.hpp` are in very early stages. These
should be considered unstable and not fit for any practical purpose for now. The API is not final
and the implementations are not tested very well.

For more specific notes on what the library contains, and the implementation status,
please refer to the [documentation](https://3011.io/Documentation/MathLib/). The documentation
is incomplete for now, but it should cover most of the library soon.
