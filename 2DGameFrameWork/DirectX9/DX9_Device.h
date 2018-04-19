#pragma once
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#include <d3d9.h>
#include <d3dx9.h>
#include "../System.h"

namespace DX9
{
	//Direct3D�f�o�C�X�Ǘ���
	class Direct3D
	{
	public:
		IDirect3D9*			  p_d3d;
		IDirect3DDevice9* p_d3dDevice;
	
		Direct3D();
		~Direct3D();
		//�f�o�C�X����
		bool Create(System& win);
		IDirect3DDevice9* Get(){return p_d3dDevice;}
	};

	extern Direct3D direct3d;	//�f�o�C�X�͑��̋@�\���g�����ɂ��g���̂ŃO���[�o��(�����΂悢)
	
}