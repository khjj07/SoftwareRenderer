#pragma once
#include "IWideWindow.h"
#include "RenderData.h"

namespace math
{
	struct Matrix4x4;
}

namespace common
{
	class IRenderer
	{
	public:
		virtual ~IRenderer() = default;

		enum Type
		{
			WideRenderer,
			DX11, //나중에 구현을 목표
			None
		};

		virtual int Initialize(IWideWindow* window) = 0;
		virtual void Draw(RenderData* data, math::Matrix4x4 worldMatrix) = 0;
		virtual int BeginRender() = 0;
		virtual int EndRender() = 0;
		virtual int Finalize() = 0;
	};
}
