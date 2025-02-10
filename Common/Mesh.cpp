#include "Mesh.h"


common::Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<int>& indices)
{
	type_ = Type::Mesh;
	vertices_.assign(vertices.begin(), vertices.end());
	indices_.assign(indices.begin(), indices.end());
}

std::vector<common::Vertex> common::Mesh::GetVertices()
{
	return vertices_;
}

std::vector<int> common::Mesh::GetIndices()
{
	return indices_;
}
