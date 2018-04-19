#pragma once
#include "Image.h"
#include "Keyboard.h"
namespace DX9
{
	class Game
	{
	public:
		struct Rota
		{
			Image image;
			MyClass::Vec2 vec2;
			MyClass::Box src;
			MyClass::Box draw;
			float r;
		}rota[16], me;

		KeyBoard key;
		void Init();
		void Run();
		void Draw();
		void Fin();

	};

}
