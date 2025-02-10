#pragma once
#include <vector>
#include "Material.h"
#include "RenderObject.h"

namespace common
{
	class RenderData
	{

	public:
		RenderData(RenderObject* renderObject);
		RenderObject* GetRenderObject();
		void AddMaterial(Material* material);
		std::vector<common::Material*>* GetMaterials();

	private:
		RenderObject* renderObject_;
		std::vector<Material*> materials_;
	};
}
