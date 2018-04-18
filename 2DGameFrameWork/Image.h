#pragma once
#include "DirectX9\MyClass.h"
#include "DirectX9\DX9_Sprire.h"
#include "DirectX9\DX9_Texture.h"

class Image
{
private:
	DX9::Sprite sprite;
	DX9::Texture tex;
public:
	//(íÜêSì_(x,y)ï`âÊîÕàÕ(w,h))
	Image();
	~Image();
	void Load(IDirect3DDevice9* p_d3dDevice,const char* path);
	void Draw(float x, float y);
	void Draw(D3DXVECTOR2 pos);
	void Draw(float x, float y, MyClass::Box src, MyClass::Box draw);
	void Draw(D3DXVECTOR2 pos, MyClass::Box src, MyClass::Box draw);
	void DrawRota(float x, float y, float degree, MyClass::Box src, MyClass::Box draw);
	void DrawRota(D3DXVECTOR2 pos, float degree,MyClass::Box src, MyClass::Box draw);
};

