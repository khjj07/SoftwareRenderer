
#include <cassert>
#include <functional>
#include <filesystem>
#include <windows.h>

#include "Platform_windows.h"
#include "WideWindow_windows.h"
#define DLL_DIRECTORY_PATH L""


common::IWideWindow* platform::Platform::CreateWideWindow(std::wstring title, std::wstring iconName, int width,int height)
{
	auto window = new WideWindow(title, iconName, width, height);
	window->Initialize();
	return window;
}

void platform::Platform::DestroyWideWindow(common::IWideWindow* window)
{
	window->Destroy();
}

common::IRenderer* platform::Platform::CreateRenderer(common::IRenderer::Type type)
{
	std::wstring directoryPath = DLL_DIRECTORY_PATH;

	switch (type)
	{
	case common::IRenderer::WideRenderer:
		auto func = GetRenderFunction(directoryPath.append(L"WideRenderer.dll"));
		return func();
		break;
	}
	return nullptr;
}

int platform::Platform::ReleaseRenderer(common::IRenderer* renderer)
{
	renderer->Finalize();
	delete[] renderer;
	return 0;
}

std::function<common::IRenderer* ()> platform::Platform::GetRenderFunction(const std::wstring& filePath)
{
	std::filesystem::path path(filePath);
	HINSTANCE dllInstance = LoadLibrary(path.generic_wstring().c_str());
	auto func = reinterpret_cast<common::IRenderer * (*)()>(GetProcAddress(dllInstance, "CreateRenderer"));
	return func;
}