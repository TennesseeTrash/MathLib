# MathLib

This is a a small, header-only C++ math library for use in Computer Graphics.
The core of the library is implemented and its interface is most likely
stable at this point. However, things may still change at any point without
warning, because the library is still not well tested and bugs or unfortunate
design decisions may force changes in the future.

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
