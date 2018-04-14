#pragma once
#include "DX9_Device.h"
#include "DX9_Texture.h"
#include "DX9_Font.h"
#include "DX9_Sprire.h"
#include "../System.h"
namespace DX9
{
	class DirectX
	{
	public: 
		DX9::Direct3D direct3d;
		DX9::Font font;
		DX9::Texture tex;
		DX9::Sprite sprite;
		DirectX() {};
		~DirectX() {};
		bool Init(System& win);
		void Update();
		void Draw();
	};
}
