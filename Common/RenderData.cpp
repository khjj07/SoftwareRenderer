#include "RenderData.h"


common::RenderData::RenderData(RenderObject* renderObject)
	:renderObject_(renderObject)
{

}

common::RenderObject* common::RenderData::GetRenderObject()
{
	return renderObject_;
}

void common::RenderData::AddMaterial(Material* material)
{

}

std::vector<common::Material*>* common::RenderData::GetMaterials()
{
	return &materials_;
}
