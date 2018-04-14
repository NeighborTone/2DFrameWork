#include "DirectX.h"
#include "Define.hpp"
using namespace DX9;

bool DirectX::Init(System& win)
{
	if (direct3d.Create(win))
	{
		font.Create(direct3d.p_d3dDevice);
		tex.Create(direct3d.p_d3dDevice,"bg_title.png");
		sprite.pos = { 480,270 };



		return true;
	}
	return false;
}

void DirectX::Update()
{
	
}
void DirectX::Draw()
{
	//�`��J�n
	if (SUCCEEDED(direct3d.p_d3dDevice->BeginScene()))
	{
		//�w�i�N���A
		direct3d.p_d3dDevice->Clear(
			0,
			NULL,
			D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER,
			GetColor(100, 149, 237),
			1.0f,
			0
		);
		sprite.Draw(direct3d.p_d3dDevice, tex);
		font.Draw(GetColor(255,255,255),0,0,"AAAAAA\nBBBBBB");
		//�`��I��
		direct3d.p_d3dDevice->EndScene();
	}
	else
	{
		MessageBox(NULL, "�`��Ɏ��s���܂���", "Error", MB_OK);
	}
	//�`�攽�f
	direct3d.p_d3dDevice->Present(NULL,NULL, NULL,NULL);
}