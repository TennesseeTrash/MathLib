# MathLib

A work-in-progress C++20 math library.

Documentation is planned to live [here](https://3011.io/docs/MathLib/),
some text is written there, but it might be outdated and is still
woefully incomplete. This needs to be done before the v1.0 can come out.

Any comments or criticisms are welcome.

## Usage

Since this library is header-only, you can just copy the contents of
the `Include` directory into your include path. If you're using CMake,
it's probably easier to use FetchContent for this.

```cmake
include(FetchContent)

FetchContent_Declare(
    MathLib
    GIT_REPOSITORY https://github.com/3O11/MathLib
#   GIT_TAG        vX.X.X # - This will be relevant then there are actual releases
)
```

After that, you can just include the appropriate headers in your projects.

## Features planned and present

The library can be considered feature complete in terms of the basic objects
it offers, that includes Vectors, Matrices, Points, Transforms, and
Quaternions. The API of these features shouldn't change much going forward.
However, they are still mostly untested.

Known defects:
- The library does not compile under MSVC. This is caused primarily by some
of the more template heavy code related to functions. The only compiler
known to work well currently is Clang (15.0.0+, not sure about older ones).
- Some of the differentiable functions do not compile, because they
depend on `<cmath>` in a constexpr context (this might be supported in C++26).
A custom implementation of these functions is being investigated.

Missing/incomplete features:
- Functions and derivatives - Some functions and their derivatimes are
present. However, more complicated features such as multidimensional
functions with partial derivatives are not. There is also the problem
that the derivatives are implemented in a very naive manner, so there
are bound to be problems with numerical stability with more complicated
functions.
- Noise algorithms - A preliminary implementation of basic Perlin noise is
present, but it's missing useful things like derivatives. This is mostly
blocked by the previous point.
- Geometry - So far, the plan is to prepare some utilities to deal with
triangles, triangle meshes, and ray casts. Another good feature would be some
voxel related utilities, especially ray casts.

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
