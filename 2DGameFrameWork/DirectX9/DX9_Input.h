#pragma once
#define DIRECTINPUT_VERSION 0x0800
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
#include <dinput.h>

namespace DX9
{

	class Input
	{
	private:
		LPDIRECTINPUT8 pDI;
		LPDIRECTINPUTDEVICE8 pKey;
		unsigned char buf[256];
		unsigned char prebuf[256];
		static const int MAX_KEY = 61;
		int dikCode[MAX_KEY];
	public:
	
		Input();
		~Input();
		bool CreateInput(const HWND& hwnd);
		void UpDate();
		//������
		bool Press(const int key);
		//�����Ă���
		bool Push(const int key);
		//������Ă��Ȃ�
		bool Free(const int key);
		//�����ꂽ
		bool Pull(const int key);
		LPDIRECTINPUT8 GetpDI() const
		{
			return pDI;
		}
	};
	extern Input in;	//���������ɐ�������
}