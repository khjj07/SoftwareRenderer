#pragma once
#include "RenderData.h"
#include "RenderObject.h"
#include "Vertex.h"

namespace common
{
	class Mesh : public RenderObject
	{
	public:
		Mesh(const std::vector<Vertex>&, const std::vector<int>&);
		std::vector<Vertex> GetVertices();
		std::vector<int> GetIndices();
		
	private:
		std::vector<Vertex> vertices_;
		std::vector<int> indices_;
	};
}
