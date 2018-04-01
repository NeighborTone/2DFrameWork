#pragma once
#include "DX9_Device.h"
#include "DX9_Texture.h"
#include "DX9_Font.h"
#include "../System.h"
namespace DX9
{
	class DirectX
	{
	public:
		DX9::Direct3D direct3d;
		DX9::Font font;
		DirectX() {};
		~DirectX() {};
		bool Init(System& win);
		void Draw();
	};
}
