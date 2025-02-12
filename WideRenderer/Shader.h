#pragma once
#include <vector>

#include "../Math/Matrix4x4.h"
#include "../Common/Vertex.h"


namespace renderer
{
	enum VertexShader
	{
		T1 = 0,

	};

	template <enum VertexShader T>
	void VS(std::vector<common::Vertex>& InVertices, const math::Matrix4x4& InMatrix)
	{
		static_assert("error");
	}

	template <>
	inline void VS<VertexShader::T1>(std::vector<common::Vertex>& InVertices, const math::Matrix4x4& InMatrix)
	{
		for (auto v : InVertices)
		{
			v.position = InMatrix * v.position;
		}
	}
	
	
}

