#pragma once
#pragma comment(lib,"d3dx9.lib")
#include <d3dx9.h>
namespace DX9
{
	//置き場所に困る処理の集い
	DWORD GetColor(int r, int g, int b)
	{
		DWORD color = D3DCOLOR_ARGB(255, r, g, b);
		return color;
	}
}