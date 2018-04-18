#pragma once
#include <d3dx9.h>
#include "DX9_Texture.h"
namespace DX9
{
	//このクラスはプリミティブの作成も内部で行う
	class Sprite
	{
	private:
		LPD3DXSPRITE pSprite;
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

		
		bool Create(LPDIRECT3DDEVICE9 device);
		//読み込んだテクスチャの全範囲を描画
		//1,テクスチャ 2,座標
		void SimpleDraw(LPDIRECT3DTEXTURE9 tex, float x, float y);
		void SimpleDraw(LPDIRECT3DTEXTURE9 tex, D3DXVECTOR2 pos);

		void Draw(const D3DXVECTOR2& pos,const RECT& draw_, const RECT& src_, const LPDIRECT3DTEXTURE9& texture_, const float degree_, const D3DXVECTOR2& center_, const D3DCOLOR& color_ = 0xffffffff)const;
	};
}