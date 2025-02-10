#pragma once
namespace common
{
	class IWideWindow
	{
	public:
		using Handle = void*;
		virtual Handle GetHandle() = 0;
		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;
		virtual void Destroy() = 0;
		virtual int Initialize() = 0;
		virtual int Tick() = 0;
	};
}
