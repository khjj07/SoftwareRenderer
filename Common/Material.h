#pragma once
#include <string>

namespace common
{
	class Material
	{
	public:
		Material(std::wstring shaderName);

	private:
		std::wstring shaderName_;
	};
}
