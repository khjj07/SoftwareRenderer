#pragma once
#include <string>


namespace common
{
	class Material
	{
	public:
		Material();
		void SetVertexShader(int n);
		void SetPixelShader(int n);
		int GetVertexShaderIndex();
		int GetPixelShaderIndex();

	private:
		int vertexShaderIndex_;
		int pixelShaderIndex_;
	};
}
