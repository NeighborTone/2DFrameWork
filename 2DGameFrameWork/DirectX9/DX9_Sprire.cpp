#include "DX9_Sprire.h"

namespace DX9
{

	Sprite::Sprite()
	{
		pSprite = nullptr;
		width = 0;
		height = 0;
	}
	Sprite::~Sprite()
	{
		if (pSprite != nullptr)
		{
			pSprite->Release();
		}
	}
	bool Sprite::Create()
	{
		if (FAILED(D3DXCreateSprite(direct3d.p_d3dDevice, &pSprite)))
		{
			MessageBox(NULL, "スプライトの生成に失敗しました", "Error", MB_OK);
			return false;
		}
		return true;
	}
	void Sprite::SimpleDraw(LPDIRECT3DTEXTURE9 tex, float x, float y, DWORD color) const
	{
		D3DXVECTOR3 center(0, 0, 0);
		D3DXVECTOR3 pos3(x, y, 0);
		pSprite->Begin(D3DXSPRITE_ALPHABLEND);	//(alphaブレンドのフラグ)
		pSprite->Draw(
			tex,
			NULL,
			NULL,   //中心点
			&pos3, //座標
			color
		);
		pSprite->End();
	}
	void Sprite::SimpleDraw(LPDIRECT3DTEXTURE9 tex, D3DXVECTOR2 pos, DWORD color) const
	{

		D3DXVECTOR3 pos3(pos.x, pos.y, 0);
		pSprite->Begin(D3DXSPRITE_ALPHABLEND);	//(alphaブレンドのフラグ)
		pSprite->Draw(
			tex,
			NULL,
			NULL,   //中心点
			&pos3, //座標
			color
		);
		pSprite->End();
	}

	void Sprite::Draw(const D3DXVECTOR2& pos, const RECT& draw, const RECT& src, const LPDIRECT3DTEXTURE9& texture_, const float degree, const D3DXVECTOR2& center_, const D3DCOLOR& color) const
	{
		this->pSprite->Begin(D3DXSPRITE_ALPHABLEND);
		//----------------------------------
		float  xs = (static_cast<float>(draw.right - draw.left)) / (static_cast<float>(src.right - src.left));
		float  ys = (static_cast<float>(draw.bottom - draw.top)) / (static_cast<float>(src.bottom - src.top));
		RECT rect = src;
		D3DXVECTOR3 pos3(static_cast<float>(draw.left), static_cast<float>(draw.top), 0.0f);
		D3DXVECTOR3  scale(xs, ys, 1.0f);
		D3DXVECTOR3  center(static_cast<float>(draw.left), static_cast<float>(draw.top), 0);
		D3DXVECTOR3 pos2(pos.x, pos.y, 0);
		D3DXMATRIX matS;
		D3DXMatrixScaling(&matS, scale.x, scale.y, scale.z);
		D3DXMATRIX matR;
		D3DXMatrixRotationZ(&matR, D3DXToRadian(degree));
		D3DXMATRIX matT;
		D3DXMatrixTranslation(&matT, pos3.x, pos3.y, pos3.z);
		D3DXMATRIX mat = matS * matR * matT;
		this->pSprite->SetTransform(&mat);
		this->pSprite->Draw(texture_, &rect, &center, &pos2, color);
		this->pSprite->End();
	}

	void Sprite::Draw(const float& x, const float& y, const RECT& draw, const RECT& src, const LPDIRECT3DTEXTURE9& texture_, const float degree, const D3DXVECTOR2& center_, const D3DCOLOR& color) const
	{
		this->pSprite->Begin(D3DXSPRITE_ALPHABLEND);
		//----------------------------------
		float  xs = (static_cast<float>(draw.right - draw.left)) / (static_cast<float>(src.right - src.left));
		float  ys = (static_cast<float>(draw.bottom - draw.top)) / (static_cast<float>(src.bottom - src.top));
		RECT rect = src;
		D3DXVECTOR3 pos3(static_cast<float>(draw.left), static_cast<float>(draw.top), 0.0f);
		D3DXVECTOR3 scale(xs, ys, 1.0f);
		D3DXVECTOR3 center(static_cast<float>(draw.left), static_cast<float>(draw.top), 0);
		D3DXVECTOR3 pos2(x, y, 0);
		D3DXMATRIX matS;
		D3DXMatrixScaling(&matS, scale.x, scale.y, scale.z);
		D3DXMATRIX matR;
		D3DXMatrixRotationZ(&matR, D3DXToRadian(degree));
		D3DXMATRIX matT;
		D3DXMatrixTranslation(&matT, pos3.x, pos3.y, pos3.z);
		D3DXMATRIX mat = matS * matR * matT;
		this->pSprite->SetTransform(&mat);
		this->pSprite->Draw(texture_, &rect, &center, &pos2, color);
		this->pSprite->End();
	}
}

