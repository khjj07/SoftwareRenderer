#pragma once
namespace math
{
	struct Quaternion
	{
		union
		{
			struct 
			{
				float w, x, y, z;
			};
			float e[4];
		};
		static inline Quaternion Identity() noexcept
		{
			return Quaternion{ 1.f, 0.f, 0.f, 0.f };
		}

		/// <summary>
		/// 쿼터니언 함수
		/// </summary>
		float Length() const noexcept;
		float LengthSquare() const noexcept;
		float FastInvSqrt(float number) const noexcept;
		float Dot(const Quaternion&) const noexcept;

		Quaternion Conjugate() const noexcept;
		Quaternion Inverse() const noexcept;
		Quaternion& Normalize() noexcept;
		Quaternion Normalized() const noexcept;

		Quaternion& operator += (const Quaternion&) noexcept;
		Quaternion& operator -= (const Quaternion&) noexcept;

		Quaternion operator + (const Quaternion&) const noexcept;
		Quaternion operator - (const Quaternion&) const noexcept;
		Quaternion operator - () const noexcept;

		Quaternion& operator *= (const Quaternion&) noexcept;
		Quaternion& operator /= (const Quaternion&) noexcept;

		Quaternion operator * (const Quaternion&) const noexcept;
		Quaternion operator / (const Quaternion&) const noexcept;

		Quaternion& operator *= (const float) noexcept;
		Quaternion& operator /= (const float) noexcept;

		Quaternion operator * (const float) const noexcept;
		Quaternion operator / (const float) const noexcept;

		friend Quaternion operator *= (const float, Quaternion&) noexcept;
		friend Quaternion operator /= (const float, Quaternion&) noexcept;

		friend Quaternion operator * (const float, Quaternion&) noexcept;
		friend Quaternion operator / (const float, Quaternion&) noexcept;

		bool operator == (const Quaternion&) const noexcept;
	};
}

