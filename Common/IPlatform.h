#pragma once
#include "IRenderer.h"
#include "IWideWindow.h"

namespace common
{
	class IPlatform
	{
	public:
		virtual ~IPlatform() = default;
		virtual IWideWindow* CreateWideWindow(std::wstring title, std::wstring iconName, int width, int height) = 0;
		virtual void DestroyWideWindow(IWideWindow* window) = 0;
		virtual IRenderer* CreateRenderer(IRenderer::Type type) = 0;
		virtual int ReleaseRenderer(IRenderer* renderer) = 0;
	};
}
