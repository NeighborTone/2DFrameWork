#pragma once
#include "MyClass.h"
#include "DirectX9\DX9_Sprire.h"
#include "DirectX9\DX9_Texture.h"

//2D�摜�Ǘ���
class Image
{
private:
	DX9::Sprite sprite;
	DX9::Texture tex;
public:
	//draw��(���S�_(x,y)�`��͈�(w,h))�Ŏw��
	Image();
	~Image();
	void Load(const char* path);
	void Draw(float x, float y, DWORD color = MyClass::GetColor(255,255,255));
	void Draw(D3DXVECTOR2 pos, DWORD color = MyClass::GetColor(255, 255, 255));
	void Draw(float x, float y, MyClass::Box src, MyClass::Box draw, DWORD color = MyClass::GetColor(255, 255, 255));
	void Draw(D3DXVECTOR2 pos, MyClass::Box src, MyClass::Box draw, DWORD color = MyClass::GetColor(255, 255, 255));
	void DrawRota(float x, float y, float degree, MyClass::Box src, MyClass::Box draw, DWORD color = MyClass::GetColor(255, 255, 255));
	void DrawRota(D3DXVECTOR2 pos, float degree, MyClass::Box src, MyClass::Box draw, DWORD color = MyClass::GetColor(255, 255, 255));

	//�摜�̉������
	void Destroy();
};

