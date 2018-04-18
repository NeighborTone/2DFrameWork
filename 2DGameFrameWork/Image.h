#pragma once
#include "DirectX9\MyClass.h"
#include "DirectX9\DX9_Sprire.h"
#include "DirectX9\DX9_Texture.h"

class Image
{
private:
	DX9::Sprite sprite;
	DX9::Texture tex;
	MyClass::Box box;
	

public:

	Image();
	~Image();
	RECT GetSrc();
	RECT GetDraw();
	
	void Load(const char* path);
	void Draw(float x, float y ,RECT src,RECT draw);
	void DrawRota(float x, float y, RECT src, RECT draw);
};

