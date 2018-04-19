#pragma once
#pragma warning (disable : 4838)	//RECT�̂���
#pragma warning (disable : 4244)//
#pragma comment(lib,"d3dx9.lib")
#include <d3dx9.h>
//�u���ꏊ�ɍ��鏈���̏W��
namespace MyClass {
	typedef D3DXVECTOR2 Vec2;
	class Box
	{
	public:
		float x, y, w, h;
		Box();
		Box(float x, float y, float w, float h);
		Box(const Box& me);
		~Box();
		D3DXVECTOR2 OffSet(D3DXVECTOR2& pos);
		D3DXVECTOR2 OffSet(float& x, float& y);
		RECT ToRECT();
	};

	DWORD GetColor(int r, int g, int b, int a = 255);
	float ToRadian(const float degree);


}
