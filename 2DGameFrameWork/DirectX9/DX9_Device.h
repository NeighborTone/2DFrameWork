#pragma once
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#include <d3d9.h>
#include <d3dx9.h>
#include "../System.h"

namespace DX9
{
	//Direct3Dデバイス管理部
	class Direct3D
	{
	public:
		IDirect3D9*			  p_d3d;
		IDirect3DDevice9* p_d3dDevice;
	
		Direct3D();
		~Direct3D();
		//デバイス生成
		bool Create(System& win);
		IDirect3DDevice9* Get(){return p_d3dDevice;}
	};

	extern Direct3D direct3d;	//デバイスは他の機能を使う時にも使うのでグローバル(一つあればよい)
	
}