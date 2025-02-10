#pragma once
#include "WideRenderer.h"

namespace Renderer
{
	class WideSwapChain
	{
	public:
		WideSwapChain(common::IWideWindow* window,size_t bufferCount);
		int Present();
	private:
		HDC frontBuffer_;
		HDC* backBuffer_;
		size_t bufferIndex_;
		size_t bufferCount_;

	};
}
