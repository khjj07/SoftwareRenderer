#include "Vector4D.h"
#include <cmath>

const math::Vector4D math::Vector4D::zero = math::Vector4D();
const math::Vector4D math::Vector4D::one = math::Vector4D(1.0f);


math::Vector4D::Vector4D(const float& v) noexcept
	: x(v), y(v), z(v), w(v) {}

math::Vector4D::Vector4D(const float& x, const float& y, const float& z, const float& w) noexcept
	: x(x), y(y), z(z), w(w) {}

math::Vector4D math::Vector4D::operator+(const Vector4D& v) noexcept
{
	Vector4D temp(*this);
	temp.x += v.x;
	temp.y += v.y;
	temp.z += v.z;
	temp.w += v.w;
	return *this;
}

math::Vector4D math::Vector4D::operator-(const Vector4D& v) noexcept
{
	Vector4D temp(*this);
	temp.x -= v.x;
	temp.y -= v.y;
	temp.z -= v.z;
	temp.w -= v.w;
	return *this;
}

math::Vector4D math::Vector4D::operator*(const float& v) noexcept
{
	Vector4D temp(*this);
	temp.x *= v;
	temp.y *= v;
	temp.z *= v;
	temp.w *= v;
	return *this;
}

math::Vector4D math::Vector4D::operator/(const float& v) noexcept
{
	Vector4D temp(*this);
	temp.x /= v;
	temp.y /= v;
	temp.z /= v;
	temp.w /= v;
	return *this;
}

math::Vector4D& math::Vector4D::operator+=(const Vector4D& v) noexcept
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	this->w += v.w;
	return *this;
}

math::Vector4D& math::Vector4D::operator-=(const Vector4D& v) noexcept
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	this->w -= v.w;
	return *this;
}

math::Vector4D& math::Vector4D::operator*=(const float v) noexcept
{
	this->x *= v;
	this->y *= v;
	this->z *= v;
	this->w *= v;
	return *this;
}

math::Vector4D& math::Vector4D::operator/=(const float v) noexcept
{
	this->x /= v;
	this->y /= v;
	this->z /= v;
	this->w /= v;
	return *this;
}

bool math::Vector4D::operator==(const Vector4D& v) noexcept
{
	return this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w;
}

float math::Vector4D::Length() const noexcept
{
	return sqrt(x * x + y * y + z * z + w * w);
}
 
math::Vector4D math::Vector4D::Normalize() noexcept
{
	return *this / (Length());
}

float math::Vector4D::Dot(const Vector4D& v) noexcept
{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}


