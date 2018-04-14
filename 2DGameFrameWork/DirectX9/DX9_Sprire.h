#pragma once
#include <d3dx9.h>
#include "DX9_Texture.h"
namespace DX9
{
	//���̃N���X�̓v���~�e�B�u�̍쐬�������ōs��
	class Sprite
	{
	public:
		//�|���S���p���_���
		struct Vertex
		{
			float x, y, z;	//3�������W
			float rhw;		//2D�ϊ��ς݃t���O	(�W�I���g���p�C�v���C���ł��łɕϊ����ꂽ�Ƃ݂Ȃ���钸�_���W)
			float u, v;		//UV���W
		};
		static const DWORD SPRITE_FVF = D3DFVF_XYZRHW | D3DFVF_TEX1;		//DirectX�ɂǂ̒��_�����g���Ă��邩������(���������������ƕ`�悪���������Ȃ�̂Œ���)
		//�X�v���C�g�ʒu
		D3DXVECTOR2 pos;
		//�X�v���C�g�T�C�Y(�g��{��)
		int width;
		int height;

		Sprite();
		~Sprite();

		void Draw(IDirect3DDevice9* pDevice3D, DX9::Texture pTexture);

	};
}