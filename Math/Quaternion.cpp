#include <cmath>
#include "Quaternion.h"

float math::Quaternion::Length() const noexcept
{
	return std::sqrtf(x * x + y * y + z * z + w * w);
}

float math::Quaternion::LengthSquare() const noexcept
{
	return x * x + y * y + z * z + w * w;
}
float math::Quaternion::FastInvSqrt(float number) const noexcept
{
	return 1 / std::sqrtf(number);
}
float math::Quaternion::Dot(const Quaternion& q) const noexcept
{
	return (this->w * q.w) + (this->x * q.x) + (this->y * q.y) + (this->z * q.z);
}

math::Quaternion math::Quaternion::Conjugate() const noexcept
{
	return Quaternion{ w, -x, -y, -z };
}

math::Quaternion math::Quaternion::Inverse() const noexcept
{
	float temp = LengthSquare();

	if (temp == 0.0f)
	{
		return *this;
	}

	float invSqrt = FastInvSqrt(temp);

	return Quaternion
	{
		w * invSqrt,
		-x * invSqrt,
		-y * invSqrt,
		-z * invSqrt
	};
}

math::Quaternion& math::Quaternion::Normalize() noexcept
{
	float temp = LengthSquare();

	if (temp == 0.0f)
	{
		return *this;
	}

	float invSqrt = FastInvSqrt(temp);
	(*this) *= invSqrt;

	return *this;
}

math::Quaternion math::Quaternion::Normalized() const noexcept
{
	Quaternion q(*this);

	return q.Normalize();
}

math::Quaternion& math::Quaternion::operator+=(const Quaternion& q) noexcept
{
	this->w += q.w;
	this->x += q.x;
	this->y += q.y;
	this->z += q.z;
	return *this;
}

math::Quaternion& math::Quaternion::operator-=(const Quaternion& q) noexcept
{
	this->w -= q.w;
	this->x -= q.x;
	this->y -= q.y;
	this->z -= q.z;
	return *this;
}

math::Quaternion math::Quaternion::operator+(const Quaternion& q) const noexcept
{
	Quaternion temp(*this);
	return temp += q;
}

math::Quaternion math::Quaternion::operator-(const Quaternion& q) const noexcept
{
	Quaternion temp(*this);
	return temp -= q;
}

math::Quaternion math::Quaternion::operator-() const noexcept
{
	return Quaternion
	{
		-this->w,
		-this->x,
		-this->y,
		-this->z
	};
}

math::Quaternion& math::Quaternion::operator*=(const Quaternion& q) noexcept
{
	// 해밀턴 곱
	float newW =
		this->w * q.w -
		this->x * q.x -
		this->y * q.y -
		this->z * q.z;

	float newX =
		this->w * q.x +
		this->x * q.w +
		this->y * q.z -
		this->z * q.y;

	float newY =
		this->w * q.y +
		this->y * q.w +
		this->z * q.x -
		this->x * q.z;

	float newZ =
		this->w * q.z +
		this->z * q.w +
		this->x * q.y -
		this->y * q.x ;

	this->w = newW;
	this->x = newX;
	this->y = newY;
	this->z = newZ;

	return *this;
}

math::Quaternion& math::Quaternion::operator/=(const Quaternion& q) noexcept
{
	Quaternion conjugate = q.Conjugate();
	float temp = q.LengthSquare();

	/// 사원수 나눗셈은 해당 사원수의 켤레를 곱하고
	*this *= conjugate;

	/// 크기의 제곱을 나눈 것과 같다.
	*this /= temp;

	return *this;
}

math::Quaternion math::Quaternion::operator*(const Quaternion& q) const noexcept
{
	Quaternion result = *this;
	result *= q;
	return result;
}

math::Quaternion math::Quaternion::operator/(const Quaternion& q) const noexcept
{
	Quaternion result = *this;
	result /= q;
	return result;
}

math::Quaternion& math::Quaternion::operator*=(const float n) noexcept
{
	this->w *= n;
	this->x *= n;
	this->y *= n;
	this->z *= n;
	return *this;
}

math::Quaternion& math::Quaternion::operator/=(const float n) noexcept
{
	float invN = 1.0f / n;

	this->w *= invN;
	this->x *= invN;
	this->y *= invN;
	this->z *= invN;
	return *this;
}

math::Quaternion math::Quaternion::operator*(const float n) const noexcept
{
	Quaternion result(*this);
	return result *= n;
}

math::Quaternion math::Quaternion::operator/(const float n) const noexcept
{
	Quaternion result(*this);
	return result /= n;
}

math::Quaternion math::operator*=(const float n, Quaternion& q) noexcept
{
	return q *= n;
}

math::Quaternion math::operator/=(const float n, Quaternion& q) noexcept
{
	return q /= n;
}

math::Quaternion math::operator*(const float n, Quaternion& q) noexcept
{
	return n *= q;
}

math::Quaternion math::operator/(const float n, Quaternion& q) noexcept
{
	return n /= q;
}

bool math::Quaternion::operator==(const Quaternion& q) const noexcept
{
	return (this->w == q.w && this->x == q.x && this->y == q.y && this->z == q.z);
}
