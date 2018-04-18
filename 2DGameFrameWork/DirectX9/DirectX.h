#pragma once
#include "DX9_Device.h"
#include "DX9_Texture.h"
#include "DX9_Font.h"
#include "DX9_Sprire.h"
#include "../System.h"
#include "../Image.h"
namespace DX9
{
	class DirectX
	{
	private:
		Direct3D direct3d;
	public: 
		
		DX9::Font font;
		struct Obj
		{
			Image image;
			MyClass::Vec2 vec2;
			MyClass::Box src;
			MyClass::Box draw;
		}rota[16];

		DirectX() {};
		~DirectX() {};
		bool Init(System& win);
		void Update();
		void Draw();
	};
}
