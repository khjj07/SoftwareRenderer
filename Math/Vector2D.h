#pragma once

namespace math
{

	struct Vector2D
	{
		float x, y;

		const static Vector2D zero;
		const static Vector2D one;
		const static Vector2D left;
		const static Vector2D right;
		const static Vector2D up;
		const static Vector2D down;

		Vector2D() noexcept = default;
		Vector2D(const float& v) noexcept;
		Vector2D(const float& x, const float& y) noexcept;
		Vector2D(const Vector2D& other) noexcept = default;
		Vector2D(Vector2D&& other) noexcept = default;

		Vector2D operator+(const Vector2D& v) noexcept;
		Vector2D operator-(const Vector2D& v) noexcept;
		Vector2D operator*(const float& v) noexcept;
		Vector2D operator/(const float& v) noexcept;

		Vector2D& operator += (const Vector2D&) noexcept;
		Vector2D& operator -= (const Vector2D&) noexcept;
		Vector2D& operator *= (const float) noexcept;
		Vector2D& operator /= (const float) noexcept;

		bool operator==(const Vector2D& v) noexcept;

		float Length();
		Vector2D Normalize();

	};

}
