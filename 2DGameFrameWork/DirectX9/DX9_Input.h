#pragma once
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

namespace DX9
{

	class Input
	{
	private:
		LPDIRECTINPUT8 pDI;
		LPDIRECTINPUTDEVICE pKey;
		unsigned char buf[256];
		unsigned char prebuf[256];
		static const int MAX_KEY = 28;
		int dikCode[MAX_KEY];
	public:
		Input();
		~Input();
		bool CreateInput(const HWND& hwnd);
		void UpDate();
		//押した
		bool Press(const int key);
		//押している
		bool Push(const int key);
		//押されていない
		bool Free(const int key);
		//離された
		bool Pull(const int key);
		LPDIRECTINPUT8 GetpDI() const
		{
			return pDI;
		}
	};
}