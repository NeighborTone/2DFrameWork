#include "MyClass.h"
using namespace MyClass;

Box::Box()
{
	x = y = w = h = 0;
}

Box::Box(float x, float y, float w, float h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h; 
}

Box::Box(const Box& me)
{
	x = me.x;
	y = me.y;
	w = me.w;
	h = me.h;
}

Box::~Box()
{

}

D3DXVECTOR2 Box::OffSet(D3DXVECTOR2& pos)
{
	this->x += pos.x;
	this->y += pos.y;

	return D3DXVECTOR2(x, y);
}
D3DXVECTOR2 Box::OffSet(float& x, float& y)
{
	this->x += x;
	this->y += y;

	return D3DXVECTOR2(this->x, this->y);
}
RECT Box::ToRECT()
{
	RECT rect = { x , y , w + x, h + y };	//‹éŒ`‚Í‚±‚ê‚Å‚Å‚«‚é
	return rect;
}

DWORD MyClass::GetColor(int r, int g, int b, int a)
{
	DWORD color = D3DCOLOR_ARGB(a, r, g, b);
	return color;
}
float MyClass::ToRadian(const float degree)
{
	const float m_pi = 3.141592654f;
	return degree * (m_pi) / 180.f;
}