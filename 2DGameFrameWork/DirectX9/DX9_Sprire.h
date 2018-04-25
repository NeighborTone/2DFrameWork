#pragma once
#include <d3dx9.h>
#include "DX9_Device.h"
#include "DX9_Texture.h"
namespace DX9
{

	class Sprite
	{
	private:
		LPD3DXSPRITE pSprite;
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

		
		bool Create();
		//�ǂݍ��񂾃e�N�X�`���̑S�͈͂�`��
		//1,�e�N�X�`�� 2,���W
		void SimpleDraw(LPDIRECT3DTEXTURE9 tex, float x, float y,DWORD color = 0xffffffff) const;
		void SimpleDraw(LPDIRECT3DTEXTURE9 tex, D3DXVECTOR2 pos , DWORD color = 0xffffffff) const;
		//�ǂݍ��񂾃e�N�X�`������]�@�\�t���ŕ`��
		void Draw(const D3DXVECTOR2& pos,const RECT& draw_, const RECT& src_, const LPDIRECT3DTEXTURE9& texture_, const float degree_, const D3DXVECTOR2& center_, const D3DCOLOR& color_ = 0xffffffff)const;
		void Draw(const float& x, const float& y, const RECT& draw_, const RECT& src_, const LPDIRECT3DTEXTURE9& texture_, const float degree_, const D3DXVECTOR2& center_, const D3DCOLOR& color_ = 0xffffffff)const;
	};

	extern Sprite sprite;
}