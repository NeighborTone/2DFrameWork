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
	HFONT hFont = nullptr;	//�t�H���g�n���h��
	LOGFONT LogFont = {};	//�t�H���g�I�u�W�F�N�g

	//�f�t�H���g�t�H���g�擾
	hFont = ((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	//�f�t�H���g�t�H���g���擾
	GetObject(hFont, sizeof(LOGFONT), &LogFont);
	//DirectX�t�H���g�擾
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
		MessageBox(NULL, "�t�H���g�̐����Ɏ��s���܂���", "Error", MB_OK);
		pFont->Release();
		return false;
	}
	return true;
}

void Font::Draw(DWORD color, int x, int y, const string Str, ...)
{
	va_list args;		//�ς̈������g�p�\�ɂ���
	va_start(args, Str);
	unsigned int len = _vsctprintf(Str.c_str(), args) + 1;	//������+�k���������i�[
	if (buf.size() < len)
	{
		buf.resize(len);	//�����������I�Ƀ������m��
	}
	_vstprintf( &buf[0], Str.c_str(), args);	//�����𐮌`����
	SetRect(&rect, 0, 0, 0, 0);
	//�`��̈�T�C�Y�擾
	pFont->DrawText(
		NULL,
		&buf[0],
		-1,
		&rect,
		DT_LEFT | DT_CALCRECT,
		color);
	//�`��J�n
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