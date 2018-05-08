#pragma once
#include "../SceneManager.h"
#include "DX9_Device.h"
#include "DX9_Texture.h"
#include "DX9_Font.h"
#include "DX9_Sprire.h"
#include "DX9_Input.h"
#include "../System.h"
#include "../Title.h"
#include "audio.h"
namespace DX9
{
	class DirectX final
	{
	private:
		
	public: 
		Direct3D* direct3D;
		SoundSystem* system;
		 DirectX() {};
		 DirectX(const DirectX&) = delete;
		 ~DirectX() {};
		bool Init(System& win);
		void Update();
		void Draw();
		void End();
	};
	
}
