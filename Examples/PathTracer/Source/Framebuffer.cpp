#include "Framebuffer.hpp"

#include <cmath>
#include <fstream>

namespace PathTracer
{
    Framebuffer::Framebuffer(SizeType width, SizeType height)
        : mWidth(width), mHeight(height), mBuffer(Math::ToUnderlying(width * height), Vector3f(0.0f))
    {}

    Framebuffer::Framebuffer(Vector2ul size)
        : mWidth(size.x), mHeight(size.y), mBuffer(Math::ToUnderlying(size.x * size.y), Vector3f(0.0f))
    {}

    Vector2ul Framebuffer::Size() const
    {
        return { mWidth, mHeight };
    }

    void Framebuffer::Add(const Framebuffer& other)
    {
        for (SizeType i = 0; i < mBuffer.size(); ++i)
        {
            mBuffer[Math::ToUnderlying(i)] += other.mBuffer[Math::ToUnderlying(i)];
        }
    }

    void Framebuffer::Scale(f32 scale)
    {
        for (SizeType i = 0; i < mBuffer.size(); ++i)
        {
            mBuffer[Math::ToUnderlying(i)] *= scale;
        }
    }

    void Framebuffer::Clear()
    {
        mBuffer.assign(mBuffer.size(), Vector3f(0.0f));
    }

    bool Framebuffer::Save(const fs::path& filename, ImageEncoding encoding) const
    {
        std::ofstream image(filename, std::ios::trunc | std::ios::binary);

        if (!image)
        {
            return false;
        }

        image << "#?RADIANCE\n";
        image << "FORMAT=32-bit_rle_rgbe\n\n";
        image << "-Y " << Math::ToUnderlying(Math::Cast<u32>(mWidth)) << ' '
              << "+X " << Math::ToUnderlying(Math::Cast<u32>(mHeight)) << '\n';

        for (SizeType j = 0; j < mHeight; ++j)
        {
            for (SizeType i = 0; i < mWidth; ++i)
            {
                const Vector3f& pixel = (*this)(i, j);
                Math::Array<u8, 4> rgbe = { 0, 0, 0, 0 };

                f32 value = Math::Max(pixel);

                if (value >= 1e-32f)
                {
                    int exp;
                    value = std::frexp(Math::ToUnderlying(value), &exp) * (256.0f / value);

                    rgbe[0] = Math::ToUnderlying(Math::Cast<u8>(pixel.x * value));
                    rgbe[1] = Math::ToUnderlying(Math::Cast<u8>(pixel.y * value));
                    rgbe[2] = Math::ToUnderlying(Math::Cast<u8>(pixel.z * value));
                    rgbe[3] = Math::ToUnderlying(Math::Cast<u8>(exp + 128));
                }

                image.write(reinterpret_cast<const char *>(rgbe.Data()), Math::ToUnderlying(rgbe.Size));
            }
        }

        image.close();

        return true;
    }

    Vector3f& Framebuffer::operator() (SizeType x, SizeType y)
    {
        return mBuffer[Math::ToUnderlying(mWidth * y + x)];
    }

    const Vector3f& Framebuffer::operator() (SizeType x, SizeType y) const
    {
        return mBuffer[Math::ToUnderlying(mWidth * y + x)];
    }
}
