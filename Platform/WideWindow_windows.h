#pragma once
#include "../Common/Define.h"
namespace platform
{
	class PlatformAPI WideWindow : public common::IWideWindow
	{
	public:
		WideWindow(std::wstring title, std::wstring iconName, int width, int height);

	public:
		Handle GetHandle() override;
		int GetWidth() override;
		int GetHeight() override;
		void Destroy() override;
		int Initialize() override;
		int Tick() override;

	private:
		HINSTANCE hInstance_;
		HWND hwnd_;
		MSG msg_;
		std::wstring title_;
		std::wstring iconName_;
		int width_;
		int height_;
	};

	LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);
}
