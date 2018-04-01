#pragma once
#include <d3dx9.h>
#include <vector>
#include <string>
#include <tchar.h>
namespace DX9
{
	class Font
	{
	private:
		ID3DXFont* pFont;
		RECT          rect;						//描画領域
		std::vector<char> buf;		//文字バッファ
	public:
		Font();
		~Font();

		bool Create(IDirect3DDevice9* pD3DDevice, std::string fontname = "Times New Roman", int FontHeight = 16);
		void Draw(DWORD color, int x, int y, const std::string Str, ...);		//printfと同じような感覚で描画する
	};
}