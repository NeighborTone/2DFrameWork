#pragma once
#include <d3dx9.h>
#include "DX9_Texture.h"
namespace DX9
{
	//このクラスはプリミティブの作成も内部で行う
	class Sprite
	{
	private:
		LPD3DXSPRITE p_sprite;
	public:
		//板ポリゴン用頂点情報
		struct Vertex
		{
			float x, y, z;	//3次元座標
			float rhw;		//2D変換済みフラグ	(ジオメトリパイプラインですでに変換されたとみなされる頂点座標)
			float u, v;		//UV座標
		};
		static const DWORD SPRITE_FVF = D3DFVF_XYZRHW | D3DFVF_TEX1;		//DirectXにどの頂点情報を使っているか教える(ここがおかしいと描画がおかしくなるので注意)
		
		//スプライトサイズ(拡大倍率)
		int width;
		int height;

		Sprite();
		~Sprite();

		//LPD3DXSPRITEを使う場合に呼ぶ	
		bool Create(LPDIRECT3DDEVICE9 device);
		//LPD3DXSPRITEを使わないで描画,読み込んだテクスチャの全範囲を画像の中心基準で描画
		//1,デバイス 2,テクスチャ(DX9::Texture) 3,回転角度（ラジアン）
		void DrawRota(IDirect3DDevice9* pDevice3D, DX9::Texture pTexture, float x, float y,float radian);
		void DrawRota(IDirect3DDevice9* pDevice3D, DX9::Texture pTexture, D3DXVECTOR2 pos,float radian);
		//LPD3DXSPRITEを使用して描画,読み込んだテクスチャの全範囲を描画
		//1,テクスチャ 2,座標
		void SimpleDraw(LPDIRECT3DTEXTURE9 tex, float x, float y);
		void SimpleDraw(LPDIRECT3DTEXTURE9 tex, D3DXVECTOR2 pos);
	};
}