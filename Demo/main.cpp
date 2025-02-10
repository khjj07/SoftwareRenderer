
#include <windows.h>
#include "../Platform/Platform_windows.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	platform::Platform platform;

	auto window = platform.CreateWideWindow(L"test", L"test", 1920, 1080);
	auto renderer = platform.CreateRenderer(common::IRenderer::Type::WideRenderer);
	renderer->Initialize(window);

	while(true)
	{
		window->Tick();
		renderer->BeginRender();

		renderer->EndRender();
	}

	platform.ReleaseRenderer(renderer);
	platform.DestroyWideWindow(window);
	return 0;
}
