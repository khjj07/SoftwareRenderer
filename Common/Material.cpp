#include "Material.h"

common::Material::Material()
{

}

void common::Material::SetVertexShader(int n)
{
	vertexShaderIndex_ = n;
}

void common::Material::SetPixelShader(int n)
{
	pixelShaderIndex_ = n;
}

int common::Material::GetVertexShaderIndex()
{
	return vertexShaderIndex_;
}

int common::Material::GetPixelShaderIndex()
{
	return pixelShaderIndex_;
}
