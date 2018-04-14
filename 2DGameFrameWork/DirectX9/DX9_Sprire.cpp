#include "DX9_Sprire.h"

using namespace DX9;

Sprite::Sprite()
{
	pos.x = 0;
	pos.y = 0;
	width = 0;
	height = 0;
}
Sprite::~Sprite()
{

}

//�Ƃ肠�����ǂݍ���ŕ\���i���摜�̐؂���Ȃ��j
//�摜�̒��S��ŕ`��
void Sprite::Draw(IDirect3DDevice9* pDevice3D, Texture pTexture)
{
	//���_���Z�b�g�i�|���S�������p�Ȃ̂Œ��_4�j
	Vertex vtx[4] =
	{
		//x					   y					    z      rhw   u      v
		{ pos.x + pTexture.GetInfo().Width / 2, pos.y - pTexture.GetInfo().Height / 2, 0.0f, 1.0f, 1.0f, 0.0f },
		{ pos.x + pTexture.GetInfo().Width / 2, pos.y + pTexture.GetInfo().Height / 2, 0.0f, 1.0f, 1.0f, 1.0f },
		{ pos.x - pTexture.GetInfo().Width / 2, pos.y - pTexture.GetInfo().Height / 2, 0.0f, 1.0f, 0.0f, 0.0f },
		{ pos.x - pTexture.GetInfo().Width / 2, pos.y + pTexture.GetInfo().Height / 2, 0.0f, 1.0f, 0.0f, 1.0f },
	};
	
	//�e�N�X�`���Z�b�g
	pDevice3D->SetTexture(0, pTexture.Gettexture());
	
	//���_���Z�b�g
	pDevice3D->SetFVF(SPRITE_FVF);
	//�|���S���𐶐����e�N�X�`���[��\��t���ăX�v���C�g�`��
	pDevice3D->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vtx, sizeof(Vertex));


}