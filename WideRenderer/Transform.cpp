#include "Transform.h"

#include "../Math/MathUtil.h"

math::Matrix4x4 Transform::GetWorldMatrix()
{
	if(parent)
	{
		return GetLocalMatrix();
	}
	else
	{
		return GetLocalMatrix() * parent->GetLocalMatrix();
	}
}

math::Matrix4x4 Transform::GetLocalMatrix()
{
	return math::ToScaleMatrix(scale_) * math::ToRotationMatrix(rotation_) * math::ToTranslationMatrix(position_);
}

