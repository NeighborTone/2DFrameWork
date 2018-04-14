#pragma once
#include <d3dx9.h>
#include "DX9_Texture.h"
namespace DX9
{
	//このクラスはプリミティブの作成も内部で行う
	class Sprite
	{
	public:
		//板ポリゴン用頂点情報
		struct Vertex
		{
			float x, y, z;	//3次元座標
			float rhw;		//2D変換済みフラグ	(ジオメトリパイプラインですでに変換されたとみなされる頂点座標)
			float u, v;		//UV座標
		};
		static const DWORD SPRITE_FVF = D3DFVF_XYZRHW | D3DFVF_TEX1;		//DirectXにどの頂点情報を使っているか教える(ここがおかしいと描画がおかしくなるので注意)
		//スプライト位置
		D3DXVECTOR2 pos;
		//スプライトサイズ(拡大倍率)
		int width;
		int height;

		Sprite();
		~Sprite();

		void Draw(IDirect3DDevice9* pDevice3D, DX9::Texture pTexture);

	};
}