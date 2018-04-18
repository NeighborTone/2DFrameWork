#include "DX9_Sprire.h"

using namespace DX9;

Sprite::Sprite()
{
	p_sprite = nullptr;
	width = 0;
	height = 0;
}
Sprite::~Sprite()
{
	if (p_sprite != nullptr)
	{
		p_sprite->Release();
	}
}
bool Sprite::Create(LPDIRECT3DDEVICE9 device)
{
	if (FAILED(D3DXCreateSprite(device, &p_sprite)))
	{
		MessageBox(NULL, "�X�v���C�g�̐����Ɏ��s���܂���", "Error", MB_OK);
		return false;
	}
	return true;
}
void Sprite::DrawRota(IDirect3DDevice9* pDevice3D, DX9::Texture pTexture, float x, float y, float radian)
{
	//���_���Z�b�g�i�|���S�������p�Ȃ̂Œ��_4�j
	Vertex vtx[4] =
	{
		//x					   y					    z      rhw   u      v
		{ static_cast<float>(pTexture.GetInfo().Width / 2), -static_cast<float>(pTexture.GetInfo().Height / 2), 0.0f, 1.0f, 1.0f, 0.0f },
		{ static_cast<float>(pTexture.GetInfo().Width / 2),  static_cast<float>(pTexture.GetInfo().Height / 2), 0.0f, 1.0f, 1.0f, 1.0f },
		{ -static_cast<float>(pTexture.GetInfo().Width / 2),-static_cast<float>(pTexture.GetInfo().Height / 2), 0.0f, 1.0f, 0.0f, 0.0f },
		{ -static_cast<float>(pTexture.GetInfo().Width / 2), static_cast<float>(pTexture.GetInfo().Height / 2), 0.0f, 1.0f, 0.0f, 1.0f },
	};
	for (int i = 0; i < 4; ++i)
	{
		float rx = vtx[i].x * cosf(radian) - vtx[i].y * sinf(radian);
		float ry = vtx[i].x * sinf(radian) + vtx[i].y * cosf(radian);
		vtx[i].x = rx + x;
		vtx[i].y = ry + y;
	}
	//�e�N�X�`���Z�b�g
	pDevice3D->SetTexture(0, pTexture.Gettexture());
	//���_���Z�b�g
	pDevice3D->SetFVF(SPRITE_FVF);
	//�|���S���𐶐����e�N�X�`���[��\��t���ăX�v���C�g�`��
	pDevice3D->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vtx, sizeof(Vertex));
}
void Sprite::DrawRota(IDirect3DDevice9* pDevice3D, Texture pTexture, D3DXVECTOR2 pos,float radian)
{
	//���_���Z�b�g�i�|���S�������p�Ȃ̂Œ��_4�j
	Vertex vtx[4] =
	{
		//x					   y					    z      rhw   u      v
		{  static_cast<float>(pTexture.GetInfo().Width / 2), -static_cast<float>(pTexture.GetInfo().Height / 2), 0.0f, 1.0f, 1.0f, 0.0f },
		{  static_cast<float>(pTexture.GetInfo().Width / 2),  static_cast<float>(pTexture.GetInfo().Height / 2), 0.0f, 1.0f, 1.0f, 1.0f },
		{  -static_cast<float>(pTexture.GetInfo().Width / 2),-static_cast<float>(pTexture.GetInfo().Height / 2), 0.0f, 1.0f, 0.0f, 0.0f },
		{  -static_cast<float>(pTexture.GetInfo().Width / 2), static_cast<float>(pTexture.GetInfo().Height / 2), 0.0f, 1.0f, 0.0f, 1.0f },
	};
	for (int i = 0; i < 4; ++i)
	{
		float x = vtx[i].x * cosf(radian) - vtx[i].y * sinf(radian);
		float y = vtx[i].x * sinf(radian) + vtx[i].y * cosf(radian);
		vtx[i].x = x + pos.x;
		vtx[i].y = y + pos.y;
	}
	//�e�N�X�`���Z�b�g
	pDevice3D->SetTexture(0, pTexture.Gettexture());
	//���_���Z�b�g
	pDevice3D->SetFVF(SPRITE_FVF);
	//�|���S���𐶐����e�N�X�`���[��\��t���ăX�v���C�g�`��
	pDevice3D->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vtx, sizeof(Vertex));
}
void Sprite::SimpleDraw(LPDIRECT3DTEXTURE9 tex, float x, float y)
{
	D3DXVECTOR3 center(0, 0, 0);
	D3DXVECTOR3 pos3(x, y, 0);
	p_sprite->Begin(D3DXSPRITE_ALPHABLEND);	//(alpha�u�����h�̃t���O)
	p_sprite->Draw(
		tex,
		NULL,
		&center,   //���S�_
		&pos3,		  //���W
		0xFFFFFFFF
	);
	p_sprite->End();
}
void Sprite::SimpleDraw(LPDIRECT3DTEXTURE9 tex,D3DXVECTOR2 pos)
{
	D3DXVECTOR3 center(0,0,0);
	D3DXVECTOR3 pos3(pos.x, pos.y, 0);
	p_sprite->Begin(D3DXSPRITE_ALPHABLEND);	//(alpha�u�����h�̃t���O)
	p_sprite->Draw(
		tex,
		NULL,
		&center,   //���S�_
		&pos3,		  //���W
		0xFFFFFFFF
	);
	p_sprite->End();
}