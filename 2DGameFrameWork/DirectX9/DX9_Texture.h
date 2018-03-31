#pragma once
#include "DirectX.h"
#include <string>
namespace DX9
{
	class Texture
	{
	private:
		LPDIRECT3DTEXTURE9 p_tex;	
		D3DXIMAGE_INFO info;			//このオブジェクトに画像の情報が入る
	public:
		Texture();
		~Texture();
		bool Create(LPDIRECT3DDEVICE9 device,const std::string path);
	
	};
	
}