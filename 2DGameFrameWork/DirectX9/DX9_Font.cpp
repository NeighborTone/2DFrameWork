#include "DX9_Font.h"
using namespace std;
using namespace DX9;

Font::Font()
{
	pFont = nullptr;
}

Font::~Font()
{
	if (pFont != nullptr)
	{
		pFont->Release();
	}
}

bool Font::Create(IDirect3DDevice9* pD3DDevice, std::string fontname, int FontHeight)
{
	return true;
}

void Font::Draw(DWORD Color, int x, int y, const TCHAR* Str, ...)
{

}