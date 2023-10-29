# MathLib

This is a header-only C++ math library intended primarily for use in graphics.
Currently, it's still considered unstable, but most of the core features are
solid enough to be considered complete, at least in terms of API.

Documentation is planned to live [here](https://3011.io/docs/MathLib/),
some text is written there, but it might be outdated and is still
woefully incomplete. This needs to be done before the v1.0 can come out.

Any questions, comments, criticism, bug reports, feature requests or pull
requests are welcome. Please use the GitHub issue system for this purpose.

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

The library is mostly complete in terms of the basic math that every competent
should have. Vectors and matrices are supported (in 2D, 3D and 4D variants)
along with quaternions.
More specific types such as point and transform are also implemented. These
make some additional assumptions to save space (up to 16B in Transform3f),
while hopefully keeping the similar performance.

Some parts missing parts are:
- Functions - There is no way to pass around functions, test for the presence
of a derivative, and get the derivative or a primitive function where
applicable.
- Noise algorithms - A preliminary implementation of basic Perlin noise is
implemented, but it's missing useful things like derivatives. This is
blocked by the previous point.
- Geometry - So far, the plan is to prepare some utilities to deal with
triangles, triangle meshes, and ray casts. Another good feature would be some
voxel related utilities, especially ray casts.

## Example

Here is a small example of what the library has to offer.

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

    // f32 is just an alias for float
    Math::f32 cosAngle = Dot(v4, v5); // Cross products are also present
}
```
