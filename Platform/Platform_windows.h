#pragma once

#include <functional>
#include <string>
#include "../Common/Define.h"
#include "../Common/IPlatform.h"

namespace platform
{
	class PlatformAPI Platform : public common::IPlatform
	{
	public:
		common::IWideWindow* CreateWideWindow(std::wstring title, std::wstring iconName, int width, int height) override;
		void DestroyWideWindow(common::IWideWindow* window) override;
	
		common::IRenderer* CreateRenderer(common::IRenderer::Type type) override;
		int ReleaseRenderer(common::IRenderer* renderer) override;
		std::function<common::IRenderer*()> GetRenderFunction(const std::wstring& filePath);
	};
}
