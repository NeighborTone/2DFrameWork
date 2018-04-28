#pragma once
#include "DX9_Device.h"
#include <d3dx9.h>
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
		virtual ~Texture();
		bool Create(const std::string path);
		void Destroy();

		LPDIRECT3DTEXTURE9 Gettexture()
		{
			return p_tex;
		}
		//�ǂݍ��񂾉摜����Ԃ�
		D3DXIMAGE_INFO GetInfo() const	
		{
			return info;
		}
	};
	
}