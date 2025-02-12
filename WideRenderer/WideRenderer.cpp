#include <windows.h>
#include "../Common/Mesh.h"
#include "WideSwapChain.h"
#include "WideRenderer.h"

#include "Shader.h"


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

		for (auto material : data->GetMaterials())
		{
			DrawMesh(mesh,material,worldMatrix);
		}
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

void Renderer::WideRenderer::DrawMesh(common::Mesh* mesh, common::Material* material, const math::Matrix4x4& inMatrix)
{
	//Set Input Assembler 단계지만 거의 생략 
	auto vertices = mesh->GetVertices();
	auto indices = mesh->GetIndices();

	//Vertex Shader
	auto v_index = static_cast<renderer::VertexShader>(material->GetVertexShaderIndex()); //너무 길어서 축약..
	renderer::VS<v_index>(vertices, inMatrix); //왜 신텍스 에러가 나지?

	//Hull shader, Tesselator, Domain shader(생략)


	//Geomtry shader

	//Stream Output shader

	//Rasterizer

	//Pixel-shader  



}

common::IRenderer* Renderer::CreateRenderer()
{
	return new WideRenderer();
}
