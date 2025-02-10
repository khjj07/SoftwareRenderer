#pragma once
#include "../Math/Vector4D.h"
#include "../Math/Vector2D.h"

namespace common
{
	using Color = math::Vector4D;
	struct Vertex
	{
		math::Vector4D position;
		Color color;
		math::Vector2D uv;
	};
}
