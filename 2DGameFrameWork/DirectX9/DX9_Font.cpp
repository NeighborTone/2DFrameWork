#pragma warning (disable : 4996)
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
	HFONT hFont = nullptr;	//フォントハンドル
	LOGFONT LogFont = {};	//フォントオブジェクト

	//デフォルトフォント取得
	hFont = ((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	//デフォルトフォント情報取得
	GetObject(hFont, sizeof(LOGFONT), &LogFont);
	//DirectXフォント取得
	HRESULT hr;
	if (hr = FAILED(D3DXCreateFont(
		pD3DDevice,
		FontHeight,
		LogFont.lfWidth,
		LogFont.lfWeight,
		0,
		LogFont.lfItalic,
		LogFont.lfCharSet,
		LogFont.lfOutPrecision,
		LogFont.lfQuality,
		LogFont.lfPitchAndFamily,
		fontname.c_str(),
		&pFont))
		)
	{
		MessageBox(NULL, "フォントの生成に失敗しました", "Error", MB_OK);
		pFont->Release();
		return false;
	}
	return true;
}

void Font::Draw(DWORD color, int x, int y, const string Str, ...)
{
	va_list args;		//可変の引数を使用可能にする
	va_start(args, Str);
	unsigned int len = _vsctprintf(Str.c_str(), args) + 1;	//文字数+ヌル文字を格納
	if (buf.size() < len)
	{
		buf.resize(len);	//文字数分動的にメモリ確保
	}
	_vstprintf( &buf[0], Str.c_str(), args);	//文字を整形する
	SetRect(&rect, 0, 0, 0, 0);
	//描画領域サイズ取得
	pFont->DrawText(
		NULL,
		&buf[0],
		-1,
		&rect,
		DT_LEFT | DT_CALCRECT,
		color);
	//描画開始
	rect.left += x;
	rect.right += x;
	rect.top += y;
	rect.bottom += y;
	pFont->DrawText(
		NULL,
		&buf[0],
		-1,
		&rect,
		DT_LEFT,
		color
	);
}