#pragma once
namespace math
{
	struct Vector3D
	{
		float x, y, z;

		const static Vector3D zero;
		const static Vector3D one;
		const static Vector3D left;
		const static Vector3D right;
		const static Vector3D up;
		const static Vector3D down;
		const static Vector3D forward;
		const static Vector3D backward;

		Vector3D() noexcept = default;
		Vector3D(const float& v) noexcept;
		Vector3D(const float& x, const float& y, const float& z) noexcept;
		Vector3D(const Vector3D& other) noexcept = default;
		Vector3D(Vector3D&& other) noexcept = default;

		Vector3D operator+(const Vector3D& v) const noexcept;
		Vector3D operator-(const Vector3D& v) const noexcept;
		Vector3D operator*(const float& v) const noexcept;
		Vector3D operator/(const float& v) const noexcept;

		Vector3D& operator += (const Vector3D&) noexcept;
		Vector3D& operator -= (const Vector3D&) noexcept;
		Vector3D& operator *= (const float) noexcept;
		Vector3D& operator /= (const float) noexcept;

		Vector3D& operator = (const Vector3D&) noexcept;

		bool operator==(const Vector3D& v) noexcept;

		float Length();
		Vector3D Normalize();

	};
}

