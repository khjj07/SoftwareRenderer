#include "Matrix3x3.h"

math::Matrix3x3 math::Matrix3x3::Transpose()
{
	return Matrix3x3
	{
		e00, e10, e20,
		e01, e11, e21,
		e02, e12, e22
	};
}

math::Matrix3x3 math::Matrix3x3::Inverse()
{
	Matrix3x3 result{};

	float det = Determinant();

	if (det == 0.0f)
	{
		return result;
	}

	float invDet = 1.0f / det;

	result.e00 = (e11 * e22 - e21 * e12) * invDet;
	result.e01 = (e02 * e21 - e01 * e22) * invDet;
	result.e02 = (e01 * e12 - e02 * e11) * invDet;
	result.e10 = (e12 * e20 - e10 * e22) * invDet;
	result.e11 = (e00 * e22 - e02 * e20) * invDet;
	result.e12 = (e02 * e10 - e00 * e12) * invDet;
	result.e20 = (e10 * e21 - e11 * e20) * invDet;
	result.e21 = (e01 * e20 - e00 * e21) * invDet;
	result.e22 = (e00 * e11 - e01 * e10) * invDet;

	return result;
}

float math::Matrix3x3::Determinant() noexcept
{
	float det =
		e00 * (e11 * e22 - e21 * e12) -
		e01 * (e10 * e22 - e20 * e12) +
		e02 * (e10 * e21 - e20 * e11);

	return det;
}

math::Matrix3x3 math::Matrix3x3::operator+(const Matrix3x3& m) const noexcept
{
	Matrix3x3 temp(*this);
	return temp += m;
}

math::Matrix3x3& math::Matrix3x3::operator+=(const Matrix3x3& m) noexcept
{
	this->e00 += m.e00;
	this->e01 += m.e01;
	this->e02 += m.e02;

	this->e10 += m.e10;
	this->e11 += m.e11;
	this->e12 += m.e12;

	this->e20 += m.e20;
	this->e21 += m.e21;
	this->e22 += m.e22;
	return *this;
}

math::Matrix3x3 math::Matrix3x3::operator-(const Matrix3x3& m) const noexcept
{
	Matrix3x3 temp(*this);
	return temp -= m;
}

math::Matrix3x3& math::Matrix3x3::operator-=(const Matrix3x3& m) noexcept
{
	this->e00 -= m.e00;
	this->e01 -= m.e01;
	this->e02 -= m.e02;
	this->e10 -= m.e10;
	this->e11 -= m.e11;
	this->e12 -= m.e12;
	this->e20 -= m.e20;
	this->e21 -= m.e21;
	this->e22 -= m.e22;
	return *this;
}

math::Matrix3x3 math::Matrix3x3::operator*(const Matrix3x3& m) const noexcept
{
	Matrix3x3 temp(*this);
	return temp *= m;
}

math::Matrix3x3& math::Matrix3x3::operator*=(const Matrix3x3& m) noexcept
{
	(this->e00 *= m.e00 + this->e01 * m.e10 + this->e02 * m.e20);
	(this->e00 *= m.e01 + this->e01 * m.e11 + this->e02 * m.e21);
	(this->e00 *= m.e02 + this->e01 * m.e12 + this->e02 * m.e22);

	(this->e10 *= m.e00 + this->e11 * m.e10 + this->e12 * m.e20);
	(this->e10 *= m.e01 + this->e11 * m.e11 + this->e12 * m.e21);
	(this->e10 *= m.e02 + this->e11 * m.e12 + this->e12 * m.e22);

	(this->e20 *= m.e00 + this->e21 * m.e10 + this->e22 * m.e20);
	(this->e20 *= m.e01 + this->e21 * m.e11 + this->e22 * m.e21);
	(this->e20 *= m.e02 + this->e21 * m.e12 + this->e22 * m.e22); return *this;
}
