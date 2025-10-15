#pragma once

namespace Engine
{
    namespace Math
    {
        struct Vector4
        {
            float x;
            float y;
            float z;
            float w;

            Vector4(float x, float y, float z, float w) :x(x), y(y), z(z), w(w) {}
            Vector4(float scalar) :x(scalar), y(scalar), z(scalar), w(scalar) {}

            Vector4 operator+(const Vector4& other) const
            {
                return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
            }
        };
    }
}


