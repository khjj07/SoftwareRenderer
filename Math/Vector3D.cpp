#include "Vector3D.h"

#include <cmath>

const math::Vector3D math::Vector3D::zero = math::Vector3D();
const math::Vector3D math::Vector3D::one = math::Vector3D(1.0f);
const math::Vector3D math::Vector3D::left = math::Vector3D(-1.0f, 0.0f, 0.0f);
const math::Vector3D math::Vector3D::right = math::Vector3D(1.0f, 0.0f, 0.0f);
const math::Vector3D math::Vector3D::up = math::Vector3D(0.0f, 1.0f, 0.0f);
const math::Vector3D math::Vector3D::down = math::Vector3D(0.0f, -1.0f, 0.0f);
const math::Vector3D math::Vector3D::forward = math::Vector3D(0.0f, 0.0f, 1.0f);
const math::Vector3D math::Vector3D::backward = math::Vector3D(0.0f, 0.0f, -1.0f);




math::Vector3D::Vector3D(const float& v) noexcept
	: x(v), y(v), z(v) {}

math::Vector3D::Vector3D(const float& x, const float& y, const float& z) noexcept
	: x(x), y(y), z(z) {}

math::Vector3D math::Vector3D::operator+(const Vector3D& v) const noexcept
{
	Vector3D temp(*this);
	temp.x += v.x;
	temp.y += v.y;
	temp.z += v.z;
	return *this;
}

math::Vector3D math::Vector3D::operator-(const Vector3D& v) const noexcept
{
	Vector3D temp(*this);
	temp.x -= v.x;
	temp.y -= v.y;
	temp.z -= v.z;
	return *this;
}

math::Vector3D math::Vector3D::operator*(const float& v) const noexcept
{
	Vector3D temp(*this);
	temp.x *= v;
	temp.y *= v;
	temp.z *= v;
	return *this;
}

math::Vector3D math::Vector3D::operator/(const float& v) const noexcept
{
	Vector3D temp(*this);
	temp.x /= v;
	temp.y /= v;
	temp.z /= v;
	return *this;
}

math::Vector3D& math::Vector3D::operator+=(const Vector3D& v) noexcept
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return *this;
}

math::Vector3D& math::Vector3D::operator-=(const Vector3D& v) noexcept
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return *this;
}

math::Vector3D& math::Vector3D::operator*=(const float v) noexcept
{
	this->x *= v;
	this->y *= v;
	this->z *= v;
	return *this;
}

math::Vector3D& math::Vector3D::operator/=(const float v) noexcept
{
	this->x /= v;
	this->y /= v;
	this->z /= v;
	return *this;
}

math::Vector3D& math::Vector3D::operator=(const Vector3D& v) noexcept
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return *this;
}

bool math::Vector3D::operator==(const Vector3D& v) noexcept
{
	return this->x == v.x && this->y == v.y && this->z == v.z;
}

float math::Vector3D::Length()
{
	return sqrt(x * x + y * y + z * z);
}

math::Vector3D math::Vector3D::Normalize()
{
	return *this / (Length());
}


