#include "Image.h"

using namespace DX9;
Image::Image()
{

}

Image::~Image()
{
	
}

void Image::Load(const char* path)
{
	tex.Create(path);
	sprite.Create();
}

void Image::Draw(float x, float y, DWORD color)
{
	sprite.SimpleDraw(tex.Gettexture(),D3DXVECTOR2(x,y),color);
}
void Image::Draw(D3DXVECTOR2 pos, DWORD color)
{
	sprite.SimpleDraw(tex.Gettexture(), D3DXVECTOR2(pos), color);
}

void Image::Draw(float x, float y, MyClass::Box src, MyClass::Box draw, DWORD color)
{
	sprite.Draw(x, y, draw.ToRECT(), src.ToRECT(), tex.Gettexture(), 0, D3DXVECTOR2(0, 0), color);
}

void Image::Draw(D3DXVECTOR2 pos, MyClass::Box src, MyClass::Box draw, DWORD color)
{
	sprite.Draw(pos, draw.ToRECT(), src.ToRECT(), tex.Gettexture(), 0, D3DXVECTOR2(0, 0), color);
}

void Image::DrawRota(float x, float y, float degree, MyClass::Box src, MyClass::Box draw, DWORD color)
{
	sprite.Draw(x, y, draw.ToRECT(), src.ToRECT(), tex.Gettexture(), degree, D3DXVECTOR2(draw.OffSet(x,y)), color);
}

void Image::DrawRota(D3DXVECTOR2 pos, float degree ,MyClass::Box src, MyClass::Box draw, DWORD color)
{
	sprite.Draw(pos, draw.ToRECT(), src.ToRECT(), tex.Gettexture(), degree, D3DXVECTOR2(draw.OffSet(pos)), color);
}