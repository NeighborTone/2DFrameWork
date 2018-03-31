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
		RECT          rect;						//�`��̈�
		std::vector<std::string> buf;		//�����o�b�t�@
	public:
		Font();
		~Font();

		bool Create(IDirect3DDevice9* pD3DDevice, std::string fontname, int FontHeight = 16);
		void Draw(DWORD Color, int x, int y, const TCHAR* Str, ...);		//printf�Ɠ����悤�Ȋ��o�ŕ`�悷��
	};
}