#ifndef MATHLIB_EXAMPLES_PATHTRACER_FRAMEBUFFER_HPP
#define MATHLIB_EXAMPLES_PATHTRACER_FRAMEBUFFER_HPP

#include "Base.hpp"

#include <vector>
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

        bool Save(const fs::path& filename, ImageEncoding encoding = ImageEncoding::HDR) const;

        void Clear();

        Vector3f& operator() (SizeType x, SizeType y);
        const Vector3f& operator() (SizeType x, SizeType y) const;

    private:
        SizeType mWidth;
        SizeType mHeight;
        std::vector<Vector3f> mBuffer;
    };
}

#endif //MATHLIB_EXAMPLES_PATHTRACER_FRAMEBUFFER_HPP
