#pragma once
namespace common
{
	class RenderObject
	{
	public:
		enum class Type
		{
			Mesh,
			Sprite,
			Text,
			None
		};

	public:
		Type GetType();

	protected:
		Type type_ = Type::None;
	};
}

