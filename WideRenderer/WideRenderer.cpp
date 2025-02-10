#include <windows.h>
#include "../Common/Mesh.h"
#include "WideSwapChain.h"
#include "WideRenderer.h"


Renderer::WideRenderer::~WideRenderer()
{
}

int Renderer::WideRenderer::Initialize(common::IWideWindow* window)
{
	window_ = window;
	swapchain_ = new WideSwapChain(window, 2);
	return 0;
}

int Renderer::WideRenderer::BeginRender()
{
	return 0;
}

int Renderer::WideRenderer::EndRender()
{
	swapchain_->Present();
	return 0;
}

int Renderer::WideRenderer::Finalize()
{
	return 0;
}

void Renderer::WideRenderer::Draw(common::RenderData* data, math::Matrix4x4 worldMatrix)
{
	auto renderObject = data->GetRenderObject();
	
	switch (renderObject->GetType())
	{
	case common::RenderObject::Type::Mesh:
	{
		auto mesh = static_cast<common::Mesh*>(renderObject);
		DrawMesh(mesh,data->GetMaterials(), worldMatrix);
	}
	break;
	case common::RenderObject::Type::Sprite:

		break;
	case common::RenderObject::Type::Text:

		break;
	case common::RenderObject::Type::None:

		break;
	}
}

void Renderer::WideRenderer::DrawMesh(common::Mesh* mesh, std::vector<common::Material*>* materials, const math::Matrix4x4& inMatrix)
{
	mesh->GetVertices();
	mesh->GetIndices();
}

common::IRenderer* Renderer::CreateRenderer()
{
	return new WideRenderer();
}
