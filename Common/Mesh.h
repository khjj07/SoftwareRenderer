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
		std::vector<size_t> GetIndices();
		
	private:
		std::vector<Vertex> vertices_;
		std::vector<size_t> indices_;
	};
}
