#pragma once
#include "Vector4D.h"

namespace math
{
    struct Matrix4x4
    {
        union
        {
            struct
            {
                float e00, e01, e02, e03, e10, e11, e12, e13, e20, e21, e22, e23, e30, e31, e32, e33;
            };
            float m[4][4];
            Vector4D v[4];
        };


        Matrix4x4 Transpose() const;
        Matrix4x4 Inverse();
        float Determinant() noexcept;
        Matrix4x4 operator+ (const Matrix4x4&) const noexcept;
        Matrix4x4& operator+= (const Matrix4x4&) noexcept;
        Matrix4x4 operator- (const Matrix4x4&) const noexcept;
        Matrix4x4& operator-= (const Matrix4x4&) noexcept;
        Matrix4x4 operator* (const Matrix4x4&) const noexcept;
    	Vector4D operator*(const Vector4D& InVector) const;
        Matrix4x4& operator*= (const Matrix4x4&) noexcept;
    };

}
