#pragma once
#include "DirectX.h"
#include <string>
namespace DX9
{
	class Texture
	{
	private:
		LPDIRECT3DTEXTURE9 p_tex;	
		D3DXIMAGE_INFO info;			//���̃I�u�W�F�N�g�ɉ摜�̏�񂪓���
	public:
		Texture();
		~Texture();
		bool Create(LPDIRECT3DDEVICE9 device,const std::string path);
	
	};
	
}