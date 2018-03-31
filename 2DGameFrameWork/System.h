#pragma once
#include <Windows.h>
#include <tchar.h>
#include <string>
//�E�B���h�E�֘A�̏������s��
class System
{
private:
	HWND handle;
	UINT SCREEN_W;
	UINT SCREEN_H;
public:
	System();
	~System();
	void SetWindowSize(UINT w = 640, UINT h = 480);				//��ʃT�C�Y�w��
	bool Create(std::string str , HINSTANCE& hInstance, int& nCmdShow);		//�E�B���h�E����
	UINT Width() { return SCREEN_W; }
	UINT Height() { return SCREEN_H; }
	HWND GetWindow();
};