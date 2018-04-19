#pragma once
#include "DX9_Device.h"
#include "DX9_Texture.h"
#include "DX9_Font.h"
#include "DX9_Sprire.h"
#include "../System.h"
#include "../Image.h"
#include "../Game.h"
namespace DX9
{
	class DirectX
	{
	private:
		
	public: 
		Game game;
		DX9::Font font;
	
		DirectX() {};
		~DirectX() {};
		bool Init(System& win);
		void Update();
		void Draw();
	};
	
}
