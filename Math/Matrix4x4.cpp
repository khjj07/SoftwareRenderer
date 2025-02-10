#include "Matrix4x4.h"

math::Matrix4x4 math::Matrix4x4::Transpose() const
{
    return Matrix4x4
    {
        e00, e10, e20, e30,
        e01, e11, e21, e31,
        e02, e12, e22, e32,
        e03, e13, e23, e33
    };
}

math::Matrix4x4 math::Matrix4x4::Inverse()
{
    Matrix4x4 result{};

    float det = Determinant();

    if (det == 0.0f)
    {
    	return result;
    }

    float invDet = 1.0f / det;
    result.e00 = (e12 * e23 * e31 - e13 * e22 * e31 + e13 * e21 * e32 - e11 * e23 * e32 - e12 * e21 * e33 + e11 * e22 * e33) * invDet;
    result.e01 = (e03 * e22 * e31 - e02 * e23 * e31 - e03 * e21 * e32 + e01 * e23 * e32 + e02 * e21 * e33 - e01 * e22 * e33) * invDet;
    result.e02 = (e02 * e13 * e31 - e03 * e12 * e31 + e03 * e11 * e32 - e01 * e13 * e32 - e02 * e11 * e33 + e01 * e12 * e33) * invDet;
    result.e03 = (e03 * e12 * e21 - e02 * e13 * e21 - e03 * e11 * e22 + e01 * e13 * e22 + e02 * e11 * e23 - e01 * e12 * e23) * invDet;
    result.e10 = (e13 * e22 * e30 - e12 * e23 * e30 - e13 * e20 * e32 + e10 * e23 * e32 + e12 * e20 * e33 - e10 * e22 * e33) * invDet;
    result.e11 = (e02 * e23 * e30 - e03 * e22 * e30 + e03 * e20 * e32 - e00 * e23 * e32 - e02 * e20 * e33 + e00 * e22 * e33) * invDet;
    result.e12 = (e03 * e12 * e30 - e02 * e13 * e30 - e03 * e10 * e32 + e00 * e13 * e32 + e02 * e10 * e33 - e00 * e12 * e33) * invDet;
    result.e13 = (e02 * e13 * e20 - e03 * e12 * e20 + e03 * e10 * e22 - e00 * e13 * e22 - e02 * e10 * e23 + e00 * e12 * e23) * invDet;
    result.e20 = (e11 * e23 * e30 - e13 * e21 * e30 + e13 * e20 * e31 - e10 * e23 * e31 - e11 * e20 * e33 + e10 * e21 * e33) * invDet;
    result.e21 = (e03 * e21 * e30 - e01 * e23 * e30 - e03 * e20 * e31 + e00 * e23 * e31 + e01 * e20 * e33 - e00 * e21 * e33) * invDet;
    result.e22 = (e01 * e13 * e30 - e03 * e11 * e30 + e03 * e10 * e31 - e00 * e13 * e31 - e01 * e10 * e33 + e00 * e11 * e33) * invDet;
    result.e23 = (e03 * e11 * e20 - e01 * e13 * e20 - e03 * e10 * e21 + e00 * e13 * e21 + e01 * e10 * e23 - e00 * e11 * e23) * invDet;
    result.e30 = (e12 * e21 * e30 - e11 * e22 * e30 - e12 * e20 * e31 + e10 * e22 * e31 + e11 * e20 * e32 - e10 * e21 * e32) * invDet;
    result.e31 = (e01 * e22 * e30 - e02 * e21 * e30 + e02 * e20 * e31 - e00 * e22 * e31 - e01 * e20 * e32 + e00 * e21 * e32) * invDet;
    result.e32 = (e02 * e11 * e30 - e01 * e12 * e30 - e02 * e10 * e31 + e00 * e12 * e31 + e01 * e10 * e32 - e00 * e11 * e32) * invDet;
    result.e33 = (e01 * e12 * e20 - e02 * e11 * e20 + e02 * e10 * e21 - e00 * e12 * e21 - e01 * e10 * e22 + e00 * e11 * e22) * invDet;

    return result;
}

float math::Matrix4x4::Determinant() noexcept
{
    float det =
        e00 * e11 * e22 * e33 +
        e00 * e12 * e23 * e31 +
        e00 * e13 * e21 * e32 +
        e01 * e10 * e23 * e32 +
        e01 * e12 * e20 * e33 +
        e01 * e13 * e22 * e30 +
        e02 * e10 * e21 * e33 +
        e02 * e11 * e23 * e30 +
        e02 * e13 * e20 * e31 +
        e03 * e10 * e22 * e31 +
        e03 * e11 * e20 * e32 +
        e03 * e12 * e21 * e30 -
        e00 * e11 * e23 * e32 -
        e00 * e12 * e21 * e33 -
        e00 * e13 * e22 * e31 -
        e01 * e10 * e22 * e33 -
        e01 * e12 * e23 * e30 -
        e01 * e13 * e20 * e32 -
        e02 * e10 * e23 * e31 -
        e02 * e11 * e20 * e33 -
        e02 * e13 * e21 * e30 -
        e03 * e10 * e21 * e32 -
        e03 * e11 * e22 * e30 -
        e03 * e12 * e20 * e31;
    return det;
}

math::Matrix4x4 math::Matrix4x4::operator+(const Matrix4x4& m) const noexcept
{
	math::Matrix4x4 temp(*this);
	return temp += m;
}

math::Matrix4x4& math::Matrix4x4::operator+=(const Matrix4x4& m) noexcept
{
    this->e00 += m.e00;
    this->e01 += m.e01;
    this->e02 += m.e02;
    this->e03 += m.e03;

    this->e10 += m.e10;
    this->e11 += m.e11;
    this->e12 += m.e12;
    this->e13 += m.e13;

    this->e20 += m.e20;
    this->e21 += m.e21;
    this->e22 += m.e22;
    this->e23 += m.e23;

    this->e30 += m.e30;
    this->e31 += m.e31;
    this->e32 += m.e32;
    this->e33 += m.e33;
    return (*this);
}

math::Matrix4x4 math::Matrix4x4::operator-(const Matrix4x4& m) const noexcept
{
	Matrix4x4 temp(*this);
	return temp -= m;
}

math::Matrix4x4& math::Matrix4x4::operator-=(const Matrix4x4& m) noexcept
{
    this->e00 -= m.e00;
    this->e01 -= m.e01;
    this->e02 -= m.e02;
    this->e03 -= m.e03;
                 
    this->e10 -= m.e10;
    this->e11 -= m.e11;
    this->e12 -= m.e12;
    this->e13 -= m.e13;
                 
    this->e20 -= m.e20;
    this->e21 -= m.e21;
    this->e22 -= m.e22;
    this->e23 -= m.e23;
                 
    this->e30 -= m.e30;
    this->e31 -= m.e31;
    this->e32 -= m.e32;
    this->e33 -= m.e33;
    return (*this);
}

math::Matrix4x4 math::Matrix4x4::operator*(const math::Matrix4x4& m) const noexcept
{
	math::Matrix4x4 temp(*this);
	return temp *= m;
}

math::Matrix4x4& math::Matrix4x4::operator*=(const Matrix4x4& m) noexcept
{
    Matrix4x4 result(*this);

    this->e00 = result.e00 * m.e00 + result.e01 * m.e10 + result.e02 * m.e20 + result.e03 * m.e30;
    this->e01 = result.e00 * m.e01 + result.e01 * m.e11 + result.e02 * m.e21 + result.e03 * m.e31;
    this->e02 = result.e00 * m.e02 + result.e01 * m.e12 + result.e02 * m.e22 + result.e03 * m.e32;
    this->e03 = result.e00 * m.e03 + result.e01 * m.e13 + result.e02 * m.e23 + result.e03 * m.e33;

    this->e10 = result.e10 * m.e00 + result.e11 * m.e10 + result.e12 * m.e20 + result.e13 * m.e30;
    this->e11 = result.e10 * m.e01 + result.e11 * m.e11 + result.e12 * m.e21 + result.e13 * m.e31;
    this->e12 = result.e10 * m.e02 + result.e11 * m.e12 + result.e12 * m.e22 + result.e13 * m.e32;
    this->e13 = result.e10 * m.e03 + result.e11 * m.e13 + result.e12 * m.e23 + result.e13 * m.e33;

    this->e20 = result.e20 * m.e00 + result.e21 * m.e10 + result.e22 * m.e20 + result.e23 * m.e30;
    this->e21 = result.e20 * m.e01 + result.e21 * m.e11 + result.e22 * m.e21 + result.e23 * m.e31;
    this->e22 = result.e20 * m.e02 + result.e21 * m.e12 + result.e22 * m.e22 + result.e23 * m.e32;
    this->e23 = result.e20 * m.e03 + result.e21 * m.e13 + result.e22 * m.e23 + result.e23 * m.e33;

    this->e30 = result.e30 * m.e00 + result.e31 * m.e10 + result.e32 * m.e20 + result.e33 * m.e30;
    this->e31 = result.e30 * m.e01 + result.e31 * m.e11 + result.e32 * m.e21 + result.e33 * m.e31;
    this->e32 = result.e30 * m.e02 + result.e31 * m.e12 + result.e32 * m.e22 + result.e33 * m.e32;
    this->e33 = result.e30 * m.e03 + result.e31 * m.e13 + result.e32 * m.e23 + result.e33 * m.e33;
    return (*this);
}

math::Vector4D math::Matrix4x4::operator*(const Vector4D& InVector) const
{
    Matrix4x4 transposedMatrix = Transpose();
    return Vector4D(
        transposedMatrix.v[0].Dot(InVector),
        transposedMatrix.v[1].Dot(InVector),
        transposedMatrix.v[2].Dot(InVector),
        transposedMatrix.v[3].Dot(InVector)
    );
}
