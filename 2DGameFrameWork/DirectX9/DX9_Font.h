#pragma once
#include "DirectX.h"
#include <vector>
#include <string>
namespace DX9
{
	class Font
	{
	private:
		ID3DXFont* pFont;
		RECT          rect;						//描画領域
		std::vector<std::string> buf;		//文字バッファ
	public:
		Font();
		~Font();

		bool Create(IDirect3DDevice9* pD3DDevice, std::string fontname, int FontHeight = 16);
		void Draw(DWORD Color, int x, int y, const TCHAR* Str, ...);		//printfと同じような感覚で描画する
	};
}