#pragma once
#include "Matrix4x4.h"
#include "Quaternion.h"
#include "Vector3D.h"

namespace math
{
	Matrix4x4 ToTranslationMatrix(const Vector3D& v);
	Matrix4x4 ToRotationMatrix(const Quaternion& v);
	Matrix4x4 ToScaleMatrix(const Vector3D& v);

}
