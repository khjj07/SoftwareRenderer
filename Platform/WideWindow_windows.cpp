#include <string>
#include <windows.h>
#include "../Common/IWideWindow.h"
#include "WideWindow_windows.h"

platform::WideWindow::WideWindow(std::wstring title, std::wstring iconName, int width, int height)
	:title_(title),iconName_(iconName),width_(width),height_(height), hInstance_(nullptr),hwnd_(nullptr)
{
	ZeroMemory(&msg_, sizeof(MSG));
}

common::IWideWindow::Handle platform::WideWindow::GetHandle()
{
	return hwnd_;
}

int platform::WideWindow::GetWidth()
{
	RECT rect;
	GetWindowRect(hwnd_, &rect);
	return rect.right - rect.left;
}

int platform::WideWindow::GetHeight()
{
	RECT rect;
	GetWindowRect(hwnd_, &rect);
	return rect.bottom - rect.top;
}

void platform::WideWindow::Destroy()
{
	DestroyWindow(hwnd_);
}

int platform::WideWindow::Initialize()
{
	HINSTANCE hInstance = GetModuleHandle(NULL);
	WNDCLASSEXW wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProcedure;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(NULL)); //아이콘은 추후 초기화
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = title_.c_str();
	wc.cbSize = sizeof(WNDCLASSEX);

	RegisterClassExW(&wc);

	hwnd_ = CreateWindowEx(WS_EX_APPWINDOW, title_.c_str(), title_.c_str(), WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, width_, height_, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd_, SW_SHOW);
	SetForegroundWindow(hwnd_);
	SetFocus(hwnd_);
	SetCursor(wc.hCursor);
	return 0;
}

int platform::WideWindow::Tick()
{
	if (PeekMessage(&msg_, NULL, 0, 0, PM_REMOVE))
	{
		if (msg_.message == WM_QUIT)
			return -1;

		TranslateMessage(&msg_);
		DispatchMessage(&msg_);
	}
	return 0;
}

LRESULT CALLBACK platform::WindowProcedure(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch (umsg)
	{
	case WM_SIZE:
		return 0;
	case WM_DESTROY:
		return 0;
	}
	return DefWindowProc(hwnd, umsg, wparam, lparam);
}