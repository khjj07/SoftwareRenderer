#pragma once
#include "../Math/Matrix4x4.h"
#include "../Math/Quaternion.h"
#include "../Math/Vector3D.h"

class Transform
{
public:
	math::Matrix4x4 GetWorldMatrix();
	math::Matrix4x4 GetLocalMatrix();

private:
	math::Vector3D position_;
	math::Quaternion rotation_;
	math::Vector3D scale_;
	Transform* parent;
};
