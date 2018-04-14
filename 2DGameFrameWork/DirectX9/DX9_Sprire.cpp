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

//とりあえず読み込んで表示（元画像の切り取りなし）
//画像の中心基準で描画
void Sprite::Draw(IDirect3DDevice9* pDevice3D, Texture pTexture)
{
	//頂点情報セット（板ポリゴン生成用なので頂点4つ）
	Vertex vtx[4] =
	{
		//x					   y					    z      rhw   u      v
		{ pos.x + pTexture.GetInfo().Width / 2, pos.y - pTexture.GetInfo().Height / 2, 0.0f, 1.0f, 1.0f, 0.0f },
		{ pos.x + pTexture.GetInfo().Width / 2, pos.y + pTexture.GetInfo().Height / 2, 0.0f, 1.0f, 1.0f, 1.0f },
		{ pos.x - pTexture.GetInfo().Width / 2, pos.y - pTexture.GetInfo().Height / 2, 0.0f, 1.0f, 0.0f, 0.0f },
		{ pos.x - pTexture.GetInfo().Width / 2, pos.y + pTexture.GetInfo().Height / 2, 0.0f, 1.0f, 0.0f, 1.0f },
	};
	
	//テクスチャセット
	pDevice3D->SetTexture(0, pTexture.Gettexture());
	
	//頂点情報セット
	pDevice3D->SetFVF(SPRITE_FVF);
	//板ポリゴンを生成しテクスチャーを貼り付けてスプライト描画
	pDevice3D->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vtx, sizeof(Vertex));


}