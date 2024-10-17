#ifndef MATHLIB_EXAMPLES_PATHTRACER_FRAMEBUFFER_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_FRAMEBUFFER_HPP

#include "Base.hpp"

#include <filesystem>

namespace fs = std::filesystem;

namespace PathTracer
{
    enum class ImageEncoding
    {
        HDR,
    };

    class Framebuffer
    {
    public:
        Framebuffer(SizeType width, SizeType height);
        Framebuffer(Vector2ul size);

        Vector2ul Size() const;

        void Add(const Framebuffer& other);
        void Scale(f32 scale);
        void Clear();

        bool Save(const fs::path& filename, ImageEncoding encoding = ImageEncoding::HDR) const;

        Vector3f& operator() (SizeType x, SizeType y);
        const Vector3f& operator() (SizeType x, SizeType y) const;
    private:
        SizeType mWidth;
        SizeType mHeight;
        std::vector<Vector3f> mBuffer;
    };
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_FRAMEBUFFER_HPP
