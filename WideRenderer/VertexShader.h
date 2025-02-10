#pragma once
#include <vector>

#include "../Math/Matrix4x4.h"
#include "../Common/Vertex.h"


namespace renderer
{
	namespace shader
	{
		void VS(std::vector<common::Vertex>& InVertices, const math::Matrix4x4& InMatrix)
		{
			for (auto v : InVertices)
			{
				v.position =  InMatrix * v.position;
			}
		}
	}
}

