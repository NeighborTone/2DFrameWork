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
	public: 
		Direct3D direct3d;
		DX9::Font font;
		struct Obj
		{
			Image image;
			MyClass::Vec2 vec2;
			MyClass::Box src;
			MyClass::Box draw;
		}rota[16];
	/*	struct Cursor
		{
			DX9::Texture tex;
			DX9::Sprite sprite;
			D3DXVECTOR2  pos;
		}cursor,back,hoge;*/

		DirectX() {};
		~DirectX() {};
		bool Init(System& win);
		void Update();
		void Draw();
	};
}
