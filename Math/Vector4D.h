#pragma once

namespace math
{
	struct Vector4D
	{
		float x, y, z, w;

		const static Vector4D zero;
		const static Vector4D one;

		Vector4D() noexcept = default;
		Vector4D(const float& v) noexcept;
		Vector4D(const float& x, const float& y, const float& z, const float& w) noexcept;
		Vector4D(const Vector4D& other) noexcept = default;
		Vector4D(Vector4D&& other) noexcept = default;

		Vector4D operator+(const Vector4D& v) noexcept;
		Vector4D operator-(const Vector4D& v) noexcept;
		Vector4D operator*(const float& v) noexcept;
		Vector4D operator/(const float& v) noexcept;

		Vector4D& operator += (const Vector4D&) noexcept;
		Vector4D& operator -= (const Vector4D&) noexcept;
		Vector4D& operator *= (const float) noexcept;
		Vector4D& operator /= (const float) noexcept;

		bool operator==(const Vector4D& v) noexcept;

		float Length() const noexcept;
		Vector4D Normalize() noexcept;
		float Dot(const Vector4D& v) noexcept;

	};

}

