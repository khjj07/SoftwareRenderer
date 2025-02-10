#include "Vector2D.h"

#include <cmath>

const math::Vector2D math::Vector2D::zero = math::Vector2D();
const math::Vector2D math::Vector2D::one = math::Vector2D(1.0f);
const math::Vector2D  math::Vector2D::left = math::Vector2D(-1.0f, 0.0f);
const math::Vector2D  math::Vector2D::right = math::Vector2D(1.0f, 0.0f);
const math::Vector2D  math::Vector2D::up = math::Vector2D(0.0f, 1.0f);
const math::Vector2D  math::Vector2D::down = math::Vector2D(0.0f, -1.0f);




math::Vector2D::Vector2D(const float& v) noexcept
	: x(v), y(v) {}

math::Vector2D::Vector2D(const float& x, const float& y) noexcept
	: x(x), y(y) {}

math::Vector2D math::Vector2D::operator+(const Vector2D& v) noexcept
{
	Vector2D temp(*this);
	temp.x += v.x;
	temp.y += v.y;
	return *this;
}

math::Vector2D math::Vector2D::operator-(const Vector2D& v) noexcept
{
	Vector2D temp(*this);
	temp.x -= v.x;
	temp.y -= v.y;
	return *this;
}

math::Vector2D math::Vector2D::operator*(const float& v) noexcept
{
	Vector2D temp(*this);
	temp.x *= v;
	temp.y *= v;
	return *this;
}

math::Vector2D math::Vector2D::operator/(const float& v) noexcept
{
	Vector2D temp(*this);
	temp.x /= v;
	temp.y /= v;

	return *this;
}

math::Vector2D& math::Vector2D::operator+=(const Vector2D& v) noexcept
{
	this->x += v.x;
	this->y += v.y;
	return *this;
}

math::Vector2D& math::Vector2D::operator-=(const Vector2D& v) noexcept
{
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}

math::Vector2D& math::Vector2D::operator*=(const float v) noexcept
{
	this->x *= v;
	this->y *= v;
	return *this;
}

math::Vector2D& math::Vector2D::operator/=(const float v) noexcept
{
	this->x /= v;
	this->y /= v;

	return *this;
}

bool math::Vector2D::operator==(const Vector2D& v) noexcept
{
	return this->x == v.x && this->y == v.y;
}

float math::Vector2D::Length()
{
	return sqrt(x * x + y * y);
}

math::Vector2D math::Vector2D::Normalize()
{
	return *this / (Length());
}


