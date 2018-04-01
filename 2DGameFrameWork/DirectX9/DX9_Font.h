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
		RECT          rect;						//�`��̈�
		std::vector<char> buf;		//�����o�b�t�@
	public:
		Font();
		~Font();

		bool Create(IDirect3DDevice9* pD3DDevice, std::string fontname = "Times New Roman", int FontHeight = 16);
		void Draw(DWORD color, int x, int y, const std::string Str, ...);		//printf�Ɠ����悤�Ȋ��o�ŕ`�悷��
	};
}