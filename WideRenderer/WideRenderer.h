#pragma once
#include <windows.h>
#include "../Common/IRenderer.h"
#include "../Common/Define.h"
#include "../Math/Matrix4x4.h"

namespace Renderer
{
	class WideSwapChain;

	class WideRendererAPI WideRenderer : public common::IRenderer
	{
	public:
		WideRenderer() = default;
		~WideRenderer() override;
		int Initialize(common::IWideWindow* window) override;
		int BeginRender() override;
		int EndRender() override;
		int Finalize() override;
		void Draw(common::RenderData* data, math::Matrix4x4 worldMatrix) override;

	private:
		void DrawMesh(common::Mesh* mesh,std::vector<common::Material*>* materials,const math::Matrix4x4& worldMatrix);
	private:
		common::IWideWindow* window_;
		WideSwapChain* swapchain_;
	};

	extern "C"
	{
		WideRendererAPI common::IRenderer* CreateRenderer();
	}
}
