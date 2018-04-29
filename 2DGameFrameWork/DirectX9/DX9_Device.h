#pragma once
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

#include <d3d9.h>
#include <d3dx9.h>
#include "../System.h"

namespace DX9
{
	//Direct3Dデバイス管理部。シングルトン
	class Direct3D final
	{
	private:
		Direct3D();
		static IDirect3D9* p_d3d;
		static IDirect3DDevice9* p_d3dDevice;
	public:
	
		~Direct3D();
		//デバイス生成
		bool Create(System& win);
		IDirect3DDevice9* GetDevice();
		static Direct3D* GetInst();
	};

}