#pragma once
#include "System.h"
#include "DirectX9/DirectX.h"
//メインループ処理を行う
class Mainloop final
{
private:
	MSG msg;
	System window;
	DX9::DirectX directx;

public:
	Mainloop() {};
	~Mainloop() {};
	bool Init(HINSTANCE hInstance, int nCmdShow);
	void Run();
};