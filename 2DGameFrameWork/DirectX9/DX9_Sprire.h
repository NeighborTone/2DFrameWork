#pragma once
#include <d3dx9.h>
#include "DX9_Texture.h"
namespace DX9
{
	//���̃N���X�̓v���~�e�B�u�̍쐬�������ōs��
	class Sprite
	{
	private:
		LPD3DXSPRITE p_sprite;
	public:
		//�|���S���p���_���
		struct Vertex
		{
			float x, y, z;	//3�������W
			float rhw;		//2D�ϊ��ς݃t���O	(�W�I���g���p�C�v���C���ł��łɕϊ����ꂽ�Ƃ݂Ȃ���钸�_���W)
			float u, v;		//UV���W
		};
		static const DWORD SPRITE_FVF = D3DFVF_XYZRHW | D3DFVF_TEX1;		//DirectX�ɂǂ̒��_�����g���Ă��邩������(���������������ƕ`�悪���������Ȃ�̂Œ���)
		
		//�X�v���C�g�T�C�Y(�g��{��)
		int width;
		int height;

		Sprite();
		~Sprite();

		//LPD3DXSPRITE���g���ꍇ�ɌĂ�	
		bool Create(LPDIRECT3DDEVICE9 device);
		//LPD3DXSPRITE���g��Ȃ��ŕ`��,�ǂݍ��񂾃e�N�X�`���̑S�͈͂��摜�̒��S��ŕ`��
		//1,�f�o�C�X 2,�e�N�X�`��(DX9::Texture) 3,��]�p�x�i���W�A���j
		void DrawRota(IDirect3DDevice9* pDevice3D, DX9::Texture pTexture, float x, float y,float radian);
		void DrawRota(IDirect3DDevice9* pDevice3D, DX9::Texture pTexture, D3DXVECTOR2 pos,float radian);
		//LPD3DXSPRITE���g�p���ĕ`��,�ǂݍ��񂾃e�N�X�`���̑S�͈͂�`��
		//1,�e�N�X�`�� 2,���W
		void SimpleDraw(LPDIRECT3DTEXTURE9 tex, float x, float y);
		void SimpleDraw(LPDIRECT3DTEXTURE9 tex, D3DXVECTOR2 pos);
	};
}