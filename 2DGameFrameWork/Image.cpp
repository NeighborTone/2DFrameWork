#include "Image.h"

using namespace DX9;
Image::Image()
{

}

Image::~Image()
{

}

void Image::Load(IDirect3DDevice9* p_d3dDevice,const char* path)
{
	tex.Create(p_d3dDevice, path);
	sprite.Create(p_d3dDevice);
}

void Image::Draw(float x, float y)
{
	sprite.SimpleDraw(tex.Gettexture(),D3DXVECTOR2(x,y));
}
void Image::Draw(D3DXVECTOR2 pos)
{
	sprite.SimpleDraw(tex.Gettexture(), D3DXVECTOR2(pos));
}

void Image::Draw(float x, float y, MyClass::Box src, MyClass::Box draw)
{
	sprite.Draw(x, y, draw.ToRECT(), src.ToRECT(), tex.Gettexture(), 0, D3DXVECTOR2(0, 0));
}

void Image::Draw(D3DXVECTOR2 pos, MyClass::Box src, MyClass::Box draw)
{
	sprite.Draw(pos, draw.ToRECT(), src.ToRECT(), tex.Gettexture(), 0, D3DXVECTOR2(0, 0));
}

void Image::DrawRota(float x, float y, float degree, MyClass::Box src, MyClass::Box draw)
{
	sprite.Draw(x, y, draw.ToRECT(), src.ToRECT(), tex.Gettexture(), degree, D3DXVECTOR2(draw.OffSet(x,y)));
}

void Image::DrawRota(D3DXVECTOR2 pos, float degree ,MyClass::Box src, MyClass::Box draw)
{
	sprite.Draw(pos, draw.ToRECT(), src.ToRECT(), tex.Gettexture(), degree, D3DXVECTOR2(draw.OffSet(pos)));
}