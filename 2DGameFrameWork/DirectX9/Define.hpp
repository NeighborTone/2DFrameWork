#pragma once
#pragma comment(lib,"d3dx9.lib")
#include <d3dx9.h>
namespace DX9
{
	//’u‚«êŠ‚É¢‚éˆ—‚ÌW‚¢
	const float m_pi = 3.141592654f;
	DWORD GetColor(int r, int g, int b, int a = 255)
	{
		DWORD color = D3DCOLOR_ARGB(a, r, g, b);
		return color;
	}
	float Radian(const float degree)
	{
		return degree * (m_pi) / 180.f;
	}

}