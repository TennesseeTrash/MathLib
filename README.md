This is an attempt at a small, header-only C++ math library for use in
Computer Graphics. It aims to provide basic primitives, such as Vectors,
Matrices and Points that are useful in any work related to graphics.

It is currently very much work in progress and mostly untested. Even if if
was complete, it would still probably be wiser to use more battle-tested
libraries, such as [GLM](https://github.com/g-truc/glm) or
[Terathon Math](https://github.com/EricLengyel/Terathon-Math-Library) in your
projects. Please also keep in mind that as the library continues to get
updated, many things may change unexpectedly.

Any bug reports, feature requests or pull requests are welcome!

## Implementation status

Currently, Vector and Matrix types are mostly implemented, but untested.
There are some tests, but they are far form satisfactory.

The following list is in no particular order of importance. All of the
features on this list are important for this library to be of proper use.

- [ ] Point types
- [ ] Useful functions (some are present, but the bulk is yet to be implemented)
- [ ] Documentation
- [ ] Tests (basic interface tests, fuzz tests)
- [ ] Basic transforms (Rotate, Translate, Scale)
- [ ] Camera transforms (Perspective, Orthographic projection)
- [x] Coordinate frames
- [x] Vector types
- [x] Matrix types
- [x] Useful constants

## Documentation

The library is mostly self-explanatory and small enough
for the source code itself to act as documentation of sorts,
but proper documentation will live on my website at some point.

## Motivation

I wanted to try my hand at writing a small library that would be useful for me
in the field that I am most interested in, that is Computer Graphics. Another
reason was because I believe that libraries like GLM are a bit too convoluted
in their implementation. They are implemented through many templated
abstractions and/or implement difficult features like swizzling.
