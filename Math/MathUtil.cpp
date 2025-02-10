#include "MathUtil.h"

math::Matrix4x4 math::ToTranslationMatrix(const Vector3D& v)
{
	return Matrix4x4 {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		v.x,v.y,v.z,1
	};
}

math::Matrix4x4 math::ToRotationMatrix(const Quaternion& q)
{
    Matrix4x4 matrix;

    const float w2 = q.w * q.w;
    const float x2 = q.x * q.x;
    const float y2 = q.y * q.y;
    const float z2 = q.z * q.z;
    const float xy = q.x * q.y;
    const float xz = q.x * q.z;
    const float yz = q.y * q.z;
    const float wx = q.w * q.x;
    const float wy = q.w * q.y;
    const float wz = q.w * q.z;

    matrix.e00 = 1.0f - 2.0f * (y2 + z2);
    matrix.e01 = 2.0f * (xy + wz);
    matrix.e02 = 2.0f * (xz - wy);
    matrix.e03 = 0.0f;

    matrix.e10 = 2.0f * (xy - wz);
    matrix.e11 = 1.0f - 2.0f * (x2 + z2);
    matrix.e12 = 2.0f * (yz + wx);
    matrix.e13 = 0.0f;

    matrix.e20 = 2.0f * (xz + wy);
    matrix.e21 = 2.0f * (yz - wx);
    matrix.e22 = 1.0f - 2.0f * (x2 + y2);
    matrix.e23 = 0.0f;

    matrix.e30 = 0.0f;
    matrix.e31 = 0.0f;
    matrix.e32 = 0.0f;
    matrix.e33 = 1.0f;

    return matrix;

}

math::Matrix4x4 math::ToScaleMatrix(const Vector3D& v)
{
	return Matrix4x4{
	v.x,0,0,0,
	0,v.y,0,0,
	0,0,v.z,0,
	0,0,0,1
	};
}
