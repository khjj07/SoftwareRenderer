#include "WideSwapChain.h"

Renderer::WideSwapChain::WideSwapChain(common::IWideWindow* window, size_t bufferCount)
{
	frontBuffer_ = GetDC(static_cast<HWND>(window->GetHandle()));
	
	bufferCount_ = bufferCount;
	backBuffer_ = new HDC[bufferCount_];
	for (size_t i = 0; i< bufferCount_; i++)
	{
		backBuffer_[i] = CreateCompatibleDC(frontBuffer_);
	}
}

int Renderer::WideSwapChain::Present()
{
	SwapBuffers(backBuffer_[bufferIndex_]);
	if(bufferCount_> bufferIndex_)
	{
		bufferIndex_++;
	}
	else
	{
		bufferIndex_ = 0;
	}
	return 0;
}
