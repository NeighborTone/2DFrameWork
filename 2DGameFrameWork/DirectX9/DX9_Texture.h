#pragma once
#include <d3dx9.h>
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
		bool Create(IDirect3DDevice9* device,const std::string path);

		LPDIRECT3DTEXTURE9 Gettexture()
		{
			return p_tex;
		}
		//読み込んだ画像情報を返す
		D3DXIMAGE_INFO GetInfo() const	
		{
			return info;
		}
	};
	
}