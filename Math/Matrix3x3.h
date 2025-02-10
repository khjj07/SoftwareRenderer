#pragma once
namespace math
{
    struct Matrix3x3
    {
	    union
	    {
            struct
            {
                float e00, e01, e02, e10, e11, e12, e20, e21, e22;
            };
            float m[3][3];
	    };
       

        Matrix3x3 Transpose();
        Matrix3x3 Inverse();
        float Determinant() noexcept;
        Matrix3x3 operator+ (const Matrix3x3&) const noexcept;
        Matrix3x3& operator+= (const Matrix3x3&) noexcept;
        Matrix3x3 operator- (const Matrix3x3&) const noexcept;
        Matrix3x3& operator-= (const Matrix3x3&) noexcept;
        Matrix3x3 operator* (const Matrix3x3&) const noexcept;
        Matrix3x3& operator*= (const Matrix3x3&) noexcept;
    };

}
