#pragma once
#include "MyClass.h"
#include "DirectX9\DX9_Sprire.h"
#include "DirectX9\DX9_Texture.h"

//2D‰æ‘œŠÇ—•”
class Image
{
private:
	DX9::Sprite sprite;
	DX9::Texture tex;
public:
	//(’†S“_(x,y)•`‰æ”ÍˆÍ(w,h))
	Image();
	~Image();
	void Load(const char* path);
	void Draw(float x, float y);
	void Draw(D3DXVECTOR2 pos);
	void Draw(float x, float y, MyClass::Box src, MyClass::Box draw);
	void Draw(D3DXVECTOR2 pos, MyClass::Box src, MyClass::Box draw);
	void DrawRota(float x, float y, float degree, MyClass::Box src, MyClass::Box draw);
	void DrawRota(D3DXVECTOR2 pos, float degree, MyClass::Box src, MyClass::Box draw);
};

