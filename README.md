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

This is an _unordered_ list of things that still need work. For now, the
library is still nowhere near a release, and should be considered unstable.

#### Known defects:
- The library does not compile under MSVC. This is caused primarily by some
of the more template heavy code related to functions. The only compiler
known to work well currently is Clang (15.0.0+, not sure about older ones).
- Some differentiable functions do not compile, because they
depend on `<cmath>` in a constexpr context (this might be supported in C++26).
A custom implementation of these functions is planned.
- Documentation doesn't exist. This library is still very incomplete, so any
documentation would go out of date incredibly quickly, because many things are
still changing even in very core parts of the library. For now, the best way
to know what the library can offer is to look at the source code. This is
not ideal, but the code is simple enough for the most part that this shouldn't
be a problem.
- Tests are woefully incomplete. The tests are there and can serve as a bit of
a sanity check that the library at least compiles, but they are nowhere near
comprehensive enough to provide any real certainty that the library will
actually work properly.
- No real examples are included.

#### Missing/incomplete features:
- Functions and derivatives - Multidimensional functions are missing.
This could be solved via tagging, the exact implementation is still
not certain.
- Noise algorithms - There is a basic implementation of Perlin noise,
but other useful noise algorithms (other Perlin variants, Worley nouse)
are not done yet. These will be implemented once the API is finished.
- Geometry - The plan is to prepare the basic primitives, such as rays and
shapes (maybe even basic acceleration structures), in a way where they don't
limit the design of potential renderers that use them. The primary use case
would be CPU renderers. More complicated geometry tools, such as mesh optimization
will likely be out of scope for this library.
- Random - A few pseudorandom number generators have been implemented based on
the [incredible work](http://prng.di.unimi.it/) of Sebastiano Vigna and
David Blackman, but a lot of tooling for ease of use around these is still missing.

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
